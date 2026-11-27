#include <iostream> 
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "platform.h"
#include "enemy.h"
#include "theCamera.h"
#include "gameData.h"
#include "fakeplatform.h"

// Platformer game




int main(void)
{
    
    InitWindow(screenWidth, screenHeight, "Platformer Game");
    GameState currentState = INTRO;
    //GameState currentState = LVL1;

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
    // original start
    player.setPosition({20, levelHeight-20});
    // level 2 start
    //player.setPosition({levelWidth/2, levelHeight-700});

    //set boundaries
    //base
    Platform platformBase;
    platformBase.setWall({0,levelHeight-20, levelWidth, 20});
    //left wall
    Platform leftWall;
    leftWall.setWall({0,0,20, levelHeight});
    // right wall
    Platform rightWall;
    rightWall.setWall({levelWidth, 0, 30, levelHeight});
    
    
    
    //REAL PLATFORMS LANDING
    int REAL_PLATFORM_COUNT = 24;
    Platform realPlatformArr[REAL_PLATFORM_COUNT];
    int platformColorIndex = 0;
    
    // LEVEL 1
    // platform 1  H: 100
    realPlatformArr[0].setWall({levelWidth - 100, levelHeight-100, 100, 20});
    // platform 2 H: 150
    realPlatformArr[1].setWall({levelWidth - 50, levelHeight - 150, 50,20});
    //platform 3  H:200
    realPlatformArr[2].setWall({100, levelHeight-200, 100,20});
    //platform 4   H: 250
    realPlatformArr[3].setWall({100, levelHeight-250, 100,5});
    // platform 5   H: 300
    realPlatformArr[4].setWall({levelWidth-100, levelHeight-300, 100, 10});
    //platform 6  H: 350
    realPlatformArr[5].setWall({levelWidth-100, levelHeight-350, 100, 1});
    // platform 7 H: 400
    realPlatformArr[6].setWall({20, levelHeight-400, 20, 1});
    // platform 8 H: 450
    realPlatformArr[7].setWall({levelWidth/2, levelHeight-450, 40, 10});
    // platform 9 H: 500
    realPlatformArr[8].setWall({levelWidth/2-100, levelHeight-500, 40, 5});
    // platform 10 H: 550
    realPlatformArr[9].setWall({levelWidth/2, levelHeight-550, 10, 5});
     // platform 11 H: 600
    realPlatformArr[10].setWall({levelWidth/2+100, levelHeight-600, 5, 5});
    // platform 12 H: 650
    realPlatformArr[11].setWall({200, levelHeight-650, levelWidth-250, 5});
    
    //LEVEL 2
    //platform 13 H:700
    realPlatformArr[12].setWall({levelWidth-100, levelHeight-700, 50, 5});
    //platform 14 750
    realPlatformArr[13].setWall({levelWidth-200, levelHeight-750, 10, 2});
    //platform 15 800
    realPlatformArr[14].setWall({levelWidth-70, levelHeight-800, 50, 2});
    //platform 16 850
    realPlatformArr[15].setWall({0, levelHeight-850, 50, 2});
    //platform 17 900
    realPlatformArr[16].setWall({100, levelHeight-900, 10, 2});
    //platform 18 950
    realPlatformArr[17].setWall({0, levelHeight-950, 30, 2});
    //platform 19 1000
    realPlatformArr[18].setWall({levelWidth-70, levelHeight-1000, 30, 2});
    //platform 20 1050
    realPlatformArr[19].setWall({levelWidth-60, levelHeight-1050, 25, 2});
    //platform 21 1100
    realPlatformArr[20].setWall({levelWidth/2, levelHeight-1100, 10, 10});
    //platform 22 1150
    realPlatformArr[21].setWall({levelWidth-55, levelHeight-1150, 25, 2});
    //platform 23 1200
    realPlatformArr[22].setWall({levelWidth-155, levelHeight-1200, 10, 10});
    //platform 24 1250
    realPlatformArr[23].setWall({100, levelHeight-1250, levelWidth-200, 2});

    
    
    
    
    // FAKE PLATFORMS IN FRONT
    int NUM_FAKE_PLATFORMS_FRONT = 35;
    FakePlatform fakePlatformsFront[NUM_FAKE_PLATFORMS_FRONT];
    // LEVEL 1
    fakePlatformsFront[0].setShape(RECTANGLE);
    fakePlatformsFront[0].setPosition({levelWidth/2-200, levelHeight-1000});
    fakePlatformsFront[0].setSize(5,1000);

    fakePlatformsFront[1].setShape(TRIANGLE);
    fakePlatformsFront[1].setPosition({levelWidth/2-200, levelHeight});
    fakePlatformsFront[1].setSize(100, 200);
    
    fakePlatformsFront[2].setShape(TRIANGLE);
    fakePlatformsFront[2].setPosition({levelWidth/2-50, levelHeight});
    fakePlatformsFront[2].setSize(100, 200);

    fakePlatformsFront[3].setShape(RECTANGLE);
    fakePlatformsFront[3].setPosition({levelWidth/2+200, levelHeight-1000});
    fakePlatformsFront[3].setSize(5,1000);

    fakePlatformsFront[4].setShape(RECTANGLE);
    fakePlatformsFront[4].setPosition({levelWidth/2+150, levelHeight-1000});
    fakePlatformsFront[4].setSize(5,1000);

    fakePlatformsFront[5].setShape(RECTANGLE);
    fakePlatformsFront[5].setPosition({250, levelHeight-400});
    fakePlatformsFront[5].setSize(200,20);

    fakePlatformsFront[6].setShape(RECTANGLE);
    fakePlatformsFront[6].setPosition({650, levelHeight-500});
    fakePlatformsFront[6].setSize(100,10);

    fakePlatformsFront[7].setShape(RECTANGLE);
    fakePlatformsFront[7].setPosition({50, levelHeight-500});
    fakePlatformsFront[7].setSize(100,5);

    fakePlatformsFront[8].setShape(RECTANGLE);
    fakePlatformsFront[8].setPosition({50, levelHeight-600});
    fakePlatformsFront[8].setSize(50,15);

    fakePlatformsFront[9].setShape(RECTANGLE);
    fakePlatformsFront[9].setPosition({0, levelHeight-550});
    fakePlatformsFront[9].setSize(350,1);

    fakePlatformsFront[10].setShape(RECTANGLE);
    fakePlatformsFront[10].setPosition({400, levelHeight-530});
    fakePlatformsFront[10].setSize(350,1);

    fakePlatformsFront[11].setShape(RECTANGLE);
    fakePlatformsFront[11].setPosition({0, levelHeight-650});
    fakePlatformsFront[11].setSize(50,30);

    fakePlatformsFront[12].setShape(RECTANGLE);
    fakePlatformsFront[12].setPosition({levelWidth-300, levelHeight-600});
    fakePlatformsFront[12].setSize(300,20);

    fakePlatformsFront[13].setShape(RECTANGLE);
    fakePlatformsFront[13].setPosition({200, levelHeight-600});
    fakePlatformsFront[13].setSize(150,2);

    // LEVEL 2

    fakePlatformsFront[14].setShape(RECTANGLE);
    fakePlatformsFront[14].setPosition({100, levelHeight-700});
    fakePlatformsFront[14].setSize(150,2);

    fakePlatformsFront[15].setShape(RECTANGLE);
    fakePlatformsFront[15].setPosition({0, levelHeight-910});
    fakePlatformsFront[15].setSize(levelWidth,2);

    fakePlatformsFront[16].setShape(RECTANGLE);
    fakePlatformsFront[16].setPosition({0, levelHeight-940});
    fakePlatformsFront[16].setSize(levelWidth,2);

    fakePlatformsFront[17].setShape(RECTANGLE);
    fakePlatformsFront[17].setPosition({levelWidth/2+200, levelHeight-700});
    fakePlatformsFront[17].setSize(20,7);

    fakePlatformsFront[18].setShape(RECTANGLE);
    fakePlatformsFront[18].setPosition({levelWidth/2+50, levelHeight-750});
    fakePlatformsFront[18].setSize(100,2);

    fakePlatformsFront[19].setShape(RECTANGLE);
    fakePlatformsFront[19].setPosition({50, levelHeight-750});
    fakePlatformsFront[19].setSize(100,10);

    fakePlatformsFront[20].setShape(RECTANGLE);
    fakePlatformsFront[20].setPosition({levelWidth/2-170, levelHeight-850});
    fakePlatformsFront[20].setSize(500,5);

    fakePlatformsFront[21].setShape(RECTANGLE);
    fakePlatformsFront[21].setPosition({levelWidth/2-190, levelHeight-800});
    fakePlatformsFront[21].setSize(300,5);

    fakePlatformsFront[22].setShape(RECTANGLE);
    fakePlatformsFront[22].setPosition({levelWidth/2-190, levelHeight-800});
    fakePlatformsFront[22].setSize(300,5);

    fakePlatformsFront[23].setShape(RECTANGLE);
    fakePlatformsFront[23].setPosition({20, levelHeight-800});
    fakePlatformsFront[23].setSize(40,5);

    fakePlatformsFront[24].setShape(RECTANGLE);
    fakePlatformsFront[24].setPosition({200, levelHeight-950});
    fakePlatformsFront[24].setSize(300,1);

    fakePlatformsFront[25].setShape(RECTANGLE);
    fakePlatformsFront[25].setPosition({50, levelHeight-1910});
    fakePlatformsFront[25].setSize(2,1000);

    fakePlatformsFront[26].setShape(RECTANGLE);
    fakePlatformsFront[26].setPosition({75, levelHeight-1910});
    fakePlatformsFront[26].setSize(1,1000);

    fakePlatformsFront[27].setShape(RECTANGLE);
    fakePlatformsFront[27].setPosition({60, levelHeight-1910});
    fakePlatformsFront[27].setSize(1,1000);

    fakePlatformsFront[28].setShape(RECTANGLE);
    fakePlatformsFront[28].setPosition({levelWidth-500, levelHeight-980});
    fakePlatformsFront[28].setSize(300, 5);

    fakePlatformsFront[29].setShape(RECTANGLE);
    fakePlatformsFront[29].setPosition({levelWidth/2-200, levelHeight-1140});
    fakePlatformsFront[29].setSize(150, 1);

    fakePlatformsFront[30].setShape(RECTANGLE);
    fakePlatformsFront[30].setPosition({levelWidth/2-200, levelHeight-1130});
    fakePlatformsFront[30].setSize(200, 1);

    fakePlatformsFront[31].setShape(RECTANGLE);
    fakePlatformsFront[31].setPosition({levelWidth/2-200, levelHeight-1120});
    fakePlatformsFront[31].setSize(225, 1);

    fakePlatformsFront[32].setShape(RECTANGLE);
    fakePlatformsFront[32].setPosition({levelWidth/2-200, levelHeight-1110});
    fakePlatformsFront[32].setSize(250, 1);

    fakePlatformsFront[33].setShape(RECTANGLE);
    fakePlatformsFront[33].setPosition({levelWidth/2-200, levelHeight-1100});
    fakePlatformsFront[33].setSize(275, 1);

    fakePlatformsFront[34].setShape(RECTANGLE);
    fakePlatformsFront[34].setPosition({levelWidth/2-200, levelHeight-1090});
    fakePlatformsFront[34].setSize(300, 1);


    
    
    // FAKE PLATFORMS BEHIND PLAYER
    int NUM_FAKE_PLATFORMS_BACK = 13;
    FakePlatform fakePlatformsBack[NUM_FAKE_PLATFORMS_BACK];
    
    // LEVEL 1
    fakePlatformsBack[0].setShape(TRIANGLE);
    fakePlatformsBack[0].setPosition({levelWidth/2-170, levelHeight});
    fakePlatformsBack[0].setSize(200, 300);
    // H 200
    fakePlatformsBack[1].setShape(CIRCLE);
    fakePlatformsBack[1].setPosition({100, levelHeight-200});
    fakePlatformsBack[1].setSize(50, 50);
    // H 200
    fakePlatformsBack[2].setShape(ELLIPSE);
    fakePlatformsBack[2].setPosition({levelWidth/2+300, levelHeight-200});
    fakePlatformsBack[2].setSize(50, 20);
    // H 300
    fakePlatformsBack[3].setShape(RECTANGLE);
    fakePlatformsBack[3].setPosition({levelWidth/2, levelHeight-300});
    fakePlatformsBack[3].setSize(50, 20);
    // H 100
    fakePlatformsBack[4].setShape(CIRCLE);
    fakePlatformsBack[4].setPosition({levelWidth-300, levelHeight-100});
    fakePlatformsBack[4].setSize(50, 20);
    // H 500
    fakePlatformsBack[5].setShape(CIRCLE);
    fakePlatformsBack[5].setPosition({levelWidth-100, levelHeight-500});
    fakePlatformsBack[5].setSize(50, 20);

    fakePlatformsBack[6].setShape(ELLIPSE);
    fakePlatformsBack[6].setPosition({100, levelHeight-500});
    fakePlatformsBack[6].setSize(20, 70);
    
    // LEVEL 2
    fakePlatformsBack[6].setShape(TRIANGLE);
    fakePlatformsBack[6].setPosition({levelWidth/2, levelHeight-650});
    fakePlatformsBack[6].setSize(50, 200);

    fakePlatformsBack[7].setShape(TRIANGLE);
    fakePlatformsBack[7].setPosition({levelWidth/2-100, levelHeight-650});
    fakePlatformsBack[7].setSize(50, 250);

    fakePlatformsBack[8].setShape(TRIANGLE);
    fakePlatformsBack[8].setPosition({levelWidth/2-150, levelHeight-650});
    fakePlatformsBack[8].setSize(50, 150);

    fakePlatformsBack[9].setShape(TRIANGLE);
    fakePlatformsBack[9].setPosition({levelWidth/2-125, levelHeight-650});
    fakePlatformsBack[9].setSize(50, 350);

    fakePlatformsBack[10].setShape(TRIANGLE);
    fakePlatformsBack[10].setPosition({levelWidth/2-50, levelHeight-650});
    fakePlatformsBack[10].setSize(75, 310);

    fakePlatformsBack[11].setShape(TRIANGLE);
    fakePlatformsBack[11].setPosition({levelWidth/2-75, levelHeight-650});
    fakePlatformsBack[11].setSize(75, 210);

    fakePlatformsBack[12].setShape(CIRCLE);
    fakePlatformsBack[12].setPosition({levelWidth/2-200, levelHeight-1100});
    fakePlatformsBack[12].setSize(75, 210);




////////////////////////////////////////////////////////////////////////////////////////////////
    // camera
    Camera2D camera = {0};
    camera.target = player.getPosition();
    camera.offset = (Vector2){ GetRenderWidth()/2.0f, GetRenderHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    //debug camera 
    Camera2D debugCam = {0};
    debugCam.target = player.getPosition() ;
    debugCam.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
    debugCam.rotation = 0.0f;
    debugCam.zoom = 1.0f; 

    
    int camIndex = 0;
  

    

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

                if(IsKeyPressed(KEY_O)){
                    platformColorIndex++;
                    if(platformColorIndex>=2){
                        platformColorIndex=0;
                    }
                }
                
                if(IsKeyPressed(KEY_C)){
                    camIndex++;
                    if(camIndex>=2){
                        camIndex=0;
                    }
                }
                
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
                

                player.setPosition(newPosition);


                // left wall collision
                newPosition = leftWall.checkWallCollLeft(player.getOutBox(), leftWall.getWall());
                player.setPosition(newPosition);


                // right wall collision
                newPosition = rightWall.checkWallCollRight(player.getOutBox(), rightWall.getWall());
                player.setPosition(newPosition);


                // REAL PLATFORM COLLISION
                for (int i = 0; i < REAL_PLATFORM_COUNT; i++) {

                Rectangle playerBeforePlatform = player.getOutBox();

                newPosition = realPlatformArr[i].checkWallCollPlatform(
                    player.getOutBox(),
                    realPlatformArr[i].getWall(),
                    player.getVelocityY()
                );

                if (newPosition.y != playerBeforePlatform.y) {
                    player.setVelocityY(0.0f);
                    player.setGrounded(true);
                }

                player.setPosition(newPosition);
                }
            
                // in game height statistic 
                player.setCurrentHeight(levelHeight - player.getPosition().y);
                
                if(player.getCurrentHeight() > player.getTopHeight()){
                    player.setTopHeight(player.getCurrentHeight());
                }

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
                    
                    if(camIndex==0){
                        BeginMode2D(camera);
                    }
                    else {
                        BeginMode2D(debugCam);
                    }
                    //BeginMode2D(debugCam);
                    
                    // RENDER BEHIND PLAYER
                    for (int i = 0; i < NUM_FAKE_PLATFORMS_BACK; i++) {
                    fakePlatformsBack[i].draw();
                    }
                    DrawText("LEVEL 1", 25, levelHeight-63, 50, BLACK);
                    DrawText("Can you get to the top?", 25, levelHeight-90, 15, BLACK);
                    DrawText("LEVEL 2", 670, levelHeight-680, 30, BLACK);
                    DrawText("LEVEL 3", levelWidth/2, levelHeight-1280, 30, BLACK);

                    // PLAYER RENDER
                    DrawRectangleRec(player.getOutBox(), MAGENTA);
                    DrawRectangleRec(player.getInBox(), PINK);
                    // RENDER IN FRONT OF PLAYER
                    DrawRectangleRec(platformBase.getWall(), BLACK);
                    DrawRectangleRec(leftWall.getWall(), BLACK);
                    DrawRectangleRec(rightWall.getWall(), BLACK);
                    // REAL PLATFORM RENDER IN FRONT
                    if(platformColorIndex==0){
                    for (int i = 0; i < REAL_PLATFORM_COUNT; i++) {
                    DrawRectangleRec(realPlatformArr[i].getWall(), BLACK);
                    }
                    }
                    else{
                    for (int i = 0; i < REAL_PLATFORM_COUNT; i++) {
                    DrawRectangleRec(realPlatformArr[i].getWall(), PINK);
                    }
                    }
                    // FALSE SHAPE RENDER IN FRONT
                    for (int i = 0; i < NUM_FAKE_PLATFORMS_FRONT; i++) {
                    fakePlatformsFront[i].draw();
                    }


                    // RENDER UI TEXT
                    DrawText("Press O to enter EASY MODE", camera.target.x-700, camera.target.y+250, 20, GRAY);
                    DrawText("Press P to Mute/Unmute | Press TAB to change song | A/D is move | SHIFT is Jump/Boot | C changes camera | Arrow Keys control camera", camera.target.x-700, camera.target.y+350, 20, GRAY);
                    
                    DrawText(
                        TextFormat("Current Height: %.2f", player.getCurrentHeight()),
                        camera.target.x+300, camera.target.y+300, 30, GRAY
                    );

                    DrawText(
                        TextFormat("Top Height: %.2f", player.getTopHeight()),
                        camera.target.x+300, camera.target.y+200, 30, GRAY
                    );

                    /*
                    DrawText(
                        TextFormat("y: %.2f", player.getPosition().y),
                        camera.target.x+300, camera.target.y+100, 30, GRAY
                    );
                    */

                    EndMode2D();                    
                    break;





            }
              
            DrawFPS(camera.target.x-700, camera.target.y+350);
            
        EndDrawing();
        
    }

    // De-Initialization

    UnloadMusicStream(songs[currentSong]);
    CloseAudioDevice();

    CloseWindow();        
    

    return 0;
}

