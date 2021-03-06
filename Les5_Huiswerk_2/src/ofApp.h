#pragma once

#include "ofMain.h"
#include "Ball.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
    
public:
    void setup();
    
    void update();
    
    void draw();
    
    void keyPressed(int key);
    
    void mousePressed(int x, int y, int button);
    
    ofxPanel gui;
    ofParameterGroup params;
    
    ofEasyCam cam;
    ofLight light;
    
    bool drawGrid;
    bool drawLight;
    
private:
    vector<Ball> balls;
    
    //    ofxPanel gui;
    ofParameter<int> radius;
    ofParameter<int> speedX;
    ofParameter<int> speedY;
    ofParameter<ofColor> colour;
    
    ofArduino arduino;
    
    void setupArduino(const int& version);
    
    void digitalPinChanged(const int& pin);
    
    void analogPinChanged(const int& pin);
};