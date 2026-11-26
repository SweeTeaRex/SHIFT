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

    // main screen image

    Image mainScreenImage = LoadImage("images/shift.png");
    Texture2D mainScreenText = LoadTextureFromImage(mainScreenImage);
    UnloadImage(mainScreenImage);

    // music
    InitAudioDevice();
    Music songs[9];
    songs[0] = LoadMusicStream("sound/dragon.mp3");
    songs[1] = LoadMusicStream("sound/wordChew.mp3");
    songs[3] = LoadMusicStream("sound/soul.mp3");
    songs[4] = LoadMusicStream("sound/dance.mp3");
    songs[5] = LoadMusicStream("sound/NASA.mp3");
    songs[2] = LoadMusicStream("sound/beats.mp3");
    songs[6] = LoadMusicStream("sound/pop.mp3");
    songs[7] = LoadMusicStream("sound/vista.mp3");
    songs[8] = LoadMusicStream("sound/Vampire.mp3");

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
    //PlayMusicStream(songs[currentSong]);

    

    // background colors
    bool pause = false;    
    Color colorArray[5] = {
        YELLOW,
        RED,
        BLUE,
        GREEN,
        ORANGE,
        
        
    };
    int colorIndex = 0;
    
////////////////////////////////////////////////////////////////////////////////////////////////////////
    // set player
    Player player;
    player.setOutBox({0,0,20,20});
    player.setInBox({0,0,10,10});
    player.setPosition({20, levelHeight-20});

    //set boundaries
    //base
    Platform platformBase;
    platformBase.setWall({0,levelHeight-20, levelWidth, 20});
    //left wall
    Platform leftWall;
    leftWall.setWall({0,0,20, levelHeight});
    // right wall
    Platform rightWall;
    rightWall.setWall({levelWidth-20, 0, 20, levelHeight});
    
    //PLATFORMS
    // platform 1  H: 100
    Platform platform1;
    platform1.setWall({levelWidth - 100, levelHeight-100, 100, 100});
    // platform 2 H: 150
    Platform platform2;
    platform2.setWall({levelWidth - 50, levelHeight - 150, 50,20});
    //platform 3  H:200
    Platform platform3;
    platform3.setWall({100, levelHeight-200, 100,20});
    //platform 4   H: 250
    Platform platform4;
    platform4.setWall({100, levelHeight-250, 100,5});
    // platform 5   H: 300
    Platform platform5;
    platform5.setWall({levelWidth-100, levelHeight-300, 100, 10});
    //platform 6  H: 350
    Platform platform6;
    platform6.setWall({levelWidth-100, levelHeight-350, 100, 1});

////////////////////////////////////////////////////////////////////////////////////////////////
    // camera
    Camera2D camera = {0};
    camera.target = player.getPosition();
    camera.offset = (Vector2){ GetRenderWidth()/2.0f, GetRenderHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    //debug camera 
    Camera2D debugCam = {0};
    debugCam.target = { 0.0f, levelHeight };
    debugCam.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
    debugCam.rotation = 0.0f;
    debugCam.zoom = 1.0f; 


  

    

    SetTargetFPS(60);
    
////////////////////////////////////////////////////////////////////////////////////////////////////
    // Main game loop
    while (!WindowShouldClose())
    {
        // UPDATE Frame
        float deltaTime = GetFrameTime();
        

        //PlayMusicStream(songs[currentSong]);

        

        // UPDATE Music

        UpdateMusicStream(songs[currentSong]);
        // std::cout << songNam[currentSong] << '\n';

        // tab to change song
        if(IsKeyPressed(KEY_TAB)){
            StopMusicStream(songs[currentSong]);
            currentSong++;
            if(currentSong >= 9){
                currentSong = 0;
            }
            PlayMusicStream(songs[currentSong]);
        }

        // pause music
        if(IsKeyPressed(KEY_P)){
            pause = !pause;

            if(pause){
                PauseMusicStream(songs[currentSong]);
            }
            else{
                ResumeMusicStream(songs[currentSong]);
            }
        }


        // global color change on shift press
        if(IsKeyPressed(KEY_LEFT_SHIFT)){
            colorIndex++;
            if(colorIndex>= 5){
                colorIndex=0;
            }
        }
        // update camera
        camera.target = player.getPosition();
///////////////////////////////////////////////////////////////////////////////////////////////////////        
        // SWITCH BETWEEN STATES
        switch (currentState){

            case INTRO:

                if(IsKeyPressed(KEY_SPACE)){
                    PlayMusicStream(songs[currentSong]);
                    currentState = MENU;
                }
                break;
            
            case MENU:

                if(IsKeyPressed(KEY_SPACE)){
                    currentState = LVL1;
                }
                break;
//////////////////////////////////////////////////////////////////////////////////////////////////////
            case LVL1:
                
                // debug camera controlls
                if (IsKeyDown(KEY_RIGHT)) {
                debugCam.target.x += 300 * GetFrameTime();
                }

                if (IsKeyDown(KEY_LEFT)) {
                    debugCam.target.x -= 300 * GetFrameTime();
                }

                if (IsKeyDown(KEY_DOWN)) {
                    debugCam.target.y += 300 * GetFrameTime();
                }

                if (IsKeyDown(KEY_UP)) {
                    debugCam.target.y -= 300 * GetFrameTime();
                }
                
            
            
                
            
////////////////////////////////////////////////////////////////////////////////////////////            
                // collision detection and correction for platforms
                
                //update player
                player.updatePlayer(deltaTime);
                

                
                
                // BOTTOM WALL COLLISION
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

                // platform 5

                playerBeforePlatform = player.getOutBox();
                newPosition = platform5.checkWallCollPlatform(player.getOutBox(), platform5.getWall(), player.getVelocityY());
                if(newPosition.y != playerBeforePlatform.y){
                    player.setVelocityY(0.0f);
                    player.setGrounded(true);
                }
                player.setPosition(newPosition);

                // platform 6

                playerBeforePlatform = player.getOutBox();
                newPosition = platform6.checkWallCollPlatform(player.getOutBox(), platform6.getWall(), player.getVelocityY());
                if(newPosition.y != playerBeforePlatform.y){
                    player.setVelocityY(0.0f);
                    player.setGrounded(true);
                }
                player.setPosition(newPosition);

                break;

    }        



        BeginDrawing();

            ClearBackground(LIGHTGRAY);

            

            switch(currentState){
                //Draw Global

                
                // Draw Individual
                case INTRO:
                    ClearBackground(BLACK);
                    DrawText("Game and Music made by SweeTeaRex", screenWidth/2-200, screenHeight/2, 25, WHITE);
                    DrawText("https://soundcloud.com/sweetearex", screenWidth/2-200, screenHeight/2+100, 25, WHITE);
                    DrawText("Press SPACE to continue", screenWidth/2-200, screenHeight/2+200, 25, WHITE);
                    break;
                
                case MENU:
                    ClearBackground(YELLOW);
                    DrawTextureEx(mainScreenText, {-25, 0}, 0.0f, 0.8, WHITE);
                    DrawText("PRESS SPACE TO START", screenWidth/2-700, screenHeight-100, 100, DARKPURPLE);
                    break;
                
                case LVL1:
                    ClearBackground(colorArray[colorIndex]);
                    BeginMode2D(camera);
                    //BeginMode2D(debugCam);
                    
                    // draw platforms and player

                    DrawRectangleRec(platform1.getWall(), BLACK);
                    DrawRectangleRec(player.getOutBox(), MAGENTA);
                    DrawRectangleRec(player.getInBox(), PINK);
                    DrawRectangleRec(platformBase.getWall(), BLACK);
                    DrawRectangleRec(leftWall.getWall(), BLACK);
                    DrawRectangleRec(rightWall.getWall(), BLACK);
                    
                    DrawRectangleRec(platform2.getWall(), BLACK);
                    DrawRectangleRec(platform3.getWall(), BLACK);
                    DrawRectangleRec(platform4.getWall(), BLACK);
                    DrawRectangleRec(platform5.getWall(), BLACK);
                    DrawRectangleRec(platform6.getWall(), BLACK);
                    
                    
                     


                    DrawText("Press P to Mute/Unmute | Press TAB to change song | A/D is move | SHIFT is Jump/Boot", camera.target.x-500, camera.target.y+350, 20, DARKPURPLE);
                    
                                        
                    break;





            }
              
            DrawFPS(camera.target.x-700, camera.target.y+350);
            EndMode2D();
        EndDrawing();
        
    }

    // De-Initialization

    UnloadMusicStream(songs[currentSong]);
    CloseAudioDevice();

    CloseWindow();        
    

    return 0;
}

