#include "ofApp.h"
#include "Ball.hpp"

Ball ball;

void ofApp::setup() {
    for(int i=0; i < MAXBALLS; i++)
    {
        ball[i].setup();
    }

    gui.setup("Instellingen", "settings.xml");
    gui.add(startradius.set("Radius",50,0,200));
   
}

void ofApp::update() {
    ball.update();
    for(int i=0; i <= Walker; i++)
    {
        Ball[i].update();
    }
    if (ball.radius!=startradius){
        ball.radius = startradius;
    }
}

void ofApp::draw() {
    gui.draw();
    for(int i=0; i<= Walker; i++)
    {
        ball[i].draw();
    }
}

void ofApp::keyPressed(int key){
    if (key== ' '){
        Walker--;
        ball.setup(ofRandom(ofGetWidth()),
                   ofRandom(ofGetHeight()),
                   startradius);

    }
}

void ofApp::mousePressed(int x, int y, int button){
    if (button == 0){
        Walker++;
    }
}