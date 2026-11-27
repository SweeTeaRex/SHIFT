#pragma once
#include "raylib.h"
#include "platform.h"

class Player {
    private:
    Rectangle outBox;
    Rectangle inBox;
    Vector2 position;
    float velocity;
    bool isGrounded = false;
    float GRAVITY;
    float velocityY=0;
    float currentHeight;
    float topHeight;
    
    public:
    // get
    float getCurrentHeight();
    float getTopHeight();
    Rectangle getOutBox() const;
    Rectangle getInBox() const;
    Vector2 getPosition()const;
    float getVelocity() const;
    float getVelocityY();
    //set
    void setOutBox(Rectangle inputBox);
    void setInBox(Rectangle inputBox);
    void setPosition(Vector2 inputPos);
    void setVelocityY(float inputVelocity);
    void setGrounded(bool inputGrounded);
    void setCurrentHeight(float height);
    void setTopHeight(float height);
    // update
    void updatePlayer(float deltaTime);
};