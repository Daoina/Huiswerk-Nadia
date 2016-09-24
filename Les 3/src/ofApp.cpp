#include "ofApp.h"


void ofApp::setup(){
    ofAddListener(arduino.EInitialized,
                  this,
                  &ofApp::setupArduino);
    arduino.connect("/dev/cu.usbmodem1411");
    arduino.sendFirmwareVersionRequest();

}

void ofApp::update(){
    arduino.update();

}

void ofApp::draw(){

}

void ofApp::setupArduino(const int& version){
    ofLogNotice()<<"arduino klaar!"<< endl;
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    ofLogNotice() <<"arduino firmware" << arduino.getMajorFirmwareVersion() << "." <<arduino.getMajorFirmwareVersion() << endl;
    
    arduino.sendDigitalPinMode(12, ARD_OUTPUT);
    
}

void ofApp::digitalPinChanged(const int& pinNum){
    
}

void ofApp::analogPinChanged(const int& pinNum){
                                  
}
