# IUT Chronicles

Story-driven top-down adventure built with raylib and modern C++. Explore the campus, talk to characters, solve small puzzles, and progress through the narrative-driven quest line.

## Requirements

- Windows 10/11 (x86_64)
- Graphics drivers supporting OpenGL 3.3
- Prebuilt binaries: no additional installs required
- Building from source: raylib SDK installed at `C:/raylib/raylib` (default from the official Windows installer)

## Repository Layout

- `game.exe` (root): legacy export
- `src/game.exe`: current build configured for relative assets
- `src/*.cpp` / `src/*.h`: gameplay, actor logic, collisions, UI
- `src/*.png`: character sprites, backgrounds, UI overlays
- `lib/`: helper libraries (tmx) and MinGW runtime DLLs

## Quick Start (Run Prebuilt Game)

1. Open PowerShell.
2. Change into the source directory:

  ```powershell
  Set-Location "D:/Semester 2-1/Oop Lab/Project_Fall/Project_Fall/src"
  ```

3. Launch the game:

  ```powershell
  .\game.exe
  ```

Running from `src` is important—the executable expects all textures and dialog PNG files beside it.

## Building from Source

> Skip this section if you only need the prebuilt executable.

1. Install the official **raylib 5.0 Windows Installer** from [raylib.com](https://www.raylib.com/). The installer places:
  - Headers and libraries under `C:/raylib/raylib`
  - MinGW toolchain under `C:/raylib/w64devkit`

2. (Optional) Confirm the SDK path:

  ```powershell
  Test-Path "C:/raylib/raylib/src/raylib.h"
  ```

3. Build the project from the `src` folder:

  ```powershell
  Set-Location "D:/Semester 2-1/Oop Lab/Project_Fall/Project_Fall/src"
  mingw32-make
  ```

  The Makefile links every gameplay module with the raylib static library and drops a fresh `game.exe` in the same directory.

4. Run the rebuilt binary exactly as in the quick start section to ensure textures load.

### Alternate SDK Locations

If raylib is installed elsewhere, override the path at build time:

```powershell
mingw32-make RAYLIB_PATH="E:/tools/raylib"
```

## Troubleshooting

- **Missing textures at runtime:** launch the executable from the `src` directory so relative PNG paths resolve.
- **`raymath.h` not found during build:** verify `RAYLIB_PATH` points at the SDK root that contains `src/raymath.h`.
- **`path2.png` warning:** the project references this file but the asset is currently absent. Add it next to the other `path*.png` files if you intend to use that scene.

## Credits

- Core gameplay, sprites, and story: Project Team 14
- Engine/framework: [raylib](https://github.com/raysan5/raylib) (5.0)

Enjoy exploring the chronicles!

