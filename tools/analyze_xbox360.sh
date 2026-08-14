#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
  echo "usage: $0 /absolute/path/to/extracted-game" >&2
  exit 2
fi

TS4_GAME_ROOT=$1
TS4_REPO_ROOT=$(cd "$(dirname "$0")/.." && pwd)
TS4_GHIDRA_PREFIX=$(brew --prefix ghidra)
TS4_JAVA_HOME=$(brew --prefix openjdk@21)/libexec/openjdk.jdk/Contents/Home
TS4_HEADLESS=$TS4_GHIDRA_PREFIX/libexec/support/analyzeHeadless
TS4_WORK_ROOT=${TS4_WORK_ROOT:-$TS4_REPO_ROOT/work}
TS4_PROJECT_ROOT=$TS4_WORK_ROOT/ghidra-project
TS4_SETTINGS=$TS4_WORK_ROOT/ghidra-settings
TS4_CACHE=$TS4_WORK_ROOT/ghidra-cache
TS4_REPORTS=$TS4_WORK_ROOT/analysis
TS4_SCRIPT_PATH=$TS4_REPO_ROOT/tools/ghidra

mkdir -p "$TS4_PROJECT_ROOT" "$TS4_SETTINGS" "$TS4_CACHE" "$TS4_REPORTS"

for TS4_MODULE in default.xex Loader_DLL.xex Swing_DLL.xex; do
  if [[ ! -f "$TS4_GAME_ROOT/$TS4_MODULE" ]]; then
    echo "missing module: $TS4_GAME_ROOT/$TS4_MODULE" >&2
    exit 1
  fi
  python3 "$TS4_REPO_ROOT/tools/xex_info.py" "$TS4_GAME_ROOT/$TS4_MODULE" > "$TS4_REPORTS/$TS4_MODULE.header.json"
  JAVA_HOME="$TS4_JAVA_HOME" \
    GHIDRA_HEADLESS_JAVA_OPTIONS="-Dapplication.settingsdir=$TS4_SETTINGS -Dapplication.cachedir=$TS4_CACHE" \
    "$TS4_HEADLESS" "$TS4_PROJECT_ROOT" topspin4 \
      -import "$TS4_GAME_ROOT/$TS4_MODULE" -overwrite -analysisTimeoutPerFile 600
  if [[ "$TS4_MODULE" == "Swing_DLL.xex" ]]; then
    JAVA_HOME="$TS4_JAVA_HOME" \
      GHIDRA_HEADLESS_JAVA_OPTIONS="-Dapplication.settingsdir=$TS4_SETTINGS -Dapplication.cachedir=$TS4_CACHE" \
      "$TS4_HEADLESS" "$TS4_PROJECT_ROOT" topspin4 \
        -process "$TS4_MODULE" -noanalysis -scriptPath "$TS4_SCRIPT_PATH" \
        -postScript FixXbox360SaveHelpers.java \
        -postScript ApplySymbolMap.java "$TS4_REPO_ROOT/config/symbols.csv"
  fi
  JAVA_HOME="$TS4_JAVA_HOME" \
    GHIDRA_HEADLESS_JAVA_OPTIONS="-Dapplication.settingsdir=$TS4_SETTINGS -Dapplication.cachedir=$TS4_CACHE" \
    "$TS4_HEADLESS" "$TS4_PROJECT_ROOT" topspin4 \
      -process "$TS4_MODULE" -noanalysis -scriptPath "$TS4_SCRIPT_PATH" \
      -postScript ExportProgramInventory.java "$TS4_REPORTS" \
      -postScript ExportProgramMap.java "$TS4_REPORTS"
done
