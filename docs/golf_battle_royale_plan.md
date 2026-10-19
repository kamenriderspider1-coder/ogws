# Wii Sports Golf Battle Royale: Original-Assets-Only Plan

## Goal

Modify the original US Wii Sports Golf mode into a Battle Royale-style free-roam experience while retaining the original game's assets and presentation. The mod may change gameplay rules, movement constraints, collision/boundary behavior, camera behavior, damage/elimination, and match flow. It must not add objects, weapons, scenery, characters, or effects that were not already present in Wii Sports.

## Target

- Game: Wii Sports USA Rev 1
- Expected dump SHA-1: `8bb422971b88b5551a37de98db69557df7b46637`
- First runtime target: Dolphin
- Potential later target: real Wii through Riivolution, after testing

## Design constraints

- Reuse the original Golf environment and existing Wii Sports assets.
- Free-roam means investigating and enabling movement through existing map areas, not constructing new map geometry.
- Reuse existing player actions, clubs, golf balls, animations, and effects where possible.
- Any Battle Royale-only rules must be code/state changes, not new pickups or invented equipment.
- Do not assume hidden areas are collision-ready or traversable. Inspect collision and boundary handling first.
- Keep the original game build and mod changes separate and reversible.

## Implementation sequence

### Stage 1: Validate the target and build
- Confirm the local dump is the supported USA Rev 1 target.
- Build the untouched project successfully before modifying gameplay.
- Record compiler/toolchain and Dolphin versions.

### Stage 2: Map the original Golf runtime
- Trace `RPGolScene` lifecycle, player manager, simulation manager, map/field manager, camera, ball, and collision paths.
- Locate the actual source and matching disassembly for boundaries, player control, collision, and scene transitions.
- Document verified entry points; do not guess based on class names alone.

### Stage 3: Free-roam feasibility
- Inspect original stage geometry and collision data.
- Determine which existing areas are reachable and what currently blocks players.
- Change only the boundary/collision/camera logic needed to explore existing geometry.
- Preserve existing geometry and assets; do not generate new terrain or props.
- Add safeguards against falling through the map or leaving the valid world.

### Stage 4: Battle Royale rules
- Connect a small match-state manager to actual game events.
- Use the game's existing player slots and equipment limits.
- Reuse original attack or swing animations and collision systems where feasible.
- Implement health/damage/elimination only after identifying a valid way to detect hits.
- Handle player falls or leaving the playable world using verified game state.
- Determine a last-player-standing winner and return safely to a results/state screen.

### Stage 5: In-game UI and feedback
- Prefer existing UI, fonts, sounds, and visual effects.
- Do not introduce new art or sound effects.
- If an interface element cannot be built from existing resources, keep it minimal and document the dependency.

### Stage 6: Build and test
- Build with the repository's supported toolchain and the matching legally obtained dump.
- Test in Dolphin after every small change.
- Verify normal Golf still launches when the mod is disabled.
- Create a Riivolution package only after actual replacement files exist and work.

## Current status

- [x] Isolated mod workspace and branch exist.
- [x] Standalone rules prototype supports up to four player slots, health, damage, elimination, and winner tracking.
- [ ] Verify matching local game dump and clean build.
- [ ] Identify actual Golf runtime integration points.
- [ ] Enable safe free-roam through existing map geometry.
- [ ] Connect combat/damage to original game actions and collision.
- [ ] Integrate match start, elimination, and victory into the game.
- [ ] Build and test in Dolphin.
- [ ] Package and test through Riivolution if feasible.

## Important limitation

The OGWS repository is a decompilation project and does not include the retail game's assets or complete executable code. The standalone rules prototype is not a playable mod. Actual game integration requires the matching game dump, verified runtime code paths, a supported toolchain, and testing.

## Test log template

For each change record:
- Change and files touched
- Build command and result
- Game revision and dump hash
- Dolphin version
- Reproduction steps
- Expected and observed behavior
- Whether the game still boots with the mod disabled
