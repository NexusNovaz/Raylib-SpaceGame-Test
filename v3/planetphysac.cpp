#include <bits/stdc++.h>

#include <raylib.h>
#define PHYSAC_IMPLEMENTATION
#include <physac.h>

#include "globals.h"
#include "CelestialObject.h"

vector<CelestialObject*> celestialObjects = {};

int main (void) {
    InitWindow(screen_width, screen_height, "");

    InitGame();

    SetTargetFPS(60);
    SetPhysicsTimeStep(1.0/60.0/100*1000);

    while (!WindowShouldClose()) {

        UpdateAndDrawGame();

    }

    ClosePhysics();
    CloseWindow();
}

void InitGame(void) {
    InitPhysics();

    PhysicsBody star = CreatePhysicsBodyCircle(center, 40, 0.1f);
    celestialObjects.push_back(new CelestialObject(star->position, 40, 0.1, Vector2{0, 0}, 10.0f, true, star));
}

void UpdateGame(void) {
    if (IsKeyPressed(KEY_P) || IsKeyPressed(KEY_ESCAPE)) {
        isPaused = !isPaused;
    }

    if (IsKeyPressed(KEY_ENTER) && !startGame) {
        startGame = !startGame;
    }
}

void DrawGame(void) {
    BeginDrawing();
    
        ClearBackground(BackgroundColor);

        if (isPaused) {
            DrawText("Press [P] to unpause", screen_width/2 - MeasureText("Press [P] to unpause", 30)/2, screen_height/2, 30, FontColor);
        }

        if (!startGame) {
            DrawText("Press [ENTER] to play", screen_width/2 - MeasureText("Press [ENTER] to play", 30)/2, screen_height/2, 30, FontColor);
        }

        if (startGame && !isPaused) { // Main Game Stuff


        }
        
    DrawFPS(10, 10);
    EndDrawing();
}

void UpdateAndDrawGame(void) {
    UpdatePhysics();
    UpdateGame();
    DrawGame();
}