#!/usr/bin/env bash
# Fetch, patch and build the pinned recompiler toolchain into WORK_DIR.
#
#   tools/recomp/setup_toolchain.sh [WORK_DIR] [JOBS]
#
# WORK_DIR defaults to work/recomp. Nothing is written into the repository.
# Produces:
#   WORK_DIR/XenonRecomp/build/XenonRecomp/XenonRecomp   (patched, pinned ddd128b)
#   WORK_DIR/ref/rexglue-sdk/out/linux-amd64/            (rexglue CLI + runtime, pinned 546a082)
#
# Requirements: git, cmake >= 3.25, ninja, clang/clang++ (tested 18.1.3), lld,
# and for ReXGlue: libvulkan-dev libx11-dev libx11-xcb-dev libxcb1-dev
# libwayland-dev libgtk-3-dev (SDL3 + GTK file dialogs); at run time mesa-vulkan-drivers
# (lavapipe) and imagemagick (frame conversion). Set SKIP_REXGLUE=1 to
# build only XenonRecomp.
set -euo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
WORK="${1:-$HERE/../../work/recomp}"
JOBS="${2:-2}"
mkdir -p "$WORK"
WORK="$(cd "$WORK" && pwd)"

XR_URL=https://github.com/hedge-dev/XenonRecomp.git
XR_REV=ddd128bcca99fe8bfbb99bea583c972351fa6ace
RG_URL=https://github.com/rexglue/rexglue-sdk.git
RG_REV=546a082   # tag v0.10.1

apply_patches() {  # repo_dir patch_dir
  local dir="$1" pdir="$2" p
  for p in "$pdir"/*.patch; do
    if git -C "$dir" apply --check "$p" 2>/dev/null; then
      git -C "$dir" apply "$p"; echo "applied $(basename "$p")"
    elif git -C "$dir" apply --reverse --check "$p" 2>/dev/null; then
      echo "already applied $(basename "$p")"
    else
      echo "patch does not apply: $p" >&2; exit 1
    fi
  done
}

# --- XenonRecomp -----------------------------------------------------------
XR="$WORK/XenonRecomp"
if [ ! -d "$XR/.git" ]; then
  git clone "$XR_URL" "$XR"
fi
git -C "$XR" checkout -q "$XR_REV"
git -C "$XR" submodule update --init --recursive
apply_patches "$XR" "$HERE/patches/xenonrecomp"
cmake -S "$XR" -B "$XR/build" -G Ninja -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
ninja -C "$XR/build" -j"$JOBS" XenonRecomp
echo "XenonRecomp: $XR/build/XenonRecomp/XenonRecomp"

# --- ReXGlue SDK (codegen + runtime) ---------------------------------------
if [ "${SKIP_REXGLUE:-0}" = 1 ]; then exit 0; fi
RG="$WORK/ref/rexglue-sdk"
if [ ! -d "$RG/.git" ]; then
  mkdir -p "$WORK/ref"
  git clone "$RG_URL" "$RG"
fi
git -C "$RG" fetch -q --tags || true
git -C "$RG" checkout -q "$RG_REV"
git -C "$RG" submodule update --init --recursive
apply_patches "$RG" "$HERE/patches/rexglue"
cmake -S "$RG" -B "$WORK/rexbuild" -G Ninja -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_C_FLAGS=-march=x86-64-v2 -DCMAKE_CXX_FLAGS=-march=x86-64-v2 \
  -DCMAKE_INSTALL_PREFIX="$WORK/rexsdk" \
  -DREXGLUE_BUILD_TESTS=OFF -DREXGLUE_ENABLE_TRACY=OFF -DREXGLUE_USE_VULKAN=ON \
  -DSDL_X11_XSCRNSAVER=OFF -DSDL_WAYLAND=OFF -DSDL_PIPEWIRE=OFF -DSDL_JACK=OFF \
  -DSDL_SNDIO=OFF -DSDL_IBUS=OFF
ninja -C "$WORK/rexbuild" -j"$JOBS"
cmake --install "$WORK/rexbuild" > /dev/null   # SDK package for the game project: WORK/rexsdk
echo "ReXGlue: $RG/out/linux-amd64/rexglue (SDK installed in $WORK/rexsdk)"
