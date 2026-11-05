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


Vector2 Platform::checkWallColl(Rectangle playerRec, Vector2 playerPosition){
    
}
