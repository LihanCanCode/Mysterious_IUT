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

## Design Intent
Mysterious IUT is built around the idea that places remember more than people do. Familiar campus spaces are treated as unreliable witnesses—quietly observing, subtly misleading, and occasionally revealing fragments of truth. The investigation is designed to feel personal, slow-burning, and reflective rather than urgent or combat-driven.

## Signature Mechanic
- Certain conversations and objects subtly change after major discoveries. Characters may recall events differently, and environmental details can shift, suggesting that the investigation itself is influencing reality.

## Gameplay & Core Loop
- Traverse the campus with smooth camera-following movement across interconnected zones.
- Explore each area to uncover rumors, objects, and environmental anomalies.
- Interview classmates, faculty, and staff through contextual dialogue sequences reminiscent of field interrogations.
- Cross-reference information gathered from conversations and surroundings to progress the investigation.
- Collect key items—case files, keycards, and forgotten tools—that unlock new locations and narrative states.
- Investigation flow and state transitions are scripted within [src/game.cpp](src/game.cpp).

## Investigation Systems & Features
- 🕵️‍♂️ Player-paced investigation that favors observation and deduction over explicit guidance.
- 🧩 Location-sensitive environmental puzzles tied to physical evidence boards and campus landmarks.
- 🔍 Illustrated dialogue panels presented as evidence visuals, reflecting each character’s perspective and reliability.
- 🔐 Area gating and revisitation mechanics that reward patience and attention to detail.
- 🧠 Dialogue choices subtly affect information clarity rather than branching outcomes.
- 🔊 Layered ambient sound design—rain against windows, distant PA echoes, and low-frequency overlays—to steadily build tension.

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
Thank you for walking these halls—every whisper you follow brings us closer to remembering what the campus chose to forget. Can you find the professor?
