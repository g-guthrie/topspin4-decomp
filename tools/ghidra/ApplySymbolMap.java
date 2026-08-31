// Apply reviewed function names from the repository's metadata-only symbol map.
// @category TopSpin4

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class ApplySymbolMap extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) {
            throw new IllegalArgumentException("expected one symbol-map path");
        }

        Path mapPath = Paths.get(args[0]).toAbsolutePath();
        List<String> lines = Files.readAllLines(mapPath, StandardCharsets.UTF_8);
        if (lines.isEmpty() ||
            !lines.get(0).equals("module,address,name,confidence,evidence")) {
            throw new IllegalArgumentException("unexpected symbol-map header: " + mapPath);
        }

        int applied = 0;
        for (int index = 1; index < lines.size(); index++) {
            String line = lines.get(index);
            if (line.isBlank()) {
                continue;
            }
            String[] fields = line.split(",", -1);
            if (fields.length != 5) {
                throw new IllegalArgumentException("invalid symbol-map row " + (index + 1));
            }
            if (!fields[0].equals(currentProgram.getName())) {
                continue;
            }

            Address address = currentProgram.getAddressFactory().getAddress(fields[1]);
            Function function = address == null ? null : getFunctionAt(address);
            if (function == null) {
                throw new IllegalStateException(
                    "no function at " + fields[1] + " for " + fields[2]
                );
            }
            function.setName(fields[2], SourceType.USER_DEFINED);
            applied++;
        }
        println("Applied " + applied + " reviewed function names from " + mapPath);
    }
}
