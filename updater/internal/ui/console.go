//go:build !windows

package ui

import "fmt"

type console struct{ play chan bool }

func New(title string, logoPNG []byte) Window { return &console{play: make(chan bool, 1)} }
func (c *console) Status(text string)         { fmt.Println(text) }
func (c *console) Progress(done, total int64) {
	if total > 0 {
		fmt.Printf("\r%3d%%", done*100/total)
	}
}
func (c *console) Ready()             { fmt.Println("\npronto"); c.play <- true }
func (c *console) Failed(text string) { fmt.Println("\nerro:", text); c.play <- false }
func (c *console) Run() bool          { return <-c.play }
