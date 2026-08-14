// Export selected disassembly listings into ignored local reports.
// @category TopSpin4

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.Set;

public class ExportFunctionListing extends GhidraScript {
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

            String filename = currentProgram.getName() + "." + function.getEntryPoint() + ".asm";
            Path output = outputDirectory.resolve(filename);
            try (BufferedWriter writer = Files.newBufferedWriter(output, StandardCharsets.UTF_8)) {
                writer.write("; " + function.getName() + " at " + function.getEntryPoint() + "\n");
                InstructionIterator instructions = currentProgram.getListing()
                    .getInstructions(function.getBody(), true);
                while (instructions.hasNext()) {
                    Instruction instruction = instructions.next();
                    writer.write(instruction.getAddress() + "  ");
                    for (byte value : instruction.getBytes()) {
                        writer.write(String.format("%02x", value & 0xff));
                    }
                    writer.write("  " + instruction.toString() + "\n");
                }
            }
            println("Wrote " + output);
        }
    }
}
