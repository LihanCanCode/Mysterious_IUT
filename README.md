# Mysterious IUT

## 1️⃣ Project Title + Tagline
- **Game Name:** Mysterious IUT
- **Hook:** A campus mystery where every familiar landmark hides a forgotten truth.

## 2️⃣ Short Description
Mysterious IUT is a mystery adventure with thriller undertones, presented from a top-down perspective and developed for Windows PC with C++ and raylib. Players explore the IUT campus, piecing together cryptic clues and conversations to uncover what really happened to a vanished professor—all without spoiling the truth outright.

## 3️⃣ Story Premise (Spoiler-Free)
- **Setting:** A meticulously mapped recreation of the IUT campus featuring the lake, CDS, dorms, classrooms, library, hospital, and hidden facilities.
- **Protagonist:** A wide-eyed freshman, eager to learn the campus layout and culture.
- **Conflict:** The campus murmurs about Professor Heigenberg’s secret experiment, Project Bhool Bhoolaiya, and why no one seems to remember his assistant—or the professor himself. Your curiosity pulls you deeper into the mystery.

## 4️⃣ Gameplay Overview
- Explore the campus in a free-roaming top-down world with camera-following movement.
- Talk to classmates and faculty to gather rumors, alibis, and critical hints.
- Collect key items to unlock restricted buildings and trigger story beats.
- Solve light environmental puzzles that link evidence to locations.
- Follow state-driven event sequences coded in [src/game.cpp](src/game.cpp) that react to your discoveries.

## 5️⃣ Key Features
- 🧩 Campus-wide investigation that rewards thorough exploration.
- 🕵️ Player-driven narrative pacing—choose who to question first.
- 🔐 Gated areas that open as you assemble key clues and items.
- 🎭 Character-focused dialogue panels that convey mood and stakes.
- 🗂️ Evidence tracking through scripted state flags and item pickups.
- 🎧 Ambient soundscape and visual overlays that heighten tension.

## 6️⃣ Controls / How to Play
- Arrow Keys: Move the protagonist
- Space or Enter: Advance dialogue and confirm prompts
- Escape: Exit to desktop (raylib default)

## 7️⃣ Screenshots / GIFs
<p align="center">
  <img src="src/conversation1.png" alt="Conversation panel with NPC" width="720">
</p>
<p align="center">
  <img src="src/menu1.png" alt="Main menu highlighting Play and Exit" width="720">
</p>

## 8️⃣ Installation / Run Instructions
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

3. Override the SDK path if needed:

```powershell
mingw32-make RAYLIB_PATH="X:/path/to/raylib"
```

4. Run the newly compiled `game.exe` from the same directory so assets resolve properly.

## 9️⃣ Tech Stack
- Engine / Framework: raylib 5.0
- Language: C++17
- Build System: MinGW make with the provided Makefile
- Entry Point: [src/main.cpp](src/main.cpp) spawning the `Game` controller implemented in [src/game.cpp](src/game.cpp)

## 🔟 Project Status
- In development — playable campus slice with core narrative loop and mechanics implemented.
