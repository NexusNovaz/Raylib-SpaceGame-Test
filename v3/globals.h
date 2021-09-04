#pragma once

int screen_width = 1280, screen_height = 720;

static bool startGame = false;
static bool isPaused = false;

#define FontColor           CLITERAL(Color){ 245, 245, 245, 255 }
#define BackgroundColor     CLITERAL(Color){ 0, 0, 0, 255 }

Vector2 center = {(float)screen_width / 2, (float)screen_height /2};


static void InitGame();
static void UpdateGame();
static void DrawGame();
static void UpdateAndDrawGame();

using namespace std;