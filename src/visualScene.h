//
//  visualScene.h
//  UniversalVisualSequencer
//
//  Created by Admin Mac on 12/07/2022.
//

#ifndef visualScene_h
#define visualScene_h

#include "ofMain.h"

class VisualScene {
    int param[8];
    
    
    
public:
    virtual void setup() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    //State . Starting, increasing, constant, decreasing, dying. Un peu comme une courbe adsr
    int currentState;
    const string name;
    
    enum state{ INCREASE=0, CONSTANT, DECREASE, DIE};
    
    
    
};


#endif /* visualScene_h */
