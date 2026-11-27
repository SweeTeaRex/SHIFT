#include "fakeplatform.h"
#include "gameData.h"

void FakePlatform::setShape(ShapeType inputShape){
    shape = inputShape;
}

void FakePlatform::setPosition(Vector2 inputPosition){
    position = inputPosition;
}

void FakePlatform::setSize(float inputWidth, float inputHeight){
    width = inputWidth;
    height = inputHeight;
}

void FakePlatform::draw() {
        switch (shape) {

            case RECTANGLE:
                DrawRectangle(
                    position.x,
                    position.y,
                    width,
                    height,
                    BLACK
                );
                break;

            case CIRCLE:
                DrawCircle(
                    position.x,
                    position.y,
                    width,
                    BLACK
                );
                break;

            case ELLIPSE:
                DrawEllipse(
                    position.x,
                    position.y,
                    width,
                    height,
                    BLACK
                );
                break;

            case TRIANGLE:
                DrawTriangle(
                    {position.x, position.y},
                    {position.x + width, position.y},
                    {position.x + width / 2, position.y - height},
                    BLACK
                );
                break;
        }
    }