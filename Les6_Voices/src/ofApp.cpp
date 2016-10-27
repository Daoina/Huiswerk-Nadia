#include "ofApp.h"


void ofApp::setup(){
    for (int i = 0; i < VOICES; ++i){
        voicePlayer[i].load("voice"+ofToString(i+1)+".wav");
        voicePlayer[i].setLoop(true);
        voicePlayer[i].setPaused(true);
        voicePlayer[i].play();
    }
    
    ofSoundSetVolume(0.2);

}

void ofApp::update(){
    ofSoundUpdate();
}

void ofApp::draw(){

}

void ofApp::keyPressed(int key){
    if (key=='1') {
        voicePlayer[0]
    }


}


if (key=='1'){
    if (voicePlayer[0].isPlaying()){
        voicePlayer[0].setPaused(true);
    } else{
        voicePlayer[0].setPaused(false);
        voicePlayer[0].play();
    }
} else if (key=='2'){
    
}