#include "platform.h"


// get
Rectangle Platform::getWall(){
    
    return wall;
}
/*
Rectangle Platform::getLeftWall(){
    return leftWall;
}

Rectangle Platform::getRightWall(){
    return rightWall;
}
*/
Vector2 Platform::getPosition(){
    return position;

}


// set

void Platform::setWall(Rectangle inputWall){
    wall = inputWall;
}
/*
void Platform::setLeftWall(Rectangle inputWall){
    leftWall = inputWall;
}

void Platform::setRightWall(Rectangle inputWall){
    rightWall = inputWall;
}
*/



void Platform::setPosition(Vector2 inputPos){
    position = inputPos;
    wall.x = position.x;
    wall.y = position.y;


}

// Collision Funcs
Vector2 Platform::checkWallCollBottom(Rectangle playerRec, Rectangle bottomWall){
    Vector2 playerPosition = {playerRec.x, playerRec.y};
    if(CheckCollisionRecs(playerRec, bottomWall)){
            playerPosition.y = bottomWall.y - playerRec.height;
    }
    return playerPosition;

    
}

Vector2 Platform::checkWallCollLeft(Rectangle playerRec, Rectangle leftWall){
    Vector2 playerPosition = {playerRec.x, playerRec.y};
    if(CheckCollisionRecs(playerRec, leftWall)){
        playerPosition.x = leftWall.x + leftWall.width;
    }
    return playerPosition;
}

Vector2 Platform::checkWallCollRight(Rectangle playerRec, Rectangle rightWall){
    Vector2 playerPosition = {playerRec.x, playerRec.y};
    if(CheckCollisionRecs(playerRec, rightWall)){
        playerPosition.x = rightWall.x - playerRec.width;
    }
    return playerPosition;
}