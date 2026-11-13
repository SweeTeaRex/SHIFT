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
float Player::getVelocity() const{
    return velocity;
}
float Player::getVelocityY() {
    return velocityY;
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
void Player::setVelocityY(float inputVelocity){
    velocity = inputVelocity;
}

void Player::setGrounded(bool inputGrounded){
    isGrounded = inputGrounded;
}


// UPDATE FUNCTIONS
void Player::updatePlayer(float deltaTime){
    
    GRAVITY = 100.0f;
    
    velocityY += GRAVITY * deltaTime;
    position.y += velocityY * deltaTime;

    //jump
    if(IsKeyPressed(KEY_LEFT_SHIFT)&& isGrounded){
        velocityY = -JUMP_SPEED;
        isGrounded=false;
    }
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