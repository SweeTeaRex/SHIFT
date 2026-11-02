#pragma once
#include "raylib.h"

class Platform {
    private:
    Rectangle bottomWall;
    Rectangle leftWall;
    Rectangle rightWall;

    Vector2 position;
    
    public:
    // get
    Rectangle getBottomWall();
    
    Rectangle getLeftWall();
    Rectangle getRightWall();
    
    Vector2 getPosition();
    // set
    void setBottomWall(Rectangle inputWall);
    void setLeftWall(Rectangle inputWall);
    void setRightWall(Rectangle inputWall);
    void setPosition(Vector2 inputPos);
    // check
    Vector2 checkWallColl(Rectangle playerRec, Vector2 playerPosition);
    
};