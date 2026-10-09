#include <raylib.h>
#include <iostream>
#include <string>
using namespace std;

float SCORE = 0;

int main() {
    const int WIDTH = 900;
    const int HEIGHT = 1080;
    const char* NAME = "Cookie";
    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(WIDTH, HEIGHT, NAME);
    Texture2D Oreo = LoadTexture("assets/textures/oreo.png");
    Texture2D Cookie = LoadTexture("assets/textures/cookie.png");
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BROWN);
            DrawTexture(Cookie, (WIDTH - Cookie.width) / 2, (HEIGHT - Cookie.height) / 2, WHITE);
        EndDrawing();
    }
    UnloadTexture(Cookie);
    UnloadTexture(Oreo);
    CloseWindow();
    return 0;
}