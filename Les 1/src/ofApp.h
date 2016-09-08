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
    float xrect;
    float yrect;
    float xtri;
    float ytri;
    float speedx;
    float speedy;
    float speedxrect;
    float speedyrect;
    float speedxtri;
    float speedytri;
    int radius;
    ofColor color;
    
};