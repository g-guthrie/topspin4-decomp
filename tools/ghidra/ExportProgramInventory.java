// Export a metadata-only function inventory from the current Ghidra program.
// @category TopSpin4

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.mem.MemoryBlock;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class ExportProgramInventory extends GhidraScript {
    private static String csv(String value) {
        return "\"" + value.replace("\"", "\"\"") + "\"";
    }

    private static String json(String value) {
        return "\"" + value.replace("\\", "\\\\").replace("\"", "\\\"") + "\"";
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) {
            throw new IllegalArgumentException("expected one output-directory argument");
        }

        Path outputDirectory = Paths.get(args[0]).toAbsolutePath();
        Files.createDirectories(outputDirectory);
        String programName = currentProgram.getName();
        Path csvPath = outputDirectory.resolve(programName + ".functions.csv");
        Path jsonPath = outputDirectory.resolve(programName + ".summary.json");

        int functionCount = 0;
        int thunkCount = 0;
        int externalCount = 0;
        FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
        try (BufferedWriter writer = Files.newBufferedWriter(csvPath, StandardCharsets.UTF_8)) {
            writer.write("entry,name,namespace,source_type,is_thunk,is_external,body_bytes\n");
            while (functions.hasNext() && !monitor.isCancelled()) {
                Function function = functions.next();
                functionCount++;
                if (function.isThunk()) {
                    thunkCount++;
                }
                if (function.isExternal()) {
                    externalCount++;
                }
                writer.write(csv(function.getEntryPoint().toString()));
                writer.write("," + csv(function.getName()));
                writer.write("," + csv(function.getParentNamespace().getName(true)));
                writer.write("," + csv(function.getSymbol().getSource().toString()));
                writer.write("," + function.isThunk());
                writer.write("," + function.isExternal());
                writer.write("," + function.getBody().getNumAddresses());
                writer.write("\n");
            }
        }

        MemoryBlock[] blocks = currentProgram.getMemory().getBlocks();
        String summary = "{\n" +
            "  \"program\": " + json(programName) + ",\n" +
            "  \"executable_format\": " + json(currentProgram.getExecutableFormat()) + ",\n" +
            "  \"language\": " + json(currentProgram.getLanguageID().toString()) + ",\n" +
            "  \"compiler_spec\": " + json(currentProgram.getCompilerSpec().getCompilerSpecID().toString()) + ",\n" +
            "  \"memory_blocks\": " + blocks.length + ",\n" +
            "  \"functions\": " + functionCount + ",\n" +
            "  \"thunks\": " + thunkCount + ",\n" +
            "  \"external_functions\": " + externalCount + "\n" +
            "}\n";
        Files.writeString(jsonPath, summary, StandardCharsets.UTF_8);
        println("Wrote " + csvPath + " and " + jsonPath);
    }
}
