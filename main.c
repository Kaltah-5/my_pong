#include "raylib.h"
#include <stdio.h>

// Structure pos_rect

struct pos_rect
{
    int x_pos;
    int y_pos;
    int width;
    int height;
};

struct pos_cir
{
    int center_x;
    int center_y;
    float radius;
};

int main(void)
{
    //INITILIZATION
    //----------------------------------------------------------------------------
    const unsigned int screen_width = 800;
    const unsigned int screen_height = 450;

    // Call upon pos_rect structure
    struct pos_rect player1;
    struct pos_rect player2;
    struct pos_cir ball;

    // Player 1 initial pos_rect
    player1.x_pos = 10;
    player1.y_pos = 195;
    player1.width = 10;
    player1.height = 90;

    // Player 2 initial pos_rect
    player2.x_pos = 780;
    player2.y_pos = 195;
    player2.width = 10;
    player2.height = 90;

    // Ball initial pos_rect
    ball.center_x = 400;
    ball.center_y = 225;
    ball.radius = 10;


    
    InitWindow(screen_width, screen_height, "pong");

    SetTargetFPS(60); // Set FPS to 60
    //----------------------------------------------------------------------------
    
    // Main game loop 
    while (!WindowShouldClose()) // Detect window close button or ESC
    {

        if(IsKeyDown(KEY_W)) player1.y_pos += 2;
        if(IsKeyDown(KEY_S)) player1.y_pos -= 2;

        if(IsKeyDown(KEY_UP)) player2.y_pos += 2;
        if(IsKeyDown(KEY_DOWN)) player2.y_pos -= 2;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(ball.center_x, ball.center_y, ball.radius, RAYWHITE);

        DrawRectangle(player1.x_pos, player1.y_pos,
                      player1.width, player1.height, RED);
        DrawRectangle(player2.x_pos, player2.y_pos,
                      player2.width, player2.height, BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}