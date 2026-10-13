# Golf Battle Royale mod workspace

This directory holds experimental Golf Battle Royale code separately from the OGWS game sources.

## Current state

A standalone rules prototype exists in `source/GolfBattleRoyale.h` and `source/GolfBattleRoyale.cpp`. It currently tracks up to 16 player slots, lobby and active-match phases, eliminations, a last-player-standing winner, and simple item inventory slots.

Basic host-compiler tests are in `tests/test_match_manager.cpp`.

**This is not yet a playable Wii Sports mod.** The prototype is not connected to `RPGolScene`, the original Golf player/session systems, the game build, or Dolphin/Riivolution. Item types are only inventory identifiers; their in-game effects are not implemented. The bowling-themed lobby, course integration, zone rules, HUD, and Wii package are also not implemented.

## Development order

1. Identify the actual Golf scene/player/session integration points in the decompilation.
2. Connect the rules manager to the game using verified interfaces.
3. Build using the repository's supported toolchain and legally obtained matching game dump.
4. Test each change in Dolphin.
5. Create a Riivolution package only after there are real, tested replacement files.

Do not describe the mod as playable until the integrated build launches and its gameplay is verified.
