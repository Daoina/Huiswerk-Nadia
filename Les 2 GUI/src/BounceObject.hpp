//
//  BounceObject.hpp
//  Les 2 GUI
//
//  Created by Nadia Groenewald on 18/09/16.
//
//

#pragma once

#include <stdio.h>
#include "ofMain.h"

class BounceObject
{
public:
    BounceObject();
    
    void setup();
    void draw();
    void update();
    
    ofColor Kleurbal;
    ofPoint position;
    ofVec2f speed;
    int radius;
    
};