#!/bin/sh
# Build ts4core as a freestanding WebAssembly module (no libc, no imports).
#   usage: port/core/build_wasm.sh            -> work/port/ts4core.wasm
#   env:   CLANG=/path/to/clang (needs the wasm32 target; Apple clang does not have it)
#          OUT=dir   (default <repo>/work/port)      OPT=-O2
# Needs: clang with --target=wasm32 and wasm-ld (Homebrew: `brew install llvm lld`).
set -eu
HERE=$(cd "$(dirname "$0")" && pwd)
REPO=$(cd "$HERE/../.." && pwd)
REF=$REPO/ref/gameplay
OUT=${OUT:-$REPO/work/port}
OPT=${OPT:--O2}

if [ -z "${CLANG:-}" ]; then
  for c in /opt/homebrew/opt/llvm/bin/clang /usr/local/opt/llvm/bin/clang "$(command -v clang || true)"; do
    if [ -n "$c" ] && [ -x "$c" ] && "$c" --print-targets 2>/dev/null | grep -q wasm32; then CLANG=$c; break; fi
  done
fi
if [ -z "${CLANG:-}" ]; then
  echo "build_wasm.sh: no clang with the wasm32 target found (Apple clang lacks it). Install LLVM (brew install llvm lld) or set CLANG=." >&2
  exit 2
fi
LLVM_BIN=$(dirname "$CLANG")
PATH="$LLVM_BIN:$PATH"
command -v wasm-ld >/dev/null 2>&1 || { echo "build_wasm.sh: wasm-ld not found (brew install lld)" >&2; exit 2; }

mkdir -p "$OUT"
"$CLANG" --target=wasm32 -nostdlib -ffreestanding -std=c99 $OPT -Wall -Wextra -Werror \
  -ffp-contract=off -fno-fast-math -fno-math-errno -mbulk-memory -fvisibility=hidden \
  -I"$HERE/shim" -I"$HERE/include" -I"$HERE/src" -I"$REPO/src/xbox360" -I"$REF" \
  "$HERE/src/softmath.c" "$HERE/src/data.c" "$HERE/src/ball.c" "$HERE/src/shot.c" "$HERE/src/sim.c" \
  "$HERE/src/wasm_rt.c" \
  "$REF/rules.c" "$REF/movement.c" "$REF/ai_driver.c" "$REF/stats.c" "$REF/swing_window.c" "$REF/clip_fit.c" \
  -Wl,--no-entry -Wl,--export-dynamic -Wl,-z,stack-size=262144 -Wl,--initial-memory=1048576 \
  -o "$OUT/ts4core.wasm"
echo "built $OUT/ts4core.wasm ($(wc -c < "$OUT/ts4core.wasm") bytes) with $("$CLANG" --version | head -n 1)"
