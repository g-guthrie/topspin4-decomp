// Decompile selected functions by address into ignored local reports.
// @category TopSpin4

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.Set;

public class DecompileFunctions extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            throw new IllegalArgumentException(
                "expected output directory followed by one or more addresses"
            );
        }

        Path outputDirectory = Paths.get(args[0]).toAbsolutePath();
        Files.createDirectories(outputDirectory);
        Set<Address> completed = new HashSet<>();

        DecompInterface decompiler = new DecompInterface();
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(true);
        decompiler.setSimplificationStyle("decompile");
        if (!decompiler.openProgram(currentProgram)) {
            throw new IllegalStateException("decompiler setup failed: " + decompiler.getLastMessage());
        }

        try {
            for (int index = 1; index < args.length && !monitor.isCancelled(); index++) {
                Address requested = currentProgram.getAddressFactory().getAddress(args[index]);
                if (requested == null) {
                    printerr("Invalid address: " + args[index]);
                    continue;
                }
                Function function = currentProgram.getFunctionManager().getFunctionContaining(requested);
                if (function == null) {
                    printerr("No function contains: " + requested);
                    continue;
                }
                if (!completed.add(function.getEntryPoint())) {
                    continue;
                }

                DecompileResults result = decompiler.decompileFunction(function, 120, monitor);
                String body;
                if (!result.decompileCompleted() || result.getDecompiledFunction() == null) {
                    body = "/* Decompilation failed: " + result.getErrorMessage() + " */\n";
                }
                else {
                    body = result.getDecompiledFunction().getC();
                }

                String filename = currentProgram.getName() + "." +
                    function.getEntryPoint() + ".c";
                Path output = outputDirectory.resolve(filename);
                Files.writeString(output, body, StandardCharsets.UTF_8);
                println("Wrote " + output);
            }
        }
        finally {
            decompiler.dispose();
        }
    }
}
