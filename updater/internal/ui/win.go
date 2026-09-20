//go:build windows

package ui

import (
	"bytes"
	"image"
	"image/draw"
	"image/png"
	"syscall"
	"unsafe"

	"golang.org/x/sys/windows"
)

// Janela Win32 pura (user32/gdi32/comctl32), sem cgo: logo em cima, status,
// barra de progresso e os botoes Jogar/Fechar.
var (
	user32   = windows.NewLazySystemDLL("user32.dll")
	gdi32    = windows.NewLazySystemDLL("gdi32.dll")
	comctl32 = windows.NewLazySystemDLL("comctl32.dll")
	kernel32 = windows.NewLazySystemDLL("kernel32.dll")

	pRegisterClassExW     = user32.NewProc("RegisterClassExW")
	pCreateWindowExW      = user32.NewProc("CreateWindowExW")
	pDefWindowProcW       = user32.NewProc("DefWindowProcW")
	pGetMessageW          = user32.NewProc("GetMessageW")
	pTranslateMessage     = user32.NewProc("TranslateMessage")
	pDispatchMessageW     = user32.NewProc("DispatchMessageW")
	pPostQuitMessage      = user32.NewProc("PostQuitMessage")
	pPostMessageW         = user32.NewProc("PostMessageW")
	pSendMessageW         = user32.NewProc("SendMessageW")
	pShowWindow           = user32.NewProc("ShowWindow")
	pUpdateWindow         = user32.NewProc("UpdateWindow")
	pBeginPaint           = user32.NewProc("BeginPaint")
	pEndPaint             = user32.NewProc("EndPaint")
	pSetWindowTextW       = user32.NewProc("SetWindowTextW")
	pEnableWindow         = user32.NewProc("EnableWindow")
	pLoadCursorW          = user32.NewProc("LoadCursorW")
	pGetSystemMetrics     = user32.NewProc("GetSystemMetrics")
	pDestroyWindow        = user32.NewProc("DestroyWindow")
	pStretchDIBits        = gdi32.NewProc("StretchDIBits")
	pCreateSolidBrush     = gdi32.NewProc("CreateSolidBrush")
	pInitCommonControlsEx = comctl32.NewProc("InitCommonControlsEx")
	pGetModuleHandleW     = kernel32.NewProc("GetModuleHandleW")
	pMessageBoxW          = user32.NewProc("MessageBoxW")
)

const (
	wsOverlapped  = 0x00000000
	wsCaption     = 0x00C00000
	wsSysMenu     = 0x00080000
	wsMinimizeBox = 0x00020000
	wsVisible     = 0x10000000
	wsChild       = 0x40000000
	wsDisabled    = 0x08000000
	ssCenter      = 0x00000001
	bsPushButton  = 0x00000000
	wmDestroy     = 0x0002
	wmPaint       = 0x000F
	wmCommand     = 0x0111
	wmClose       = 0x0010
	wmUser        = 0x0400
	pbmSetRange32 = wmUser + 6
	pbmSetPos     = wmUser + 2
	msgStatus     = wmUser + 100
	msgProgress   = wmUser + 101
	msgReady      = wmUser + 102
	msgFailed     = wmUser + 103
	idPlay        = 1001
	idClose       = 1002
	iccProgress   = 0x00000020
	colorBg       = 0x00000000 // COLORREF preto
	winW, winH    = 560, 500
	logoH         = 300
)

type wndClassEx struct {
	Size, Style                     uint32
	WndProc, Instance, Icon, Cursor uintptr
	Background                      uintptr
	MenuName, ClassName             *uint16
	IconSm                          uintptr
}
type msg struct {
	Hwnd    uintptr
	Message uint32
	WParam  uintptr
	LParam  uintptr
	Time    uint32
	Pt      struct{ X, Y int32 }
}
type paintStruct struct {
	Hdc         uintptr
	Erase       int32
	RcPaint     struct{ L, T, R, B int32 }
	Restore     int32
	IncUpdate   int32
	RgbReserved [32]byte
}
type bitmapInfoHeader struct {
	Size                         uint32
	Width, Height                int32
	Planes, BitCount             uint16
	Compression, SizeImage       uint32
	XPelsPerMeter, YPelsPerMeter int32
	ClrUsed, ClrImportant        uint32
}
type initCommonControlsEx struct{ Size, ICC uint32 }

type win struct {
	hwnd, status, bar, play, closeBtn uintptr
	logo                              *image.RGBA
	play_                             bool
	texts                             chan string
	done                              chan bool
	instance                          uintptr
}

var current *win

func utf16(s string) *uint16 { p, _ := syscall.UTF16PtrFromString(s); return p }

func New(title string, logoPNG []byte) Window {
	img, err := png.Decode(bytes.NewReader(logoPNG))
	w := &win{texts: make(chan string, 8), done: make(chan bool, 1)}
	if err == nil {
		// Compoe o logo sobre preto e guarda em BGRA (formato do DIB).
		b := img.Bounds()
		rgba := image.NewRGBA(b)
		draw.Draw(rgba, b, image.Black, image.Point{}, draw.Src)
		draw.Draw(rgba, b, img, b.Min, draw.Over)
		for i := 0; i < len(rgba.Pix); i += 4 {
			rgba.Pix[i], rgba.Pix[i+2] = rgba.Pix[i+2], rgba.Pix[i]
		}
		w.logo = rgba
	}
	current = w
	w.create(title)
	return w
}

func (w *win) create(title string) {
	icc := initCommonControlsEx{Size: 8, ICC: iccProgress}
	pInitCommonControlsEx.Call(uintptr(unsafe.Pointer(&icc)))
	w.instance, _, _ = pGetModuleHandleW.Call(0)
	cursor, _, _ := pLoadCursorW.Call(0, 32512)
	brush, _, _ := pCreateSolidBrush.Call(colorBg)
	cls := wndClassEx{Size: uint32(unsafe.Sizeof(wndClassEx{})), WndProc: syscall.NewCallback(wndProc), Instance: w.instance, Cursor: cursor, Background: brush, ClassName: utf16("UnkBotUpdater")}
	if atom, _, err := pRegisterClassExW.Call(uintptr(unsafe.Pointer(&cls))); atom == 0 {
		fail("RegisterClassEx", err)
	}
	sw, _, _ := pGetSystemMetrics.Call(0)
	sh, _, _ := pGetSystemMetrics.Call(1)
	x := (int(sw) - winW) / 2
	y := (int(sh) - winH) / 2
	w.hwnd, _, _ = pCreateWindowExW.Call(0, uintptr(unsafe.Pointer(utf16("UnkBotUpdater"))), uintptr(unsafe.Pointer(utf16(title))),
		wsOverlapped|wsCaption|wsSysMenu|wsMinimizeBox|wsVisible, uintptr(x), uintptr(y), winW, winH, 0, 0, w.instance, 0)
	if w.hwnd == 0 {
		fail("CreateWindowEx", nil)
	}
	child := func(class, text string, style uintptr, x, y, cx, cy, id int) uintptr {
		h, _, _ := pCreateWindowExW.Call(0, uintptr(unsafe.Pointer(utf16(class))), uintptr(unsafe.Pointer(utf16(text))),
			wsChild|wsVisible|style, uintptr(x), uintptr(y), uintptr(cx), uintptr(cy), w.hwnd, uintptr(id), w.instance, 0)
		return h
	}
	w.status = child("STATIC", "Verificando atualizacoes...", ssCenter, 20, logoH+10, winW-40, 22, 0)
	w.bar = child("msctls_progress32", "", 0, 20, logoH+40, winW-40, 22, 0)
	pSendMessageW.Call(w.bar, pbmSetRange32, 0, 1000)
	w.play = child("BUTTON", "Jogar", bsPushButton|wsDisabled, winW/2-130, logoH+80, 120, 34, idPlay)
	w.closeBtn = child("BUTTON", "Fechar", bsPushButton, winW/2+10, logoH+80, 120, 34, idClose)
	pShowWindow.Call(w.hwnd, 5)
	pUpdateWindow.Call(w.hwnd)
}

// fail mostra o erro numa MessageBox: um updater que falha em silencio nao
// serve para quem esta do outro lado.
func fail(what string, err error) {
	text := "Falha ao abrir a janela (" + what + ")"
	if err != nil {
		text += ": " + err.Error()
	}
	pMessageBoxW.Call(0, uintptr(unsafe.Pointer(utf16(text))), uintptr(unsafe.Pointer(utf16("UnkBot Updater"))), 0x10)
	panic(text)
}

func wndProc(hwnd uintptr, m uint32, wp, lp uintptr) uintptr {
	w := current
	switch m {
	case wmPaint:
		var ps paintStruct
		hdc, _, _ := pBeginPaint.Call(hwnd, uintptr(unsafe.Pointer(&ps)))
		if w != nil && w.logo != nil {
			b := w.logo.Bounds()
			hdr := bitmapInfoHeader{Size: 40, Width: int32(b.Dx()), Height: -int32(b.Dy()), Planes: 1, BitCount: 32}
			dw := b.Dx()
			dh := b.Dy()
			if dh > logoH-20 {
				dw = dw * (logoH - 20) / dh
				dh = logoH - 20
			}
			pStretchDIBits.Call(hdc, uintptr((winW-dw)/2), 10, uintptr(dw), uintptr(dh), 0, 0, uintptr(b.Dx()), uintptr(b.Dy()),
				uintptr(unsafe.Pointer(&w.logo.Pix[0])), uintptr(unsafe.Pointer(&hdr)), 0, 0x00CC0020)
		}
		pEndPaint.Call(hwnd, uintptr(unsafe.Pointer(&ps)))
		return 0
	case msgStatus:
		if w != nil {
			select {
			case t := <-w.texts:
				pSetWindowTextW.Call(w.status, uintptr(unsafe.Pointer(utf16(t))))
			default:
			}
		}
		return 0
	case msgProgress:
		if w != nil {
			pSendMessageW.Call(w.bar, pbmSetPos, wp, 0)
		}
		return 0
	case msgReady:
		if w != nil {
			pEnableWindow.Call(w.play, 1)
		}
		return 0
	case msgFailed:
		if w != nil {
			pEnableWindow.Call(w.play, 0)
		}
		return 0
	case wmCommand:
		switch wp & 0xffff {
		case idPlay:
			if w != nil {
				w.play_ = true
			}
			pDestroyWindow.Call(hwnd)
		case idClose:
			pDestroyWindow.Call(hwnd)
		}
		return 0
	case wmClose:
		pDestroyWindow.Call(hwnd)
		return 0
	case wmDestroy:
		pPostQuitMessage.Call(0)
		return 0
	}
	r, _, _ := pDefWindowProcW.Call(hwnd, uintptr(m), wp, lp)
	return r
}

func (w *win) Status(text string) {
	w.texts <- text
	pPostMessageW.Call(w.hwnd, msgStatus, 0, 0)
}
func (w *win) Progress(done, total int64) {
	pos := uintptr(0)
	if total > 0 {
		pos = uintptr(done * 1000 / total)
	}
	pPostMessageW.Call(w.hwnd, msgProgress, pos, 0)
}
func (w *win) Ready()             { pPostMessageW.Call(w.hwnd, msgReady, 0, 0) }
func (w *win) Failed(text string) { w.Status(text); pPostMessageW.Call(w.hwnd, msgFailed, 0, 0) }

func (w *win) Run() bool {
	var m msg
	for {
		r, _, _ := pGetMessageW.Call(uintptr(unsafe.Pointer(&m)), 0, 0, 0)
		if int32(r) <= 0 {
			break
		}
		pTranslateMessage.Call(uintptr(unsafe.Pointer(&m)))
		pDispatchMessageW.Call(uintptr(unsafe.Pointer(&m)))
	}
	return w.play_
}
