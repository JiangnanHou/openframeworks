#include "ofApp.h"
#include "ofxJSON.h"

#include <time.h>

ofxJSONElement root;
float temp;
float windSpeed;
int sunset;
int sunrise;
float pressure;
std::ostringstream text;
float speed;
int current;
int x;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(50);
   
    std::string url = "https://api.darksky.net/forecast/YOUR_KEY/42.3601,-71.0589";
    
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
    pressure = root["currently"]["pressure"].asFloat();
    
    ofColor color1(ofMap(temp,0,100,0,255),0,0);
    x = ofMap(current, 1585195200, sunrise, 100, ofGetWidth()-100);
    
    gui.setup();
       gui.add(speed.setup("speed", windSpeed*0.1, 0, 3));
       gui.add(xloc.setup("x", x, 100, ofGetWidth()-100));
       gui.add(color.setup("color", color1, ofColor(0, 0), ofColor(255, 255)));
    gui.add(radius.setup("radius", pressure*0.1, 0, 300));
       

}

//--------------------------------------------------------------
void ofApp::update(){
    
}




//--------------------------------------------------------------
void ofApp::draw(){
    current = time(NULL);  // get current epoch
    temp = root["currently"]["temperature"].asFloat();
    windSpeed = root["currently"]["windSpeed"].asFloat();
    sunset = root["daily"]["data"][0]["sunsetTime"].asInt();
    sunrise = root["daily"]["data"][0]["sunriseTime"].asInt();
    pressure = root["currently"]["pressure"].asFloat();
    
    std::string currentTime = "Current epoch time is " + ofToString(current) + ".";
    std::string normalTime = "Day " + ofToString((current/60/60/24) % 365) + " of the year, " + ofToString((current/60/60-4) % 24) + " hours, " + ofToString((current/60)%60) + " minutes.";
 
    if(ofGetFrameNum()==1){
        text<<"The temperature is "<<temp<<"."<<endl
        <<"The wind speed is "<<windSpeed<<"."<<endl
        <<"The pressure is "<<pressure<<"."<<endl
        <<"The sunset time today is "<<sunset<<"."<<endl
        <<"The sunrise time today is "<<sunrise<<".";
    }

    ofSetBackgroundColor(0);
    
    ofSetColor(200);
    ofDrawBitmapString(currentTime,20,ofGetHeight()-140);
    ofDrawBitmapString(normalTime,20,ofGetHeight()-110);
    ofDrawBitmapString(text.str(),20,ofGetHeight()-80);
    
    ofVec2f center1(0,0), planet, orbit;
    planet = center1 + ofVec2f(0,radius);
    
    ofSetColor(color);
    ofNoFill();
    ofSetLineWidth(5);
    
    ofPushMatrix();
    ofTranslate(xloc,0);
    ofRotateYDeg(ofGetFrameNum()*speed);
       ofRotateXDeg(60);
    ofDrawCircle(center1.x,center1.y,-250, radius);
    ofDrawLine(center1.x,center1.y,-250,center1.x,center1.y,0);
    for(int i =0; i<360; i+=10){
        orbit = planet.rotate(i, center1);
  ofDrawLine(orbit.x,orbit.y,-250,orbit.x+ofRandom(-10,10),orbit.y+ofRandom(-10,10),-550);

    }

    ofPopMatrix();
    

    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
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


