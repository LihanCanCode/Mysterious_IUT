<div align="center">
  <h1>Mysterious IUT</h1>
  <h3>A campus mystery where every familiar landmark hides a forgotten truth.</h3>
  <p>A freshman arrives at IUT expecting orientation walks and welcome banners.</p>
  <p>Whispers about Professor Heigenberg's sealed laboratory drift through every corridor.</p>
  <p>Evidence boards, coded notes, and missing classmates tease a memory-altering experiment.</p>
  <p>Each clue you follow hints that the investigation may circle back to you.</p>
</div>

## Game Details
- Genre: Mystery / Psychological Thriller
- Perspective: Top-down exploration
- Platform: Windows PC
- Engine: raylib 5.0
- Language: C++17
- Status: In development (playable vertical slice)

## Story Premise
- **Setting:** A hand-crafted IUT campus reimagined as a trail of clues—from dorm courtyards to dim faculty offices lined with evidence boards.
- **Protagonist:** A first-semester student charting new territory.
- **Hook:** Rumors of Professor Heigenberg and Project Bhool Bhoolaiya refuse to fade, yet no one can remember who was involved—or why the campus feels subtly wrong amid flickering hallway lights and hushed conversations.

## Gameplay Overview
- Traverse the campus with smooth camera-following movement.
- Interview classmates, faculty, and staff through contextual dialogues reminiscent of field interrogations.
- Collect key items—case files, keycards, forgotten tools—to access locked facilities and advance story beats.
- Solve location-sensitive puzzles that tie rumors to physical evidence pinned across campus notice boards.
- Follow investigation states scripted inside [src/game.cpp](src/game.cpp).

## Key Features
- 🕵️‍♂️ Player-paced investigation across interconnected campus zones.
- 🧩 Environmental puzzles and item-based progression inspired by classic detective adventures.
- 🔍 Illustrated conversation panels styled as evidence visuals that surface each character’s perspective.
- 🔐 Area gating that rewards patient exploration.
- 🔊 Layered ambience—rain against windows, distant PA echoes—and overlays nudging the tension curve.

## Controls / How to Play
- Arrow Keys — Move
- Space / Enter — Advance dialogue and confirm prompts
- Escape — Close the game window (raylib default)

## Screenshots / GIFs
<p align="center">
  <img src="src/menu1.png" alt="Conversation panel with an NPC" width="720">
</p>
<p align="center">
  <img src="src/map.png" alt="Main menu with Play and Exit options" width="720">
</p>
<p align="center">
  <img src="src/end2.png" alt="Main menu with Play and Exit options" width="720">
</p>
<p align="center">
  <img src="src/end3.png" alt="Main menu with Play and Exit options" width="720">
</p>
<p align="center">
  <img src="src/end4.png" alt="Main menu with Play and Exit options" width="720">
</p>

## Installation / Run Instructions
**Play the bundled build**

```powershell
Set-Location "path\to\Project_Fall\src"
./game.exe
```

**Build from source**
1. Install raylib 5.0 for Windows (default path `C:\raylib`).
2. From the project root, build inside `src`:

```powershell
Set-Location "path\to\Project_Fall\src"
mingw32-make
```

3. Override the SDK path if raylib lives elsewhere:

```powershell
mingw32-make RAYLIB_PATH="X:/path/to/raylib"
```

4. Run `game.exe` from the same directory so assets resolve correctly.

## Tech Stack
- Core systems in [src/main.cpp](src/main.cpp) and [src/game.cpp](src/game.cpp)
- Collision and interaction helpers in [src/collision.cpp](src/collision.cpp)
- Art pipeline staged through layered PNG textures housed near the executable

## Inspirations
- Campus legends traded between IUT batches
- Narrative-driven mysteries such as Oxenfree and Night in the Woods
- Classic investigative adventures balancing exploration with character drama

## Roadmap
- Expand optional dialogue branches and side encounters
- Add an in-game investigation journal UI for tracking leads and persons of interest
- Introduce dynamic lighting cues, weather variants, and refined ambience mixes for late-night stakeouts
- Polish collision edges and NPC pathing near dense areas

## Known Issues
- Windows-only build; Linux/macOS ports under evaluation
- Occasional sprite overlap around doorway choke points
- Placeholder audio cues in late investigation sequences

### A Note from Lihan
Thank you for walking these halls—every whisper you follow brings us closer to remembering what the campus chose to forget.
