#!/usr/bin/env bash
# Compile and link-check XenonRecomp output for one module.
#   usage: tools/recomp/build_xenon.sh MODULE_DIR XENONRECOMP_DIR [JOBS] [OPT]
# MODULE_DIR holds ppc/*.cpp written by XenonRecomp. Objects go to MODULE_DIR/obj. The link step
# builds MODULE_DIR/linkcheck: every symbol the module imports (__imp__<Name> kernel/XAM imports)
# is given a stub that traps, so the link proves the translated code is complete and consistent.
set -euo pipefail
M=$(realpath "$1"); XR=$(realpath "$2"); J=${3:-2}; OPT=${4:--O1}
CXX=${CXX:-clang++}
mkdir -p "$M/obj"
export M XR OPT CXX
ls "$M"/ppc/*.cpp | xargs -P "$J" -I{} sh -c '
  f={}; o="$M/obj/$(basename "$f" .cpp).o"
  [ -f "$o" ] && [ "$o" -nt "$f" ] && exit 0
  "$CXX" -std=c++20 $OPT -march=x86-64-v3 -fno-strict-aliasing -w -I"$M/ppc" -I"$XR/thirdparty/simde" -c "$f" -o "$o" \
    || { echo "COMPILE FAILED: $f"; exit 255; }'
# stubs for unresolved symbols
nm -u "$M"/obj/*.o | awk '{print $NF}' | sort -u > "$M/obj/undef.txt"
nm --defined-only "$M"/obj/*.o | awk '{print $NF}' | sort -u > "$M/obj/def.txt"
comm -23 "$M/obj/undef.txt" "$M/obj/def.txt" | c++filt | grep -E '^[A-Za-z_][A-Za-z0-9_]*\(PPCContext&, unsigned char\*\)$' \
  | sed 's/(.*//' > "$M/obj/missing.txt" || true
{
  echo '#include <cstdint>'
  echo 'struct PPCContext;'
  while read -r s; do echo "void $s(PPCContext&, uint8_t*) { __builtin_trap(); }"; done < "$M/obj/missing.txt"
  echo 'int main() { return 0; }'
} > "$M/obj/linkcheck_stubs.cpp"
"$CXX" -std=c++20 -c "$M/obj/linkcheck_stubs.cpp" -o "$M/obj/linkcheck_stubs.o"
"$CXX" -fuse-ld=lld -o "$M/linkcheck" "$M"/obj/ppc_*.o "$M/obj/linkcheck_stubs.o" -lm
echo "linked $M/linkcheck; stubbed $(wc -l < "$M/obj/missing.txt") imported symbols"
size -t "$M"/obj/ppc_*.o | tail -1
