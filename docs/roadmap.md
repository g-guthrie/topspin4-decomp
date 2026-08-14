# Roadmap

## 0. Lock the target identity — complete

1. Inventory the user-owned dump.
2. Record platform, title ID, region, game/update version, container hash, and executable hash.
3. Confirm the game boots in the matching emulator. **Pending: runtime validation is a separate gate.**

Exit condition met: `config/target.json` identifies Xbox 360 title `54540859`, media `60819732`, version `0.0.0.3`, and the executable hash.

## 1. Build a reproducible binary map

1. Extract locally into ignored storage. **Complete.**
2. Parse executable sections, imports, exports, relocations, and embedded strings. **In progress.**
3. Import into Ghidra with the correct big-endian PowerPC language and image base. **Complete.**
4. Export a deterministic function and symbol inventory. **Complete.**

Exit condition: two clean analysis runs produce the same inventory.

## 2. Name systems before translating code

Prioritize the main loop, input, timing, player state, ball physics, animation, camera, audio, save data, and rendering boundaries. Keep evidence and confidence beside every name.

Exit condition: subsystem boundaries are reviewable and runtime traces support the important call relationships.

## 3. Reconstruct vertical slices

Start with deterministic, testable code such as math, state transitions, and serialization. Preserve original behavior first; refactoring comes later.

Exit condition: each reconstructed unit has a behavioral oracle or binary-match check appropriate to the chosen strategy.

### 3a. Establish matching-build infrastructure

1. Make Jeff split each target module without a crash or unresolved function overlap. **Swing complete; Loader pending.**
2. Recover real translation-unit boundaries and commit reviewed `splits.txt` and `symbols.txt` files. **Nine exact Swing measurement units are committed; original translation-unit boundaries remain provisional.**
3. Confirm Xbox 360 MSVC `16.0.10224.0` flags with small code-generation probes. **`/O2 /Oi` verified for eleven functions.**
4. Generate an objdiff configuration and classify every source unit as missing, non-matching, equivalent, or matching. **Initial full-Swing report complete.**
5. Keep semantic and matching counters separate. **Complete.**

Exit condition met: nine source measurement units containing eleven functions are compiled with the target toolchain and have reproducible objdiff reports against their original COFFs. These units are not presented as proven original source-file boundaries.

## 4. Playable replacement

Replace platform services behind a narrow compatibility layer. Game assets remain user-supplied and loaded at runtime.

Exit condition: documented gameplay scenarios pass without distributing proprietary material.
