//
//  vibratingCircle.hpp
//  UniversalVisualSequencer
//
//  Created by Admin Mac on 12/07/2022.
//

#ifndef vibratingCircle_hpp
#define vibratingCircle_hpp

#include <stdio.h>
#include "visualScene.h"

class VibratingCircle : public VisualScene {

private:
    int finalRadius;
    int currentRadius;
    int vibrationAmplitude;
    int duration;
    int currentDuration;
    float noise;
    void updateState();
    
    
public:
    
    VibratingCircle(int, int, int, int, int, int, int, int);
    void setup();
    void update();
    void draw();
    
};

#endif /* vibratingCircle_hpp */
