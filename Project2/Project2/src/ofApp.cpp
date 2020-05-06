#include "ofApp.h"
#include "ofxJSON.h"

#include <time.h>

ofxJSONElement root;
float temp;
float windSpeed;
int sunset;
int sunrise;
float humidity;
std::ostringstream text;
float speed;
int current;
int x;
float c1,c2;
ofColor color1;
bool guiDraw;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(50);
    
    //true type setup
    ofTrueTypeFontSettings settings("CJH.ttf", 30);
    settings.addRanges(ofAlphabet::Chinese);
    myFont.load(settings);
    
    //json setup
    std::string url = "https://api.darksky.net/forecast/280d7b7bd1eff171e93a4ab8586c4b5f/42.3601,-71.0589";
    
    // Now parse the JSON
    bool parsingSuccessful = root.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << root.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    current = time(NULL);
    temp = root["currently"]["temperature"].asFloat();
    windSpeed = root["currently"]["windSpeed"].asFloat();
    sunset = root["daily"]["data"][0]["sunsetTime"].asInt();
    sunrise = root["daily"]["data"][0]["sunriseTime"].asInt();
    humidity = root["currently"]["humidity"].asFloat();
    
    gui.setup();
    gui.add(speed.setup("speed", windSpeed, 0, 70));
    gui.add(textChange.setup("text", current, sunrise-3600*6, sunset+3600*4.5));
    gui.add(tempChange.setup("temp", temp,30,90));
    gui.add(height.setup("height", humidity, 0, 1));
    
    ofSetSmoothLighting(true);
    
   
    
    
    
    cone.set(100, 200);
    cone.setResolution(40, 9, 3);
    sphere.setParent(cone);
    sphere.move(0,-250,0);
    cylinder.set(4, 200);
    cylinder.setParent(cone);
    cylinder.move(0,-160,0);
    // shininess is a value between 0 - 128, 128 being the most shiny
    material.setShininess(20 );
    material.setDiffuseColor(ofFloatColor(1,1,1));
    mat2.setShininess(20);
    mat2.setDiffuseColor(ofFloatColor(0.2,0.9,0.2));
    mesh.load("spiral.ply");
    
    //polyline setup
    for(int i =-1000; i<=1000; i+=100){
        spring.curveTo(-ofGetWidth()/2,i,-3500);
        spring.curveTo(0,i-50,-3500);
        spring.curveTo(ofGetWidth()/2,i,-3500);
        spring.curveTo(0,i+100,-3500);
    }
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
}




//--------------------------------------------------------------
void ofApp::draw(){
    color1 = ofColor(tempChange*2.8,180-tempChange*0.5,255-tempChange);

    if(textChange<sunrise || textChange > sunset){
        ofBackgroundGradient(ofColor(0), color1);
        ofSetColor(255);
        myFont.drawString("月朦胧", ofGetWidth()/2-myFont.stringWidth("月朦胧")/2,ofGetHeight()-50);
    }
    else{
        ofBackgroundGradient(ofColor(255), color1);
        ofSetColor(0);
        myFont.drawString("风日好", ofGetWidth()/2-myFont.stringWidth("风日好")/2,ofGetHeight()-50);
    }

    //polyline
    ofPushMatrix();
    float step = ofMap(sin(ofGetElapsedTimef()*2),-1,1,-0.02,0.02);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(1*7, (1.5-height+step)*7);
    ofSetColor(255);
    spring.draw();
    ofPopMatrix();
    
    //lights
    //front top
       pointLight.setPosition(ofGetWidth()*.5, ofGetHeight()/2+200,0);
       pointLight.setDiffuseColor( ofFloatColor(1, tempChange/68, 0.6) );
       //left
       pointLight2.setPosition(-ofGetWidth()/2-200, 200,500);
       pointLight2.setDiffuseColor( ofFloatColor(tempChange/68-0.2, tempChange/68-0.5, 1.2-tempChange/68) );
       //right
       pointLight3.setPosition(ofGetWidth()/2+200, 200,500);
       pointLight3.setDiffuseColor( ofFloatColor(1-tempChange/68, tempChange/108-0.5, 1.5-tempChange/68) );
    //bottom
    pointLight4.setPosition(0, -400,0);
          pointLight4.setDiffuseColor( ofFloatColor(1,1,1) );
    
    //3D
    cam.begin();
    
    ofEnableDepthTest();
    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();
    pointLight4.enable();
    //cone
    ofPushMatrix();
    ofTranslate(0, 50);
    ofRotateXDeg(ofMap(sin(ofGetElapsedTimef()/speed*10),-1,1,-30,30));
    ofRotateYDeg(speed*5*ofGetElapsedTimef());
    ofRotateXDeg(ofMap(sin(ofGetElapsedTimef()/speed*10),-1,1,30,-30));
    //cone.rotateDeg(speed, 0.5, 0, 0);
    material.begin();
    ofFill();
    ofPushMatrix();
    cone.draw();
    ofRotateZDeg(30);
    cone.draw();
    ofRotateZDeg(-60);
    cone.draw();
    ofPopMatrix();
    material.end();
    
    mat2.begin();
    cylinder.draw();
    sphere.draw();
    mat2.end();
    
    ofPopMatrix();
    
    ofDisableLighting();
    cam.end();
    
    current = time(NULL);
    temp = root["currently"]["temperature"].asFloat();
    windSpeed = root["currently"]["windSpeed"].asFloat();
    sunset = root["daily"]["data"][0]["sunsetTime"].asInt();
    sunrise = root["daily"]["data"][0]["sunriseTime"].asInt();
    humidity = root["currently"]["humidity"].asFloat();
    
    
    if(guiDraw == true){
    gui.draw();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g'){
        guiDraw =! guiDraw;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}


