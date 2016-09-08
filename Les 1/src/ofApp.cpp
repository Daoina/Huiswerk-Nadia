#include "ofApp.h"


void ofApp::setup(){
    x = ofRandom(0,ofGetWidth());
    y = ofRandom(0,ofGetHeight());
    xrect = ofRandom(0,ofGetWidth());
    yrect = ofRandom(0,ofGetHeight());
    xtri = ofRandom(0,ofGetWidth());
    ytri = ofRandom(0,ofGetHeight());
    
    
    speedx = ofRandom(-10, 10);
    speedy = ofRandom(-10, 10);
    
    speedxrect = ofRandom(-10, 10);
    speedyrect = ofRandom(-10, 10);
    
    speedxtri = ofRandom(-10, 10);
    speedytri = ofRandom(-10, 10);
    
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
    
    if(xrect<=0){
        xrect=0;
        speedxrect=-speedxrect;
    } else if (xrect>=ofGetWidth()){
        xrect= ofGetWidth();
        speedxrect=-speedxrect;
    }
    
    if(yrect<=0){
        yrect=0;
        speedyrect=-speedyrect;
    } else if (yrect>=ofGetHeight()){
        yrect= ofGetHeight();
        speedyrect=-speedyrect;
    }
    
    
    xrect+=speedxrect;
    yrect+=speedyrect;
    
    if(xtri<=0){
        xtri=0;
        speedxtri=-speedxtri;
    } else if (xtri>=ofGetWidth()){
        xtri= ofGetWidth();
        speedxtri=-speedxtri;
    }
    
    if(ytri<=0){
        ytri=0;
        speedytri=-speedytri;
    } else if (ytri>=ofGetHeight()){
        ytri= ofGetHeight();
        speedytri=-speedytri;
    }
    
    
    xtri+=speedxtri;
    ytri+=speedytri;
}

void ofApp::draw(){
    ofSetColor(ofColor::indianRed);
    ofSetBackgroundColor(0, 0, 0);
    ofDrawCircle(x,y,radius);
    ofDrawRectangle(xrect,yrect,100,100);
    ofDrawTriangle(xtri,ytri,10,40,90,40);
}

void ofApp::keyPressed(int key){
}