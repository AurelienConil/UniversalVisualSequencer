// This is rotatingSquare class
// This class is a child of VisualScene class
//  this class consist in drawing a rotating square, thats grows slowly.
//  the square start from the center of the screen and grows.

#include "rotatingSquare.hpp"

RotatingSquare::RotatingSquare(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
{

    // final radius does not exist is this class
    // this is rotatingsquare class
    currentAngle = p1 * 2;
    size = p2;
    setup();
}

// define setup
void RotatingSquare::setup()
{

    rotatingSpeed = ofRandom(-3, 3);
    // degree/sec
    thickness = 1;

    growingSpeed = ofRandom(5); // pixel/sec

    // currentState in increase
    currentState = INCREASE;
}

// define update
void RotatingSquare::update()
{

    switch (currentState)
    {
    case INCREASE:
        // update the current angle
        // currentAngle += rotatingSpeed;
        currentAngle += rotatingSpeed;
        // update the current size
        size += growingSpeed;

        break;

    default:
        break;
    }

    updateState();
}

// define updateState
void RotatingSquare::updateState()
{

    switch (currentState)
    {
    case INCREASE:
        // if the size if bigger than the screen, currentState go to DIE
        if (size > ofGetWidth())
        {
            currentState = DIE;
        }
        break;

    default:
        break;
    }
}

// define draw
void RotatingSquare::draw()
{

    // draw a white square
    ofSetColor(255, 255, 255);
    // set thickness according to the current thickness
    ofSetLineWidth(thickness);
    ofNoFill();
    // rotate
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateZDeg(currentAngle);
    // draw a square
    ofDrawRectangle(-size / 2, -size / 2, size, size);

    ofPopMatrix();
}
