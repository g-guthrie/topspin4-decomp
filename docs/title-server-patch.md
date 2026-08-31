# Title-server patch path

## Confirmed call graph

These relationships come from the locked `Swing_DLL.xex`, not from filenames found online:

| Address | Reviewed name | Evidence |
| --- | --- | --- |
| `0x887B1468` | `RegisterOnlineScriptCommands` | Registers command strings and callbacks. |
| `0x88794FE8` | `Script_TitleServer_GetPatch` | Direct callback for the `TitleServer_GetPatch` string. |
| `0x889B39A0` | `CTitleServer_RequestPatch` | Called by the script callback with patch variant zero. |
| `0x889B5A30` | `CTitleServer_QueueRequest` | Adds or updates a request record with request kind 2. |
| `0x889C0298` | `CTitleServer_BuildProtocolMessage` | Request-type switch; patch operation `0x0e` creates protocol object `0x400`. |
| `0x889B1BB8` | `CTitleServer_ProcessPatchTransfer` | References `Media\TempPatch.bin` and the patch manager. |
| `0x887ECBD0` | `RegisterPatchServices` | Registers `CGameSaveAccess`, `CDLCCache`, and `CPatchManager`. |
| `0x887EF7C0` | `CPatchManager_DeserializePayload` | Reads a 20-byte header and variable-size patch data from a stream. |

The executable also names these resources:

- `Media\Patch\PatchesFAT.bin`
- `Media\Patch\Patch.arc`
- `Media\Patch\PatchDesc.bin`
- `Media\Patch\PatchData.arc`
- `Media\Patch\MyPatchData.arc`
- `Media\TempPatch.bin`
- `UPDATE:\CoreTech_Xenon.bin`
- `UPDATE:\Layoutall.bin`

The extracted retail disc contains `Layoutall.bin`, but it contains none of the named `Media\Patch` or `Media\TempPatch.bin` payloads. Therefore the disc is the unpatched data baseline; an online data patch or a cache/save captured from a console would be a separate artifact.

## Confidence boundary

Names copied directly from script/service registration are high confidence. Names assigned from behavior are marked medium confidence in `config/symbols.csv`. Structure layouts, protocol field meanings, archive format, and whether every server patch changed gameplay balance remain unresolved.

## Next recovery targets

1. Identify the 20-byte patch header fields and the protocol `0x400` response structure.
2. Determine where `PatchDesc.bin` and `PatchesFAT.bin` are parsed.
3. Search lawful console backups or title-specific caches for the named payloads, then hash and inspect them locally without publishing them.
4. Compare a recovered final data patch against the retail assets to enumerate actual behavior changes.
