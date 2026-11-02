#include "platform.h"


// get
Rectangle Platform::getBottomWall(){
    
    return bottomWall;
}

Rectangle Platform::getLeftWall(){
    return leftWall;
}

Rectangle Platform::getRightWall(){
    return rightWall;
}

Vector2 Platform::getPosition(){
    return position;

}


// set
void Platform::setBottomWall(Rectangle inputWall){
    bottomWall = inputWall;
}

void Platform::setLeftWall(Rectangle inputWall){
    leftWall = inputWall;
}

void Platform::setRightWall(Rectangle inputWall){
    rightWall = inputWall;
}



/*
void Platform::setPosition(Vector2 inputPos){
    position = inputPos;
    wall.x = position.x;
    wall.y = position.y;


}
*/

Vector2 Platform::checkWallColl(Rectangle playerRec, Vector2 playerPosition){
    if(CheckCollisionRecs(bottomWall, playerRec)){
        playerPosition.y = bottomWall.y - playerRec.height;
    }
    if(CheckCollisionRecs(leftWall, playerRec)){
        playerPosition.x = leftWall.x + leftWall.width;
    }
    if(CheckCollisionRecs(rightWall, playerRec)){
        playerPosition.x = rightWall.x-playerRec.width;
    }
    return playerPosition;
}