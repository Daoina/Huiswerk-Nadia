//
//  BounceObject.cpp
//  Les 2 GUI
//
//  Created by Nadia Groenewald on 18/09/16.
//
//

#include "BounceObject.hpp"

BounceObject::BounceObject()
{
    
}

void BounceObject::setup()
{
    Kleurbal = ofColor(234,43,92);
    position = ofPoint(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
    speed = ofVec2f(ofRandom(-5,5), (ofRandom(-5,5)));
    radius = 100;
}

void BounceObject::update()
{
    if (position.x <= 0) {
        position.x = 0;
        speed.x = -speed.x;
    }
    else if (position.x >= ofGetWidth()) {
        position.x = ofGetWidth();
        speed.x = -speed.x;
    }
    
    if (position.y <= 0) {
        position.y = 0;
        speed.y = -speed.y;
    }
    else if (position.y >= ofGetHeight()) {
        position.y = ofGetHeight();
        speed.y = -speed.y;
    }
    
    position.x += speed.x;
    position.y += speed.y;}

void BounceObject::draw()
{
    ofSetColor(Kleurbal);
    ofDrawCircle(position, radius);
}