# Mysterious IUT

Narrative-driven top-down adventure set on the IUT campus, built with C++ and [raylib](https://www.raylib.com/). You explore familiar locations, interact with classmates and faculty, and uncover a mystery by collecting key items and solving lightweight puzzles.

The entry point lives in [src/main.cpp](src/main.cpp) and simply instantiates the `Game` class. All game logic resides in [src/game.cpp](src/game.cpp), which wires together the player controller, collision system, texture loading, and event sequences.

## Story & Gameplay

- **Setting** – A hand-drawn map of the IUT campus with buildings such as the lake, CDS, library, hospital, auditorium, and halls. The player spawns near the dorm area.
- **Goal** – Progress through a chain of interactions: talk to NPCs (Bhai, Apu, Professor, Gardener, Hacker, Imam), gather key items (key, book, USB), unlock restricted areas (hospital, library, classrooms, maze), and trigger cinematic sequences that culminate in the final reveal.
- **Mechanics** – Movement uses arrow keys; collisions prevent walking through buildings or props. Rectangle triggers inside `game.cpp` toggle state flags (e.g., `insideLibrary`, `showConversation`, or `mazeActive`) and display dialog PNGs to drive the storyline.
- **Visuals & UI** – Conversations are delivered through illustrated panels (`conversation*.png`, `bhai_convo*.png`, etc.). Health, path overlays, mystery clues, and ending slides are rendered as textured quads anchored to the camera.

### Flow From Code

1. `Game::Initialize()` loads every texture, sets the camera, and preps dialogue/state flags.
2. `Game::Run()` (defined in `game.cpp`) loops through `Update()` and `Draw()`:
  - `Update()` handles input, camera movement, collision checks against the building vectors, and state transitions when the player overlaps key rectangles.
  - `Draw()` renders the base map, player sprite, NPCs, highlight prompts, and whichever conversation/ending textures are active based on the current progression flags.
3. Completing the required interactions sets `Final = true`, advancing to the ending slides.

## Controls

- **Arrow keys** – Move the protagonist
- **Space/Enter** – Advance conversation panels where applicable
- **Escape** – Quit (handled by raylib default window close)

## Run The Game (Prebuilt Executable)

The repository ships with a ready-to-play binary in `src/game.exe`. Launch it from the `src` directory so relative asset loads succeed.

```powershell
Set-Location "D:/Semester 2-1/Oop Lab/Project_Fall/Project_Fall/src"
./game.exe
```

## Build From Source

1. Install the official **raylib 5.0 Windows** package (defaults to `C:/raylib`).
2. Open PowerShell in the project root and build from `src`:

  ```powershell
  Set-Location "D:/Semester 2-1/Oop Lab/Project_Fall/Project_Fall/src"
  mingw32-make
  ```

  The Makefile links against `C:/raylib/raylib` by default. Override via `mingw32-make RAYLIB_PATH="X:/path/to/raylib"` if your SDK lives elsewhere.

3. Run the fresh executable as described above.

## Assets

- `Pics/` and `src/Pics/` (ignored for Git) contain the original art sources.
- Production textures are copied beside the executable under `src/` so the game can load them without extra configuration.

## Credits

- Game design, story, and art – Team 14
- Engine – raylib 5.0 by Ramon Santamaría and contributors

Enjoy uncovering the mysteries of IUT!
