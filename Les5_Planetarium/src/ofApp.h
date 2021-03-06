#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Planet.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
    
    ofxPanel gui;
    ofParameterGroup params;
    
    ofEasyCam cam;
    ofLight light;
    
    Planet planet01;
    Planet planet02;
    
    bool drawGrid;
    bool drawLight;
    
};
