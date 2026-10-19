# Wii Sports Golf Battle Royale mod workspace

This workspace is for a rules-changing mod of the original Wii Sports Golf mode. The intended design is to make the existing Golf environment more open/free-roam and add Battle Royale match rules while preserving the game's original assets and visual identity.

## Non-negotiable design constraints

- Use existing Wii Sports assets, scenery, equipment, animations, and effects only.
- Do not introduce invented weapons, pickups, buildings, characters, or visual effects.
- The new content should be game rules and behavior, not a replacement art set.
- Keep changes reversible and separate from the clean OGWS source.
- Target Dolphin first, then assess Riivolution on real Wii hardware.

## Current implementation status

A standalone rules prototype exists in `source/GolfBattleRoyale.h` and `source/GolfBattleRoyale.cpp`. It supports up to four player slots, a lobby/active/finished state, player health, damage, eliminations, and a last-player-standing winner.

**This is not yet a playable Wii Sports mod.** The rules prototype is not connected to `RPGolScene`, the original player/session systems, the game's combat/collision code, camera, map boundaries, or build pipeline. Free-roam behavior, out-of-bounds handling, HUD, and real in-game damage are not implemented. It adds no custom items or game assets.

## Required next steps

1. Verify the exact US Rev 1 game dump locally and establish a clean build.
2. Trace the original Golf scene, player, camera, collision, and course-boundary code using the repository and matching local dump.
3. Determine whether the existing Golf map geometry can be explored beyond the normal course boundaries without adding new assets.
4. Identify existing Wii Sports actions/equipment that can be reused for player-versus-player interactions.
5. Connect the match rules to verified in-game events and existing player state.
6. Build and test each change in Dolphin before packaging a Riivolution patch.

Do not describe the mod as playable until the integrated build launches and its gameplay has been verified. A rules-only host test does not validate Wii compatibility.
