# Wii Sports Golf Battle Royale: Mod Plan

This document tracks the planned Golf Battle Royale fan mod for the US Wii Sports Revision 1 target. It is a design and implementation roadmap, not a claim that gameplay changes are already implemented.

## Goals

- Keep the original game and its assets separate from mod-created files.
- Develop and test in small, reversible stages.
- Target Dolphin first, then evaluate whether the same patch can be used through Riivolution on real Wii hardware.
- Use only a legally obtained game dump for local builds and testing.

## Intended game mode

1. **Pre-game area:** a bowling-themed lobby where players can wait and test controls.
2. **Golf match:** players compete on a golf course with a shrinking playable area or other elimination rules.
3. **Items:** optional pickups that create temporary advantages. Item effects must be implemented in code and tested individually.
4. **Victory condition:** the last player or team remaining wins.

These are design goals. They are not present in the game yet.

## Development stages

### Stage 1: Verify the development target
- Confirm the local dump is US Revision 1 (SHA-1: `8bb422971b88b5551a37de98db69557df7b46637`).
- Follow the repository's clean-room build instructions.
- Confirm a clean, unmodified build succeeds before changing gameplay.

### Stage 2: Map the existing golf flow
- Identify golf scene/state entry points and player/session handling in the decompilation.
- Document relevant functions and data structures before editing them.
- Avoid changing SDK or system-library code.

### Stage 3: Prototype one small gameplay change
- Choose a low-risk, visible change with a clear pass/fail test.
- Build and run it in Dolphin.
- Keep the prototype separate from the eventual item and lobby systems.

### Stage 4: Implement the match rules
- Add a match-state model for waiting, active play, eliminated players, and victory.
- Connect the state model to existing golf flow only after the relevant code paths are understood.
- Add and test one item at a time.

### Stage 5: Riivolution packaging
- Create an XML patch definition only after actual patchable files and their target paths are known.
- Verify the XML loads and that the patch points to real mod files.
- Test the package in Dolphin's Riivolution support before calling it functional.

## Current status

- [x] Created an isolated `golf-battle-royale` branch.
- [ ] Verify build environment and local game dump.
- [ ] Identify golf scene/state code.
- [ ] Implement and test a first gameplay prototype.
- [ ] Create a Riivolution package for actual implemented changes.

## Important technical limitation

OGWS is a decompilation project and does not include retail game assets or executable code. A Riivolution XML file by itself cannot add a battle royale mode. The mode requires implemented code/data changes, a successful build, and a tested patch package.

## Test checklist

For every change, record:
- What changed
- Build command and result
- Dolphin version and game revision
- Steps to reproduce
- Whether the original game still launches when the mod is disabled
