#pragma once
#include "raylib.h"

class Player {
    private:
    Rectangle outBox;
    Rectangle inBox;
    Vector2 position;
    float speed;
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
    void setSpeed(float inputSpeed);
    // update
    void updatePlayer(float deltaTime);
};