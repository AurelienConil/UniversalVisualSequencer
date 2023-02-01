//
//  vibratingCircle.cpp
//  UniversalVisualSequencer
//
//  Created by Admin Mac on 12/07/2022.
//

#include "vibratingCircle.hpp"

VibratingCircle::VibratingCircle(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8){
    
    finalRadius = p1;
    vibrationAmplitude = p2;
    duration = p3;

    
    setup();
}



//-----------------------------------------------------
void VibratingCircle::setup(){
    
    currentRadius = 0;
    currentDuration = 0;
    
    currentState = INCREASE;
    
    
}

//-----------------------------------------------------
void VibratingCircle::update(){
    
    switch (currentState) {
        case INCREASE:
            currentRadius++;;
            currentDuration++;
            break;
        case CONSTANT:
            currentDuration++;
            break;
        case DECREASE:
            currentRadius--;
            currentDuration++;
            break;
            
        default:
            break;
    }
    
    updateState();
    
}


//-----------------------------------------------------
void VibratingCircle::updateState(){
    
    switch (currentState) {
        case INCREASE:
            if(currentRadius>=finalRadius){
                currentState = CONSTANT;
            }
            break;
        case CONSTANT:
            if(currentDuration>=duration){
                currentState = DECREASE;
            }
            break;
        case DECREASE:
            if(currentRadius<= 0){
                currentState = DIE;
            }
            break;
            
        default:
            break;
    }
    
    
    
}



//-----------------------------------------------------
void VibratingCircle::draw(){
    
    ofNoFill();
    ofSetColor(255);
    int r = currentRadius + ofNoise(duration)*vibrationAmplitude;
    ofSetLineWidth(2);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, r);
    
}


//-----------------------------------------------------


//-----------------------------------------------------


//-----------------------------------------------------


