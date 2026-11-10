#include "raylib.h"

int main()
{
    InitWindow(800, 600, "My First C++ Game");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello Raylib!", 300, 250, 30, DARKGRAY);
        DrawCircle(400, 350, 40, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}