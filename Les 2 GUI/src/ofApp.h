#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "BounceObject.hpp"

#define AANTALBALLEN 100

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    
    BounceObject Ball[AANTALBALLEN];
    ofxPanel gui;
    ofParameter<int> count;
    ofParameter <float> speedX;
    ofParameter <float> speedY;
    
    int Walker;
    
};