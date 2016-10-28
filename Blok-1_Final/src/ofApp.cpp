#include "ofApp.h"

#define PIN_BUTTON 11
#define PIN_LDR 0
#define PIN_SERVO 9

void ofApp::setup() {
    
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    arduino.connect("/dev/cu.usbmodem1411");
    arduino.sendFirmwareVersionRequest();
}

void ofApp::update() {
    arduino.update();
}

void ofApp::draw(){
}


void ofApp::keyPressed(int key){
}


void ofApp::setupArduino(const int& version) {
    ofLogNotice() << "Arduino initialized" << endl;
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
    arduino.sendServoAttach(9);
    
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pin){
    ofLog() << "Digital pin" << pin << " changed to " << arduino.getDigital(pin) << endl;
    if(arduino.getDigital(pin) == 1)
    {
//    Checkt de status van de push button, als die true is gaat hij 90 graden draaien
        if(open){ofLog()<<"Servo was open, gaat nu dicht"<< endl;
            open=false;
            arduino.sendServo(9, 90);
        
//            Als de knop wordt ingedrukt draait hij terug naar 0 graden.
        }
        else{ofLog()<<"Servo was dicht, gaat nu open"<< endl;
            open=true;
            arduino.sendServo(9, 0);
        }}
}

void ofApp::analogPinChanged(const int& pin){
    ofLog() << "Analog pin" << pin << " changed to " << arduino.getAnalog(pin) << endl;
        }