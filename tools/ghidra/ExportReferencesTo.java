// Export direct references to selected addresses as deterministic CSV.
// @category TopSpin4

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class ExportReferencesTo extends GhidraScript {
    private static String csv(String value) {
        return "\"" + value.replace("\"", "\"\"") + "\"";
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            throw new IllegalArgumentException(
                "expected output CSV followed by one or more target addresses"
            );
        }

        Path output = Paths.get(args[0]).toAbsolutePath();
        Files.createDirectories(output.getParent());
        try (BufferedWriter writer = Files.newBufferedWriter(
            output,
            StandardCharsets.UTF_8
        )) {
            writer.write("target,from,reference_type,source_type,containing_function\n");
            for (int index = 1; index < args.length; index++) {
                Address target = currentProgram.getAddressFactory().getAddress(args[index]);
                if (target == null) {
                    throw new IllegalArgumentException("invalid address: " + args[index]);
                }

                ReferenceIterator references =
                    currentProgram.getReferenceManager().getReferencesTo(target);
                while (references.hasNext()) {
                    Reference reference = references.next();
                    Function function = currentProgram.getFunctionManager()
                        .getFunctionContaining(reference.getFromAddress());
                    String functionName = function == null ? "" : function.getName();
                    writer.write(String.join(",",
                        csv(target.toString()),
                        csv(reference.getFromAddress().toString()),
                        csv(reference.getReferenceType().getName()),
                        csv(reference.getSource().toString()),
                        csv(functionName)
                    ));
                    writer.write("\n");
                }
            }
        }
        println("Wrote " + output);
    }
}
