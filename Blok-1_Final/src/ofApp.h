#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
    
public:
    void setup();
    
    void update();
    
    void draw();
    
    void keyPressed(int key);
    
private:
    
    ofArduino arduino;
    
    void setupArduino(const int& version);
    
    void digitalPinChanged(const int& pin);
    
    bool open;
    
    void analogPinChanged(const int& pin);
};