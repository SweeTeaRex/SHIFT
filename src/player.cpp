#include "player.h"
#include "gameData.h"
#include "platform.h"

// GET FUNCTIONS
Rectangle Player::getOutBox() const{
        return outBox;
    }
Rectangle Player::getInBox() const{
        return inBox;
    }
Vector2 Player::getPosition()const{
    return position;
}
float Player::getSpeed() const{
    return speed;
}
// SET FUNCTIONS
void Player::setOutBox(Rectangle inputBox){
    outBox = inputBox;
}
void Player::setInBox(Rectangle inputBox){
    inBox = inputBox;
}
void Player::setPosition(Vector2 inputPos){
    position = inputPos;
    outBox.x = position.x;
    outBox.y = position.y;
    inBox.x = position.x;
    inBox.y = position.y;
}
void Player::setSpeed(float inputSpeed){
    speed = inputSpeed;
}
// UPDATE FUNCTIONS
void Player::updatePlayer(float deltaTime){
    
    GRAVITY = 100.0f;
    
    velocityY += GRAVITY * deltaTime;
    position.y += velocityY * deltaTime;
    //left
    if(IsKeyDown(KEY_LEFT_SHIFT)&&IsKeyDown(KEY_A)){
        position.x -= PLAYER_SPEED2*deltaTime;
    }
    else if(IsKeyDown(KEY_A)){
        position.x -= PLAYER_SPEED1*deltaTime;
    }
    //right
   
    if(IsKeyDown(KEY_LEFT_SHIFT)&&IsKeyDown(KEY_D)){
        position.x += PLAYER_SPEED2*deltaTime;
    }
    else if(IsKeyDown(KEY_D)){
        position.x += PLAYER_SPEED1*deltaTime;
    }
    // down
    
    if(IsKeyDown(KEY_S) && IsKeyDown(KEY_LEFT_SHIFT)){
        position.y += PLAYER_SPEED2*deltaTime;
    }
    /*
    else if(IsKeyDown(KEY_S)){
        position.y += PLAYER_SPEED1*deltaTime;
    }
    // up
    
    if(IsKeyDown(KEY_W) && IsKeyDown(KEY_LEFT_SHIFT)){
        position.y -= PLAYER_SPEED2*deltaTime;
    }
    else if(IsKeyDown(KEY_W)){
        position.y -= PLAYER_SPEED1*deltaTime;
    }
    */
    
    
    
    outBox.x = position.x;
    inBox.x= position.x;
    outBox.y = position.y;
    inBox.y = position.y;


    
}