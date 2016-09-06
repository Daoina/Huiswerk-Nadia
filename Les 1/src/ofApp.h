#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
    
private:
    float x;
    float y;
    float speedx;
    float speedy;
    int radius;
    ofColor color;
    
};