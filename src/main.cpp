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
    platform1.setWall({100, screenHeight-100, 100, 20});


    

    SetTargetFPS(60);
    

    // Main game loop
    while (!WindowShouldClose())
    {
        // UPDATE Frame
        float deltaTime = GetFrameTime();
        // collision detection and correction for platforms
        
        //update player
        player.updatePlayer(deltaTime);
        

        
        // ========================================
        // BOTTOM WALL COLLISION
        // ========================================

        Rectangle playerBox = player.getOutBox();
        Rectangle floor = platformBase.getWall();

        Vector2 newPosition =
            platformBase.checkWallCollBottom(playerBox, floor);


        // Check if bottom of player reached the floor
        if (playerBox.y + playerBox.height >= floor.y)
        {
            player.setVelocityY(0.0f);
            player.setGrounded(true);
        }
        else
        {
            player.setGrounded(false);
        }

        player.setPosition(newPosition);

        // left wall collision
        newPosition = leftWall.checkWallCollLeft(player.getOutBox(), leftWall.getWall());
        player.setPosition(newPosition);

        // right wall collision
        newPosition = rightWall.checkWallCollRight(player.getOutBox(), rightWall.getWall());
        player.setPosition(newPosition);
        //----------------------------------------------------------------------------------
        Rectangle playerBeforePlatform = player.getOutBox();
        newPosition = platform1.checkWallCollPlatform(player.getOutBox(), platform1.getWall(), player.getVelocityY());
        if(newPosition.y != playerBeforePlatform.y){
            player.setVelocityY(0.0f);
            player.setGrounded(true);
        }
        player.setPosition(newPosition);

        
        BeginDrawing();

            ClearBackground(LIGHTGRAY);
            
            // draw platforms and player
            DrawRectangleRec(player.getOutBox(), RED);
            DrawRectangleRec(player.getInBox(), BLACK);
            DrawRectangleRec(platformBase.getWall(), GRAY);
            DrawRectangleRec(leftWall.getWall(), GRAY);
            DrawRectangleRec(rightWall.getWall(), GRAY);
            DrawRectangleRec(platform1.getWall(), GRAY);




            DrawFPS(10,10);

        EndDrawing();
        
    }

    // De-Initialization

    CloseWindow();        
    

    return 0;
}

