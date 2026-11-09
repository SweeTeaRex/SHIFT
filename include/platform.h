#pragma once
#include "raylib.h"

class Platform {
    private:
    Vector2 position;
    Rectangle wall;
    /*
    Rectangle bottomWall;
    Rectangle leftWall;
    Rectangle rightWall;
    */
    
    public:
    // get
    Rectangle getWall();
    /*
    Rectangle getLeftWall();
    Rectangle getRightWall();
    */
    Vector2 getPosition();
    // set
    void setWall(Rectangle inputWall);
    /*
    void setLeftWall(Rectangle inputWall);
    void setRightWall(Rectangle inputWall);
    */
    void setPosition(Vector2 inputPos);
    // check
    Vector2 checkWallCollBottom(Rectangle playerRec, Rectangle bottomWall);

    Vector2 checkWallCollLeft(Rectangle playerRec, Rectangle leftWall);
    Vector2 checkWallCollRight(Rectangle playerRec, Rectangle rightWall);

    Vector2 checkWallCollPlatformA(Rectangle playerRec, Rectangle platA);
    
};