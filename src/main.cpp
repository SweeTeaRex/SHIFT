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
    Platform platformBase;
    platformBase.setBottomWall({0,screenHeight-20,screenWidth, 20});
    Platform leftWall;
    leftWall.setLeftWall({0,0,20, screenHeight});
    Platform rightWall;
    rightWall.setRightWall({screenWidth-20, 0, 20, screenHeight});
    


    

    SetTargetFPS(60);
    

    // Main game loop
    while (!WindowShouldClose())
    {
        // UPDATE
        float deltaTime = GetFrameTime();

        player.updatePlayer(deltaTime);
        Vector2 newPositionBase = platformBase.checkWallColl(player.getOutBox(), player.getPosition());
        player.setPosition(newPositionBase);        
        Vector2 newPositionLeftWall = leftWall.checkWallColl(player.getOutBox(), player.getPosition());
        player.setPosition(newPositionLeftWall);
        Vector2 newPositionRightWall = rightWall.checkWallColl(player.getOutBox(), player.getPosition());
        player.setPosition(newPositionRightWall);
        
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(LIGHTGRAY);
            

            DrawRectangleRec(player.getOutBox(), RED);
            DrawRectangleRec(player.getInBox(), BLACK);
            DrawRectangleRec(platformBase.getBottomWall(), GRAY);
            DrawRectangleRec(leftWall.getLeftWall(), GRAY);
            DrawRectangleRec(rightWall.getRightWall(), GRAY);




            DrawFPS(10,10);

        EndDrawing();
        
    }

    // De-Initialization

    CloseWindow();        
    

    return 0;
}

