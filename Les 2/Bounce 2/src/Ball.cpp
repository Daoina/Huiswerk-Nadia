#include "Ball.hpp"

void Ball::setup(){
    x = ofRandom(0,ofGetWidth());
    y = ofRandom(0,ofGetHeight());
    
    speedX = ofRandom(-10,10);
    speedY = ofRandom(-10,10);
    
    radius = 20;
    
    colour.set(ofRandom(255),
              ofRandom(255),
              ofRandom(255));
}

void Ball::update(){
    if (x<0){
        x=0;
        speedX *=-1;
    
    }else if (x>ofGetWidth()){
        x=ofGetWidth();
        speedX *=-1;
    }
    
    if (y<0){
        y=0;
        speedY *=-1;
        
    }else if (x>ofGetHeight()){
        y=ofGetHeight();
        speedY *=-1;
    }
    
    x += speedX;
    y += speedY;
}

void Ball::draw(){
    ofSetColor(colour);
    ofDrawCircle(x, y, radius);
    
}