#include "Professor.h"

Professor::Professor() : Player() {
    position = {1100, 870}; // Initialize the professor's position
    proConvoStep = 0;
}

void Professor::LoadTextures() {
    texture = LoadTexture("professor.png");

    const char* convoFiles[14] = {
        "pro1.png", "pro2.png", "pro3.png", "pro4.png", "pro5.png", "pro6.png", "pro7.png",
        "pro8.png", "pro9.png", "pro10.png", "pro11.png", "pro12.png", "pro13.png", "pro14.png"
    };

    for (int i = 0; i < 14; i++) {
        convoTextures[i] = LoadTexture(convoFiles[i]);
    }
}

void Professor::UnloadTextures() {
    UnloadTexture(texture);
    for (int i = 0; i < 14; i++) {
        UnloadTexture(convoTextures[i]);
    }
}

void Professor::Draw(Vector2 position) {
    Rectangle source = {0.0f, 0.0f, (float)texture.width, (float)texture.height};
    Rectangle dest = {position.x-120, position.y-80, 500, 300}; // Use fixed size for professor
    Vector2 origin = {0, 0};
    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}

void Professor::DrawConversation(int step, Vector2 position) {
    if (step >= 0 && step < 14) {
        DrawTexture(convoTextures[step], position.x, position.y, WHITE);
    }
}