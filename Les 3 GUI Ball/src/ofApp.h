#pragma once

#include "ofMain.h"
#include "Ball.hpp"
#include "ofxGui.h"


#define MAXBALLS 15

class ofApp : public ofBaseApp {
    
public:
    void setup();
    
    void update();
    
    void draw();
    
    void keyPressed(int key);
    
    void mousePressed(int x, int y, int button);
    
    Ball ball[MAXBALLS];
    
    ofxPanel gui;
    ofParameter<int> startradius;
    
    int Walker;
};
