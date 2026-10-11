#include <raylib.h>
#include <iostream>
#include <string>
using namespace std;

float SCORE = 0;

Color MyBrown = {65, 35, 0, 255};

class Cookie {
public:
    Texture2D texture;
    float x;
    float y;
    int clickPower;
    float scale = 1.0f;
    float timer = 0.0f;

    Cookie(Texture2D texture, int clickPower) {
        this->texture = texture;
        this->clickPower = clickPower;
        x = 0;
        y = 0;
    }

    Vector2 Center() {
        return {x + texture.width / 2.0f, y + texture.height / 2.0f};
    }

    float Radius() {
        return texture.width / 2.0f * 0.3;
    }

    virtual void Click() {
        SCORE += clickPower;
        scale = 1.05f;
        timer = 0.03f;
    }

    virtual void Draw() {
        if (timer > 0.0f) {
            timer -= GetFrameTime();
            if (timer <= 0.0f) scale = 1.0f;
        }

        float width = texture.width * scale;
        float height = texture.height * scale;

        DrawTexturePro(texture, {0, 0, (float)texture.width, (float)texture.height}, {x - (width - texture.width) / 2, y - (height - texture.height) / 2, width, height}, {0, 0}, 0.0f, WHITE);
    }

    virtual ~Cookie() = default;
};

int main() {
    const int WIDTH = 900;
    const int HEIGHT = 1080;
    const char* NAME = "Cookie";
    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(WIDTH, HEIGHT, NAME);

    Texture2D OreoTexture = LoadTexture("assets/textures/oreo.png");
    Texture2D CookieTexture = LoadTexture("assets/textures/cookie.png");

    Cookie cookie(CookieTexture, 1);

    cookie.x = (WIDTH - CookieTexture.width) / 2.0f;
    cookie.y = (HEIGHT - CookieTexture.height) / 2.0f;

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointCircle(mouse, cookie.Center(), cookie.Radius())) {
                cookie.Click();
            }
        }

        BeginDrawing();
            ClearBackground(MyBrown);
            cookie.Draw();
            DrawText(TextFormat("Cookies: %.0f", SCORE), 20, 20, 30, DARKBROWN);
        EndDrawing();
    }

    UnloadTexture(CookieTexture);
    UnloadTexture(OreoTexture);
    CloseWindow();

    return 0;
}