# Golf Battle Royale mod workspace

This directory is reserved for mod-specific source, configuration, and packaging files. Keep experimental changes here where practical, and document any required edits to OGWS source files.

## Current state

This is a workspace scaffold only. No gameplay code or Riivolution patch is implemented yet.

## Planned contents

- `source/`: new mod logic once the golf scene and player/session code have been identified.
- `riivolution/`: the patch XML and any supported replacement files after real patch targets exist.
- `tests/`: repeatable build and Dolphin test notes.

Do not add a Riivolution patch that points to nonexistent files. First identify a small, real gameplay change, implement it, and confirm the built result works in Dolphin.
