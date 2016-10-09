#include "ofApp.h"

#define PIN_BUTTON 11
#define PIN_POTMETER 1
#define PIN_LDR 0

void ofApp::setup() {
    gui.setup("Instellingen", "settings.xml");
    gui.add(radius.set("Radius", 0, 0, 1024));
    gui.add(speedX.set("SpeedX", 5, 5, 30));
    gui.add(speedY.set("SpeedY", 5, 5, 30));
    gui.add(colour.set("Colour", ofColor::blue));
    
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    arduino.connect("/dev/cu.usbmodem1411");
    arduino.sendFirmwareVersionRequest();
}

void ofApp::update() {
    arduino.update();
    for (unsigned int i = 0; i < balls.size(); i++) {
        balls[i].update();
    }
}

void ofApp::draw() {
    gui.draw();
    
    for (unsigned int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
}

void ofApp::keyPressed(int key) {
   
}

void ofApp::mousePressed(int x, int y, int button) {
    if (balls.size() > 0) {
        balls.pop_back();
    }
}

void ofApp::setupArduino(const int& version) {
    ofLogNotice() << "Arduino initialized" << endl;
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
    arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);
    arduino.sendAnalogPinReporting(PIN_LDR, ARD_ANALOG);
    
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pin){
    ofLog() << "Digital pin" << pin << " changed to " << arduino.getDigital(pin) << endl;
    if(arduino.getDigital(pin) == 1)
    {
        Ball newBall;
        newBall.setup(speedX, speedY, radius, colour);
        balls.push_back(newBall);
    }
}

void ofApp::analogPinChanged(const int& pin){
    ofLog() << "Analog pin" << pin << " changed to " << arduino.getAnalog(pin) << endl;
    radius = arduino.getAnalog(pin);
    for (unsigned int i = 0; i < balls.size(); i++) {
        if (radius != balls[i].radius) {
            balls[i].radius = radius;
        }
    }}