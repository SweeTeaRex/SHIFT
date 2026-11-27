#pragma once
#include "raylib.h"

// fake shapes

enum ShapeType{
    RECTANGLE,
    CIRCLE,
    TRIANGLE,
    ELLIPSE
};

class FakePlatform{
    private:
    ShapeType shape;
    Vector2 position;
    float width;
    float height;

    public:

    void setShape(ShapeType inputShape);
    void setPosition(Vector2 inputPosition);
    void setSize(float inputWidth, float inputHeight);
    void draw();
};