#include <iostream>
#include <math.h>
#include <raylib.h>
#include <rlgl.h>
#include <unistd.h>

static const int screen_height = 980;
static const int screen_width = 1820;


// static unsigned int microsecond = 1000000;
// static float timePassed;
// static float dt;

static bool startGame = false;
static bool isPaused = false;

static int score = 0;

static const Color text_color = RAYWHITE;
static const Color background_color = BLACK;

// Solar System Definitions
const float starRadius = 100.0f;
const float firstPlanetRadius = 10.0f;
const float secondPlanetRadius = 20.0f;

float firstPlanetRotation = 0.0f;
float secondPlanetRotation = 0.0f;
float rotationSpeed = 1.0f;

Vector2 center = {(float)screen_width / 2, (float)screen_height /2};
Vector2 mousePosition = {};


static void InitGame();
static void UpdateGame(); // Update The Game (One Frame)
static void DrawGame(); // Draw the Game (One Frame)
static void UpdateAndDrawGame(); // Update and Draw the Game (One Frame)

using namespace std;

int main(void) {
    
    InitWindow(screen_width, screen_height, "");

    InitGame(); // Brings up the start screen (essentially wait for enter to be pressed)

    SetTargetFPS(60);


    while (!WindowShouldClose()) {
        
        UpdateAndDrawGame();

    }

    CloseWindow();
}

void InitGame() {
    cout << "Initial Load" << endl;
}

void UpdateGame(void) {
    if (IsKeyPressed(KEY_P) || IsKeyPressed(KEY_ESCAPE)) {
        isPaused = !isPaused;
    }

    if (IsKeyPressed(KEY_ENTER) && !startGame) {
        startGame = !startGame;
    }

    if (IsKeyPressed(KEY_UP) && startGame && !isPaused) {
        rotationSpeed += 0.1f;
    }

    if (IsKeyPressed(KEY_DOWN) && startGame && !isPaused) {
        rotationSpeed -= 0.1f;
    }

    if (IsKeyDown(KEY_RIGHT) && startGame && !isPaused) {
        rotationSpeed += 0.1f;
    }

    if (IsKeyDown(KEY_LEFT) && startGame && !isPaused) {
        rotationSpeed -= 0.1f;
    }

    // dt = GetFrameTime();
    // timePassed = dt + timePassed;

    firstPlanetRotation += (272/360.0f * (5.0f * rotationSpeed) * rotationSpeed) * GetFrameTime();
    secondPlanetRotation += (135/360.0f * (5.0f * rotationSpeed) * rotationSpeed) * GetFrameTime();

}

void DrawGame(void) {
    BeginDrawing();
    
        ClearBackground(background_color);
        
        if (isPaused) {
            DrawText("Press [P] to unpause", screen_width/2 - MeasureText("Press [P] to unpause", 30)/2, screen_height/2, 30, text_color);
        }

        if (!startGame) {
            DrawText("Press [ENTER] to play", screen_width/2 - MeasureText("Press [ENTER] to play", 30)/2, screen_height/2, 30, text_color);
        }

        if (startGame && !isPaused) {


            rlPushMatrix();
                rlTranslatef(center.x, center.y, 0);
                DrawCircle(0, 0, starRadius, GOLD);
                {
                    rlPushMatrix();
                        rlRotatef(firstPlanetRotation, 0, 0, 1);
                        rlTranslatef(200, 0, 0);
                        DrawCircle(0, 0, firstPlanetRadius, GRAY);
                    rlPopMatrix();
                    rlPushMatrix();
                        rlRotatef(secondPlanetRotation, 0, 0, 1);
                        rlTranslatef(400, 0, 0);
                        DrawCircle(0, 0, secondPlanetRadius, BLUE);
                    rlPopMatrix();
                }
            rlPopMatrix();

            DrawText(TextFormat("Rotation Speed: %02.02f", rotationSpeed), 10, 30, 20, RAYWHITE);
        }

    DrawFPS(10, 10);
    EndDrawing();
}

void UpdateAndDrawGame(void) {
    UpdateGame();
    DrawGame();
}