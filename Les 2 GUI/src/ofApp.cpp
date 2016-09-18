#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i=0; i < AANTALBALLEN; i++)
    {
        Ball[i].setup();
    }
    gui.setup("Instellingen", "settings.xml");
    gui.add(count.set("Count",50,0,200));
    gui.add(speedX.set("speedX",20,0,200));
    gui.add(speedY.set("speedY",20,0,200));
}

void ofApp::update(){
    ofBackground(0, 0, 0);
    for(int i=0; i <= Walker; i++)
    {
        Ball[i].update();
    }
}

void ofApp::draw(){
    gui.draw();
    for(int i=0; i<= Walker; i++)
    {
        Ball[i].draw();
    }
    

}

void ofApp::keyPressed(int key){
    if (key== ' '){
        Walker--;
    }
}



void ofApp::mousePressed(int x, int y, int button){
    if (button == 0){
        Walker++;
    }
}
