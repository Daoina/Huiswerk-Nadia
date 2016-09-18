//
//  Ball.hpp
//  Bounce 2
//
//  Created by Nadia Groenewald on 12/09/16.
//
//

#pragma once
#include "ofMain.h"

class Ball {
    public:
    void setup();
    void update();
    void draw();
    
    float x;
    float y;
    float speedX;
    float speedY;
    int radius;
    ofColor colour;
    
};
