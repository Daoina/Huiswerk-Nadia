#include "ofApp.h"


void ofApp::setup(){
    x = ofRandom(0,ofGetWidth());
    y = ofRandom(0,ofGetHeight());
    
    speedx = ofRandom(-10, 10);
    speedy = ofRandom(-10, 10);
    
    radius = 40;
}

void ofApp::update(){
    if(x<=0){
        x=0;
        speedx=-speedx;
    } else if (x>=ofGetWidth()){
        x= ofGetWidth();
        speedx=-speedx;
    }
    
    if(y<=0){
        y=0;
        speedy=-speedy;
    } else if (y>=ofGetHeight()){
        y= ofGetHeight();
        speedy=-speedy;
    }
    
        
    x+=speedx;
    y+=speedy;
}

void ofApp::draw(){
    ofSetColor(ofColor::indianRed);
    ofSetBackgroundColor(0, 0, 0);
    ofDrawCircle(x,y,radius);
}

void ofApp::keyPressed(int key){
}