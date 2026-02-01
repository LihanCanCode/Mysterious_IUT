# Mysterious IUT
Narrative-driven top-down adventure set on the IUT campus, built with C++ and raylib. You play as a new freshman thrilled to explore the grounds, only to stumble upon cryptic clues about a forgotten experiment and a missing professor.

## Game Preview
<p align="center">
	<img src="src/conversation1.png" alt="In-game conversation" width="720">
</p>
<p align="center">
	<img src="src/menu1.png" alt="Main menu" width="720">
</p>

## Entry Points
- [src/main.cpp](src/main.cpp) boots the application and instantiates the `Game` class.
- [src/game.cpp](src/game.cpp) orchestrates player control, collision resolution, texture loading, and scripted event flow.

## Story & Gameplay
**Narrative**
- The campus whispers about Professor Heigenberg and a clandestine experiment dubbed "Project Bhool Bhoolaiya". Designed to alter human memory, the trial backfired, erasing the assistant from everyone's mind and trapping the professor in a time loop. The freshman learns that the professor never vanished—he is reliving the loop as the freshman himself, searching for a way to break free.

**Setting**
- Hand-drawn map of the IUT campus with landmarks such as the lake, CDS, library, hospital, auditorium, and dormitory halls. The player spawns near the dorm area, retracing steps that feel eerily familiar.

**Goal**
- Progress through a sequence of interactions: meet Bhai, Apu, Professor, Gardener, Hacker, and Imam; gather key items (key, book, USB); unlock restricted areas like the hospital, library, classrooms, and the maze; trigger cinematic sequences that unravel the fate of Heigenberg and reveal the looping identity twist.

**Mechanics**
- Move with arrow keys while collision checks prevent walking through buildings or props. Rectangle triggers in [src/game.cpp](src/game.cpp) toggle state flags (such as `insideLibrary`, `showConversation`, `mazeActive`) and activate dialog panels to drive the narrative.

**Visuals & UI**
- Conversations appear through illustrated panels (`conversation*.png`, `bhai_convo*.png`, etc.). Health indicators, path overlays, mystery clues, and ending slides render as textured quads anchored to the camera.

## Flow From Code
- `Game::Initialize()` loads textures, configures the camera, and primes dialogue/state flags.
- `Game::Run()` loops `Update()` and `Draw()`.
	- `Update()` handles input, camera movement, collision checks against building geometry, and state transitions when the player overlaps trigger rectangles.
	- `Draw()` renders the base map, player, NPCs, prompts, and whichever conversation or ending textures match the current progression flags.
- Completing the required interactions flips `Final = true`, advancing to the ending slides.

## Controls
- Arrow keys: Move the protagonist
- Space or Enter: Advance conversation panels (when shown)
- Escape: Quit (raylib default window close)

## Run The Game (Prebuilt Executable)
Launch the ready-to-play binary from the `src` directory so relative asset paths resolve correctly:

```powershell
Set-Location "path\to\Project_Fall\src"
./game.exe
```

## Build From Source
1. Install the official raylib 5.0 Windows package (defaults to `C:\raylib`).
2. Open PowerShell in the project root and build from `src`:

```powershell
Set-Location "path\to\Project_Fall\src"
mingw32-make
```

3. The Makefile links against `C:\raylib\raylib` by default. Override with `mingw32-make RAYLIB_PATH="X:/path/to/raylib"` if your SDK differs.
4. Run the freshly built executable using the steps from the previous section.

## Assets
- `Pics/` and `src/Pics/` (ignored by Git) store the original artwork sources.
- Production textures live beside the executable under `src/` so the game can load them without extra configuration.

## Credits
- Game design, story, and art: Lihan,Nafiz and Shadab
- Engine: raylib 5.0 by Ramon Santamaria and contributors

Enjoy uncovering the mysteries of IUT!
