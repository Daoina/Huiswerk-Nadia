#include "ofApp.h"

#define PIN_BUTTON 11
#define PIN_POTMETER 1
#define PIN_LDR 0

void ofApp::setup(){
    ofSetBackgroundColor(ofColor::black);
    
    planet01.setup("planet 1");
    params.add(planet01.planetParameterGroup);
    planet02.setup("planet 2");
    params.add(planet02.planetParameterGroup);
    
    gui.setup(params);
    
    light.setDirectional();
    light.setPosition(-200, -200, -200);
    light.lookAt(ofVec3f(0,0,0), ofVec3f(0,0,0));
    light.setDiffuseColor(ofColor::white);
    light.enable();
    
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    arduino.connect("/dev/cu.usbmodem1411");
    arduino.sendFirmwareVersionRequest();
}


void ofApp::update(){
    arduino.update();
    planet01.update();
    planet02.update();
    
}

void ofApp::draw(){
    gui.draw();
    
    ofEnableDepthTest();
    cam.begin();
    
    if(drawLight) light.draw();
    if (drawGrid) ofDrawGrid(200);
    
    planet01.draw();
    planet02.draw();
    
    cam.end();
    ofDisableDepthTest();
}

void ofApp::keyPressed(int key){
    if (key=='g'){
        drawGrid =!drawGrid;
    } else if (key =='l'){
        drawLight = !drawLight;
    } else if (key == 'k'){
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
        drawGrid =!drawGrid;
//        Planet newPlanet;       Ik snap dat dit niet werkt omdat er handmatige nieuwe planeten moeten worden gemaakt, niet met een key. Maar weet niet hoe ik dit zou moeten oplossen :(
    }
}

void ofApp::analogPinChanged(const int& pin){
    ofLog() << "Analog pin" << pin << " changed to " << arduino.getAnalog(pin) << endl;
//Ik wilde graag de distance zich laten aanpassen als je aan de podmeter draait, maar ik kan sowieso nergens de "distance" vinden dus ik heb geen idee hoe ik dit zou doen o_o Heb het gevoel dat het tussen de params zit? 
}