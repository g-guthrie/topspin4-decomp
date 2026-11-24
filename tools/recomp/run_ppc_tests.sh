#!/usr/bin/env bash
# Instruction tests for the patched XenonRecomp (tools/recomp/patches).
#
# Assembles Xenia-format PowerPC tests (`#_ REGISTER_IN/OUT`, `#_ MEMORY_IN/OUT`), runs
# XenonRecomp's test mode on them, compiles the generated C++ and runs it. Sources:
#   - the ReXGlue SDK corpus (tests/ppc/asm, BSD-3, derived from Xenia's tests), read from the
#     local clone and never copied into this repository;
#   - our own tests in tools/recomp/tests/*.s for the forms RC2 added.
# The assembler is the binutils build that ships in the ReXGlue clone (tools/binutils, has -mvmx128).
#
# usage: tools/recomp/run_ppc_tests.sh XENONRECOMP_DIR REXGLUE_DIR WORK_DIR [pattern]
# Prints one line per failing check and a summary; exit status 1 if anything failed.
set -euo pipefail
XR=$(realpath "$1"); REX=$(realpath "$2"); W=$(realpath -m "$3"); PAT=${4:-*}
HERE=$(cd "$(dirname "$0")" && pwd)
AS="$REX/tools/binutils/powerpc-none-elf-as"
OBJDUMP="$REX/tools/binutils/powerpc-none-elf-objdump"
rm -rf "$W"; mkdir -p "$W/asm/bin" "$W/out"
cp "$REX"/tests/ppc/asm/$PAT.s "$W/asm/" 2>/dev/null || true
cp "$HERE"/tests/$PAT.s "$W/asm/" 2>/dev/null || true
# seq_* files exercise multi-function sequences that the XenonRecomp test mode does not model
rm -f "$W"/asm/seq_*.s
n=0
for s in "$W"/asm/*.s; do
  b=$(basename "$s" .s)
  "$AS" -a32 -be -mregnames -mpower7 -maltivec -mvsx -mvmx128 -R -o "$W/asm/bin/$b.o" "$s"
  "$OBJDUMP" -d "$W/asm/bin/$b.o" > "$W/asm/bin/$b.dis"
  n=$((n+1))
done
echo "assembled $n test files"
"$XR/build/XenonRecomp/XenonRecomp" "$W/asm/bin" "$W/out" > "$W/recomp.log" 2>&1 || true
grep -E "unimplemented|ERROR" "$W/recomp.log" || true
CXX=${CXX:-clang++}
objs=()
for c in "$W"/out/*.cpp; do
  o="${c%.cpp}.o"
  "$CXX" -std=c++20 -O1 -march=x86-64-v3 -fno-strict-aliasing -w -DFMT_HEADER_ONLY \
    -I"$XR/XenonUtils" -I"$XR/thirdparty/simde" -I"$XR/thirdparty/fmt/include" -c "$c" -o "$o"
  objs+=("$o")
done
"$CXX" -o "$W/ppc_tests" "${objs[@]}"
"$W/ppc_tests" > "$W/results.txt" 2>&1 || true
checks=$(grep -c "PPC_CHECK_VALUE" "$W/out/main.cpp" || true)
fails=$(wc -l < "$W/results.txt")
echo "checks: $checks, failing: $fails"
if [ "$fails" -ne 0 ]; then
  cut -d' ' -f1 "$W/results.txt" | sort | uniq -c | sort -rn | head -50
  exit 1
fi
