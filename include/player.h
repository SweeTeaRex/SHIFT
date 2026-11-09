#pragma once
#include "raylib.h"
#include "platform.h"

class Player {
    private:
    Rectangle outBox;
    Rectangle inBox;
    Vector2 position;
    float speed;
    bool isGrounded;
    float GRAVITY;
    float velocityY=0;
    public:
    // get
    Rectangle getOutBox() const;
    Rectangle getInBox() const;
    Vector2 getPosition()const;
    float getSpeed() const;
    //set
    void setOutBox(Rectangle inputBox);
    void setInBox(Rectangle inputBox);
    void setPosition(Vector2 inputPos);
    void setVelocityY(float inputVelocity);
    void setGrounded(bool inputGrounded);
    // update
    void updatePlayer(float deltaTime);
};