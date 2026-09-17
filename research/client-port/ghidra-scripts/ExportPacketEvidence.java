// Targeted, read-only binary analysis. Arguments: output directory, hex VAs.
//@category L2Killer
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.nio.file.Files;
import java.nio.file.Path;

public class ExportPacketEvidence extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path output = Path.of(args[0]);
        Files.createDirectories(output);
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try {
            for (int i = 1; i < args.length; i++) {
                Address address = toAddr(args[i]);
                disassemble(address);
                Function function = getFunctionAt(address);
                if (function == null) function = createFunction(address, "packet_" + args[i]);
                if (function == null) throw new Exception("Cannot create function: " + address);
                DecompileResults result = decompiler.decompileFunction(function, 45, monitor);
                String text = result.decompileCompleted()
                    ? result.getDecompiledFunction().getC() : result.getErrorMessage();
                Files.writeString(output.resolve(args[i] + ".c"), text);
                println(args[i] + ": " + result.decompileCompleted());
            }
        } finally { decompiler.dispose(); }
    }
}
