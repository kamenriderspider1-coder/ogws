#!/bin/sh
set -eu
ROOT="$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)"
CXX="${CXX:-c++}"
OUT="${TMPDIR:-/tmp}/golf-battle-royale-test"
"$CXX" -std=c++98 -Wall -Wextra -pedantic \
  "$ROOT/source/GolfBattleRoyale.cpp" \
  "$ROOT/tests/test_match_manager.cpp" \
  -o "$OUT"
"$OUT"
echo "PASS: Golf Battle Royale rules tests"
