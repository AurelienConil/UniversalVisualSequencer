//  rotatingSquare.hpp
//  UniversalVisualSequencer
//
//  Created by Admin Mac on 12/07/2022.
//

#ifndef rotatingSquare_hpp
#define rotatingSquare_hpp

#include <stdio.h>
#include "visualScene.h"

class RotatingSquare : public VisualScene {

private:
    double currentAngle;
    int rotatingSpeed;
    int thickness;
    float size;
    float growingSpeed;
    void updateState();
    
    
public:
    
    RotatingSquare(int, int, int, int, int, int, int, int);
    void setup();
    void update();
    void draw();
    
};

#endif /* vibratingCircle_hpp */
