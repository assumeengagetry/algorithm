#!/bin/bash
# Automated regression tests for graph path enumeration implementations.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
BIN_DIR="$SCRIPT_DIR/bin"

CXX=${CXX:-g++}
CXXFLAGS=${CXXFLAGS:--std=c++17 -O2 -Wall -Wextra}

mkdir -p "$BIN_DIR"

echo "[build] Compiling graph1.cpp"
"$CXX" $CXXFLAGS "$PROJECT_DIR/graph1.cpp" -o "$BIN_DIR/graph1_tests"
echo "[build] Compiling graph2.cpp"
"$CXX" $CXXFLAGS "$PROJECT_DIR/graph2.cpp" -o "$BIN_DIR/graph2_tests"

declare -A inputs
declare -A expected
declare -a cases=(
  "single_path"
  "two_paths"
  "no_path"
)

inputs[single_path]=$'4 3\n1 2\n2 3\n3 4'
expected[single_path]=$'1 2 3 4'

inputs[two_paths]=$'4 4\n1 2\n2 4\n1 3\n3 4'
expected[two_paths]=$'1 2 4 1 3 4'

inputs[no_path]=$'3 1\n1 2'
expected[no_path]=$'-1'

normalize() {
  printf '%s' "$1" | tr -s '[:space:]' ' ' | sed -e 's/^ //' -e 's/ $//'
}

run_case() {
  local executable=$1
  local program_name=$2
  local case_name=$3

  local raw_output
  raw_output=$("$executable" <<< "${inputs[$case_name]}")

  local got expected_output
  got=$(normalize "$raw_output")
  expected_output=$(normalize "${expected[$case_name]}")

  if [[ "$got" != "$expected_output" ]]; then
    echo "[$program_name] $case_name FAILED"
    echo "  expected: $expected_output"
    echo "  got:      $got"
    return 1
  fi

  echo "[$program_name] $case_name passed"
}

status=0

for executable in "$BIN_DIR/graph1_tests" "$BIN_DIR/graph2_tests"; do
  program_name=$(basename "$executable")
  for case_name in "${cases[@]}"; do
    if ! run_case "$executable" "$program_name" "$case_name"; then
      status=1
    fi
  done
done

if [[ $status -ne 0 ]]; then
  echo "One or more tests failed."
else
  echo "All graph path tests passed."
fi

exit $status
