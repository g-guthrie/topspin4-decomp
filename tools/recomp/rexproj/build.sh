#!/usr/bin/env bash
# Build the ReXGlue game project (default.xex + Loader_DLL + Swing_DLL) under WORK/rc2/rex.
#
#   tools/recomp/rexproj/build.sh [JOBS]
#
# Needs: tools/recomp/setup_toolchain.sh done (XenonRecomp + ReXGlue in WORK, SDK installed
# into WORK/rexsdk by `cmake --install WORK/rexbuild`), the owner's files under orig/54540859/
# (disc/default.xex, disc/Loader_DLL.xex, disc/Loader_DLL.dll, Swing_DLL.xex, Swing_DLL.dll),
# and the default.xex basefile image at WORK/default/default.dll (only for its config).
# Generated code and objects stay in WORK (about 0.6 GB); nothing is written to the repo.
set -euo pipefail
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../../.." && pwd)"
WORK="${TS4_WORK:-$REPO/work/recomp}"
JOBS="${1:-3}"
RC2="$WORK/rc2"
PROJ="$RC2/rex"
REX="$WORK/ref/rexglue-sdk/out/linux-amd64/rexglue"
O="$REPO/orig/54540859"
cd "$REPO"

# 1. XenonRecomp-format boundaries + switch tables (also used for the stage-1 cross-check).
python3 tools/recomp_config.py config --image "$O/disc/Loader_DLL.dll" \
  --symbols config/54540859/loader/symbols.seed.txt --pdata --discover \
  --xex ../../../../orig/54540859/disc/Loader_DLL.xex --name Loader --out-dir "$RC2/loader" > /dev/null
python3 tools/recomp_config.py config --image "$O/Swing_DLL.dll" \
  --symbols config/54540859/symbols.txt --pdata --discover \
  --xex ../../../../orig/54540859/Swing_DLL.xex --name Swing --out-dir "$RC2/swing" \
  --setjmp 0x8856B7F0 --longjmp 0x88569D30 > /dev/null
python3 tools/recomp_config.py config --image "$WORK/default/default.dll" --pdata --discover \
  --xex ../../../../orig/54540859/disc/default.xex --name Default --out-dir "$RC2/default" > /dev/null

# 2. Project skeleton: our app sources, manifest, game root holding the three XEXs.
mkdir -p "$PROJ/src" "$PROJ/config" "$PROJ/game"
cp "$HERE/src/"*.h "$HERE/src/main.cpp" "$PROJ/src/"
cp "$HERE/CMakeLists.txt" "$HERE/ts4_manifest.toml" "$PROJ/"
for f in default.xex Loader_DLL.xex; do ln -f "$O/disc/$f" "$PROJ/game/$f" 2>/dev/null || cp "$O/disc/$f" "$PROJ/game/$f"; done
ln -f "$O/Swing_DLL.xex" "$PROJ/game/Swing_DLL.xex" 2>/dev/null || cp "$O/Swing_DLL.xex" "$PROJ/game/Swing_DLL.xex"

# 3. ReXGlue codegen hints. Pass 1: only the boundaries ReXGlue's own analysis gets wrong
#    (it fails validation without them). Loader setjmp/longjmp found by matching Swing's CRT
#    bodies (libjpeg's error path longjmps; without them the Press Start screen crashes).
T="python3 $REPO/tools/recomp/to_rexglue.py"
LOADER_FIX=83184210,83185C20,83187050,8317F628
SWING_FIX=883F1E88,883D8A08,883F1FA0,88660D10
# Entries that would split a function whose loop branches back across the split (no data
# references; reached only from inside their container).
LOADER_EXCL=830BC564,831711E4,8317121C,83171254,83171700,83171728,831762EC,83176324,8317635C,831799E4,8317C2C4,8317D6F8,8324FB50,831716F0,831711CC,831762D4,83171204,8317630C,83171718,8317123C,831799CC,8317C2AC,83176344
LJMP="--setjmp 0x8346A940 --longjmp 0x8346A510"
SJMP="--setjmp 0x8856B7F0 --longjmp 0x88569D30"
cd "$PROJ"
if [ ! -f "$PROJ/config/loader_register_v1.cpp" ]; then
  $T "$RC2/loader/Loader.toml" config/loader.toml --only $LOADER_FIX --no-switches $LJMP
  $T "$RC2/swing/Swing.toml" config/swing.toml --only $SWING_FIX --no-switches $SJMP
  $T "$RC2/default/Default.toml" config/default.toml --functions none --no-switches
  nice -n 5 "$REX" codegen ts4_manifest.toml > codegen_pass1.log 2>&1
  for m in default loader swing; do cp "generated/$m/ts4_register.cpp" "config/${m}_register_v1.cpp"; done
fi
# Pass 2: add every function start our boundaries know and ReXGlue's analysis missed
# (indirect-call targets such as Loader 0x833F9780), unsized so ReXGlue sizes them.
$T "$RC2/loader/Loader.toml" config/loader.toml --only $LOADER_FIX --no-switches \
  --missing-from config/loader_register_v1.cpp --exclude $LOADER_EXCL $LJMP
$T "$RC2/swing/Swing.toml" config/swing.toml --only $SWING_FIX --no-switches \
  --missing-from config/swing_register_v1.cpp $SJMP
$T "$RC2/default/Default.toml" config/default.toml --functions none --no-switches \
  --missing-from config/default_register_v1.cpp
nice -n 5 "$REX" codegen ts4_manifest.toml > codegen.log 2>&1
if grep -q "Unresolved" codegen.log; then echo "codegen reported unresolved branches" >&2; exit 1; fi
python3 "$REPO/tools/recomp/check_labels.py" generated/default generated/loader generated/swing
if grep -lq "REX_FATAL" generated/*/*.cpp; then echo "generated code contains REX_FATAL sites" >&2; exit 1; fi

# 4. Build. -O1 keeps the 260 MB of generated C++ compiling in ~25 min on 3 jobs.
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang \
  -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CXX_FLAGS=-march=x86-64-v2 \
  -DCMAKE_CXX_FLAGS_RELEASE="-O1 -DNDEBUG" -DCMAKE_PREFIX_PATH="$WORK/rexsdk" \
  -DREXGLUE_RECOMP_DEBUG_INFO=none > cmake.log
nice -n 5 ninja -C build -j"$JOBS"
# ReXGlue dlopen()s modules by bare target name on Linux, and loads the GPU plugin from the
# executable's folder.
ln -sf libts4_Loader_DLL.so build/ts4_Loader_DLL
ln -sf libts4_Swing_DLL.so build/ts4_Swing_DLL
ln -sf "$WORK/rexsdk/lib/librexgpu-xenos.so" build/librexgpu-xenos.so
echo "built $PROJ/build/ts4"
