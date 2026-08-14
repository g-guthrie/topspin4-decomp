# Roadmap

## 0. Lock the target

1. Inventory the user-owned dump.
2. Record platform, title ID, region, game/update version, container hash, and executable hash.
3. Confirm the game boots in the matching emulator.

Exit condition: `config/target.json` contains one exact executable identity.

## 1. Build a reproducible binary map

1. Extract locally into ignored storage.
2. Parse executable sections, imports, exports, relocations, and embedded strings.
3. Import into Ghidra with the correct big-endian PowerPC language and image base.
4. Export a deterministic function and symbol inventory.

Exit condition: two clean analysis runs produce the same inventory.

## 2. Name systems before translating code

Prioritize the main loop, input, timing, player state, ball physics, animation, camera, audio, save data, and rendering boundaries. Keep evidence and confidence beside every name.

Exit condition: subsystem boundaries are reviewable and runtime traces support the important call relationships.

## 3. Reconstruct vertical slices

Start with deterministic, testable code such as math, state transitions, and serialization. Preserve original behavior first; refactoring comes later.

Exit condition: each reconstructed unit has a behavioral oracle or binary-match check appropriate to the chosen strategy.

## 4. Playable replacement

Replace platform services behind a narrow compatibility layer. Game assets remain user-supplied and loaded at runtime.

Exit condition: documented gameplay scenarios pass without distributing proprietary material.
