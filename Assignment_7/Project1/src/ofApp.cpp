#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofSetFrameRate(60);
    fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA32F);
    fbo.begin();
    ofClear(255,255,255);
    fbo.end();
    ofSetCircleResolution(50);
    
    
    Title.init("TrajanPro-Regular.otf", 50);
    Title.setText("Building Zobeide");
    credits.init("TrajanPro-Regular.otf", 12);
    credits.setText("Story: Italo Calvino  Production: Jiangnan Hou");
    ofSetBackgroundColor(0);
    


}

//--------------------------------------------------------------
void ofApp::update(){

}
ofPoint myMouse;
bool toggle=false;
float i =0;
float a = 200;
float offset=0;
float step=0.1;
float speed =0;
//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(myMouse.x,myMouse.y*3);
    //Moon
    ofSetColor(255,255,255);
    ofPoint moon(ofGetWidth()/2, 0);
    ofDrawCircle(moon, 200);
    //Halo
    ofSetColor(255,255,255,a);
    offset+=step;
    if (offset>20||offset<-20){step *=-1;}

    ofDrawCircle(moon+offset, 240);
    ofDrawCircle(moon-offset, 240);
    ofPopMatrix();
    
    //Title
    ofSetColor(255,255,255,255);
    
//    ofPushMatrix();
//    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
//
//    i+=0.5;
//    ofRotateYDeg(i);
//
//    Title.drawCenter(0,-30);
//    ofPopMatrix();
    if(toggle==false){
        Title.drawCenter(ofGetWidth()/2,ofGetHeight()/2-30);}
    
    //shadow
    ofSetColor(255, 255, 255, 50);
    ofPoint origin(ofGetWidth()/2, ofGetHeight()-50);
    ofPoint newOrigin(origin.x-myMouse.x, ofGetHeight()-50);
    ofDrawEllipse(newOrigin, 300 + newOrigin.distance(origin), 50);
   
    //move credits and moon down
    myMouse.y = speed * ofGetHeight()/2/3 + (1-speed )* myMouse.y;
    if(myMouse.y*3>=ofGetHeight()/2){
        speed =0;
        myMouse.y = ofGetHeight()/2/3;
    }
    
    //credits
    ofSetColor(255,255,255);
    credits.drawCenter(ofGetWidth()/2, ofGetHeight()-100+myMouse.y);
     credits.wrapTextX(300);
    
    if(toggle==true){
        fbo.begin();
          ofSetColor(0, 0, 0, 10); // background color with alpha
          ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
          
        ofPushMatrix();
         ofTranslate(ofGetWidth()/2,ofGetHeight()/2);

         i+=0.5;
         ofRotateYDeg(i);
        
         Title.drawCenter(0,-30);
         ofPopMatrix();
        
        fbo.end();
        
        ofSetColor(255,255,255);  // always set the color before drawing the fbo
        fbo.draw(0,0);
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int step = 10;
    if(key == OF_KEY_LEFT) myMouse.x = myMouse.x - step;
    if(key == OF_KEY_RIGHT) myMouse.x = myMouse.x + step;
    
    if(key == 'f') {
        toggle= !toggle;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouseX=x;
    mouseY=y;

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    speed = 0.1;


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
