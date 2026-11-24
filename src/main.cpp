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
    GameState currentState = INTRO;

    float alpha = 1.0f;

    // music
    InitAudioDevice();
    Music songs[9];
    songs[0] = LoadMusicStream("dragon.wav");
    songs[1] = LoadMusicStream("chew.mp3");
    songs[3] = LoadMusicStream("soul.wav");
    songs[4] = LoadMusicStream("dance.mp3");
    songs[5] = LoadMusicStream("NASA.wav");
    songs[2] = LoadMusicStream("beats.wav");
    songs[6] = LoadMusicStream("pop.wav");
    songs[7] = LoadMusicStream("vista.mp3");
    songs[8] = LoadMusicStream("Vampire.wav");

    std::string songNam[9] = {
        "Eye of the Dragon",
        "wordChew",
        "beats.wav",
        "Chord Soul Intrumental",
        "dancing in your room at 2 am",
        "NASA at Night",
        "Cranjis McBasketBall",
        "NightmareonVistaDrive",
        "VampireCoverBand"
    };

    int currentSong = 0;
    PlayMusicStream(songs[currentSong]);

    bool pause = false;    


    // set player
    Player player;
    player.setOutBox({0,0,20,20});
    player.setInBox({0,0,10,10});
    player.setPosition({20, screenHeight-20});

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
    
    //PLATFORMS
    // platform 1
    Platform platform1;
    platform1.setWall({100, screenHeight-100, 100, 20});
    // platform 2
    Platform platform2;
    platform2.setWall({screenWidth - 50, screenHeight - 150, 100,20});
    //platform 3
    Platform platform3;
    platform3.setWall({100, screenHeight-200, 100,20});
    //platform 4
    Platform platform4;
    platform4.setWall({100, screenHeight-250, 100,20});



    

    SetTargetFPS(60);
    

    // Main game loop
    while (!WindowShouldClose())
    {
        // UPDATE Frame
        float deltaTime = GetFrameTime();

        // UPDATE Music

        UpdateMusicStream(songs[currentSong]);
        std::cout << songNam[currentSong] << '\n';

        if(IsKeyPressed(KEY_TAB)){
            StopMusicStream(songs[currentSong]);
            currentSong++;
            if(currentSong >= 9){
                currentSong = 0;
            }
            PlayMusicStream(songs[currentSong]);
        }

        if(IsKeyPressed(KEY_P)){
            pause = !pause;

            if(pause){
                PauseMusicStream(songs[currentSong]);
            }
            else{
                ResumeMusicStream(songs[currentSong]);
            }
        }

        // SWITCH BETWEEN STATES
        switch (currentState){

            case INTRO:

                if(IsKeyPressed(KEY_SPACE)){
                    currentState = MENU;
                }
                break;
            
            case MENU:

                if(IsKeyPressed(KEY_SPACE)){
                    currentState = LVL1;
                }
                break;

            case LVL1:
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
                //Platform 1
                Rectangle playerBeforePlatform = player.getOutBox();
                newPosition = platform1.checkWallCollPlatform(player.getOutBox(), platform1.getWall(), player.getVelocityY());
                if(newPosition.y != playerBeforePlatform.y){
                    player.setVelocityY(0.0f);
                    player.setGrounded(true);
                }
                player.setPosition(newPosition);


                // platform 2
                playerBeforePlatform = player.getOutBox();
                newPosition = platform2.checkWallCollPlatform(player.getOutBox(), platform2.getWall(), player.getVelocityY());
                if(newPosition.y != playerBeforePlatform.y){
                    player.setVelocityY(0.0f);
                    player.setGrounded(true);
                }
                player.setPosition(newPosition);
                // platform 3
                playerBeforePlatform = player.getOutBox();
                newPosition = platform3.checkWallCollPlatform(player.getOutBox(), platform3.getWall(), player.getVelocityY());
                if(newPosition.y != playerBeforePlatform.y){
                    player.setVelocityY(0.0f);
                    player.setGrounded(true);
                }
                player.setPosition(newPosition);
                //platform 4
                playerBeforePlatform = player.getOutBox();
                newPosition = platform4.checkWallCollPlatform(player.getOutBox(), platform4.getWall(), player.getVelocityY());
                if(newPosition.y != playerBeforePlatform.y){
                    player.setVelocityY(0.0f);
                    player.setGrounded(true);
                }
                player.setPosition(newPosition);

                break;

    }        



        BeginDrawing();

            ClearBackground(LIGHTGRAY);

            DrawFPS(20,20);


            switch(currentState){
                //Draw Global

                
                // Draw Individual
                case INTRO:
                    ClearBackground(BLACK);
                    DrawText("Game and Music made by SweeTeaRex", screenWidth/2-200, screenHeight/2, 25, WHITE);
                    DrawText("Press SPACE to continue", screenWidth/2-200, screenHeight/2+100, 25, WHITE);
                    break;
                
                case MENU:
                    break;
                
                case LVL1:
                    // draw platforms and player
                    DrawRectangleRec(player.getOutBox(), RED);
                    DrawRectangleRec(player.getInBox(), BLACK);
                    DrawRectangleRec(platformBase.getWall(), GRAY);
                    DrawRectangleRec(leftWall.getWall(), GRAY);
                    DrawRectangleRec(rightWall.getWall(), GRAY);
                    DrawRectangleRec(platform1.getWall(), GRAY);
                    DrawRectangleRec(platform2.getWall(), GRAY);
                    DrawRectangleRec(platform3.getWall(), GRAY);
                    DrawRectangleRec(platform4.getWall(), GRAY);
                    break;





            }
        /*    std::string songNam[9] = {
        "Eye of the Dragon",
        "wordChew",
        "beats.wav",
        "Chord Soul Intrumental",
        "dancing in your room at 2 am",
        "NASA at Night",
        "Cranjis McBasketBall",
        "NightmareonVistaDrive",
        "VampireCoverBand"
    };

*/            
            DrawText("Press P to Mute/Unmute", 10, screenHeight-20, 20, BLACK);
            DrawText("Press TAB to change song", screenWidth/2-100, screenHeight-20, 20, BLACK);
        EndDrawing();
        
    }

    // De-Initialization

    UnloadMusicStream(songs[currentSong]);
    CloseAudioDevice();

    CloseWindow();        
    

    return 0;
}

