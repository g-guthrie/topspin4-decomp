// Export local-only maps used to identify reverse-engineering targets.
// @category TopSpin4

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.DataIterator;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Set;
import java.util.TreeSet;

public class ExportProgramMap extends GhidraScript {
    private static String csv(Object value) {
        String text = String.valueOf(value)
            .replace("\r", "\\r")
            .replace("\n", "\\n")
            .replace("\t", "\\t");
        return "\"" + text.replace("\"", "\"\"") + "\"";
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

        exportMemory(outputDirectory.resolve(programName + ".memory.csv"));
        exportSymbols(outputDirectory.resolve(programName + ".symbols.csv"));
        exportStrings(outputDirectory.resolve(programName + ".strings.csv"));
    }

    private void exportMemory(Path path) throws Exception {
        try (BufferedWriter writer = Files.newBufferedWriter(path, StandardCharsets.UTF_8)) {
            writer.write("name,start,end,size,read,write,execute,initialized\n");
            for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
                writer.write(csv(block.getName()));
                writer.write("," + csv(block.getStart()));
                writer.write("," + csv(block.getEnd()));
                writer.write("," + block.getSize());
                writer.write("," + block.isRead());
                writer.write("," + block.isWrite());
                writer.write("," + block.isExecute());
                writer.write("," + block.isInitialized());
                writer.write("\n");
            }
        }
        println("Wrote " + path);
    }

    private void exportSymbols(Path path) throws Exception {
        try (BufferedWriter writer = Files.newBufferedWriter(path, StandardCharsets.UTF_8)) {
            writer.write("address,name,namespace,type,source_type,is_primary,is_external\n");
            SymbolIterator symbols = currentProgram.getSymbolTable().getAllSymbols(true);
            while (symbols.hasNext() && !monitor.isCancelled()) {
                Symbol symbol = symbols.next();
                writer.write(csv(symbol.getAddress()));
                writer.write("," + csv(symbol.getName()));
                writer.write("," + csv(symbol.getParentNamespace().getName(true)));
                writer.write("," + csv(symbol.getSymbolType()));
                writer.write("," + csv(symbol.getSource()));
                writer.write("," + symbol.isPrimary());
                writer.write("," + symbol.isExternal());
                writer.write("\n");
            }
        }
        println("Wrote " + path);
    }

    private void exportStrings(Path path) throws Exception {
        try (BufferedWriter writer = Files.newBufferedWriter(path, StandardCharsets.UTF_8)) {
            writer.write("address,data_type,length,value,direct_reference_count,reference_addresses,referencing_functions,indirect_referencing_functions\n");
            DataIterator dataItems = currentProgram.getListing().getDefinedData(true);
            while (dataItems.hasNext() && !monitor.isCancelled()) {
                Data data = dataItems.next();
                String typeName = data.getDataType().getName().toLowerCase();
                if (!typeName.contains("string") && !typeName.contains("unicode")) {
                    continue;
                }

                int referenceCount = 0;
                Set<String> referenceAddresses = new TreeSet<>();
                Set<String> functions = new TreeSet<>();
                Set<String> indirectFunctions = new TreeSet<>();
                ReferenceIterator references = currentProgram.getReferenceManager()
                    .getReferencesTo(data.getMinAddress());
                while (references.hasNext()) {
                    Reference reference = references.next();
                    referenceCount++;
                    Address from = reference.getFromAddress();
                    referenceAddresses.add(from.toString());
                    Function function = currentProgram.getFunctionManager().getFunctionContaining(from);
                    if (function != null) {
                        functions.add(function.getEntryPoint().toString());
                    }
                    else {
                        ReferenceIterator indirectReferences = currentProgram.getReferenceManager()
                            .getReferencesTo(from);
                        while (indirectReferences.hasNext()) {
                            Address indirectFrom = indirectReferences.next().getFromAddress();
                            Function indirectFunction = currentProgram.getFunctionManager()
                                .getFunctionContaining(indirectFrom);
                            if (indirectFunction != null) {
                                indirectFunctions.add(indirectFunction.getEntryPoint().toString());
                            }
                        }
                    }
                }

                writer.write(csv(data.getMinAddress()));
                writer.write("," + csv(data.getDataType().getName()));
                writer.write("," + data.getLength());
                writer.write("," + csv(data.getValue()));
                writer.write("," + referenceCount);
                writer.write("," + csv(String.join(";", referenceAddresses)));
                writer.write("," + csv(String.join(";", functions)));
                writer.write("," + csv(String.join(";", indirectFunctions)));
                writer.write("\n");
            }
        }
        println("Wrote " + path);
    }
}
