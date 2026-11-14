#!/usr/bin/env bash
# Run the recompiled game headlessly (no X server: SDL offscreen + lavapipe, SDL dummy audio).
#
#   TS4_ISO=/path/to/TopSpin4.iso tools/recomp/rexproj/headless.sh OUTDIR MAX_SECONDS [ts4 args]
#
# Optional env: TS4_INPUT_SCRIPT, TS4_SHOT_EVERY, TS4_WATCH, TS4_EXIT_AT_SWAP, REX_DRAW_EVERY
# (see src/ts4_app.h and src/ts4_script.h). TS4_WORK defaults to <repo>/work/recomp.
set -u
HERE="$(cd "$(dirname "$0")" && pwd)"
WORK="${TS4_WORK:-$HERE/../../../work/recomp}"
WORK="$(cd "$WORK" && pwd)"
OUT="$1"; SECS="$2"; shift 2
mkdir -p "$OUT"; OUT="$(cd "$OUT" && pwd)"
: "${TS4_ISO:?set TS4_ISO to the disc image}"
export LD_LIBRARY_PATH=$WORK/rexsdk/lib:$WORK/rc2/rex/build
export SDL_VIDEODRIVER=offscreen SDL_AUDIO_DRIVER=dummy
export XDG_RUNTIME_DIR="${XDG_RUNTIME_DIR:-$(mktemp -d)}"
export VK_ICD_FILENAMES=${VK_ICD_FILENAMES:-/usr/share/vulkan/icd.d/lvp_icd.json}
export TS4_ISO REX_IMPORT_TRACE_DIR="$OUT" TS4_SHOT_DIR="$OUT" TS4_FRAME_LOG="$OUT/frames.csv"
export REX_IMPORT_SNAPSHOT_ON=${REX_IMPORT_SNAPSHOT_ON:-__imp__XexLoadImage,__imp__VdSwap,__imp__XexUnloadImage,__imp__NetDll_accept,__imp__XamShowDeviceSelectorUI}
cd "$OUT"
timeout -s KILL "$SECS" "$WORK/rc2/rex/build/ts4" --game_data_root="$WORK/rc2/rex/game" \
  --log_file="$OUT/ts4.log" --gpu_plugin=xenos --async_shader_compilation=false "$@" \
  > "$OUT/stdout.log" 2>&1
echo "exit $?"
for f in "$OUT"/frame_*.ppm; do [ -e "$f" ] && convert "$f" "${f%.ppm}.png" && rm "$f"; done
exit 0
