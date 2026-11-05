#include <iostream> 
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "platform.h"
#include "enemy.h"
#include "theCamera.h"
#include "gameData.h"

// Platformer game




int main(void)
{
    
    InitWindow(screenWidth, screenHeight, "Platformer Game");
    // set player
    Player player;
    player.setOutBox({0,0,20,20});
    player.setInBox({0,0,10,10});
    player.setPosition({screenWidth/2, screenHeight/2});
    player.setSpeed(0);

    //set boundaries
    //base
    Platform platformBase;
    platformBase.setWall({0,screenHeight-20,screenWidth, 20});
    //left wall
    Platform leftWall;
    leftWall.setWall({0,0,20, screenHeight});
    // right wall
    Platform rightWall;
    rightWall.setWall({screenWidth-20, 0, 20, screenHeight});
    // platform 1
    Platform platform1;


    

    SetTargetFPS(60);
    

    // Main game loop
    while (!WindowShouldClose())
    {
        // UPDATE Frame
        float deltaTime = GetFrameTime();
        // collision detection and correction for platforms
        player.updatePlayer(deltaTime);
        
        
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(LIGHTGRAY);
            
            // draw platforms and player
            DrawRectangleRec(player.getOutBox(), RED);
            DrawRectangleRec(player.getInBox(), BLACK);
            DrawRectangleRec(platformBase.getWall(), GRAY);
            DrawRectangleRec(leftWall.getWall(), GRAY);
            DrawRectangleRec(rightWall.getWall(), GRAY);




            DrawFPS(10,10);

        EndDrawing();
        
    }

    // De-Initialization

    CloseWindow();        
    

    return 0;
}

