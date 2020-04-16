#pragma once

#include "ofMain.h"
#include "ofxTextSuite.h"
#include "ofxGui.h"

#include <time.h>


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofFbo fbo;
    ofTrueTypeFont MyFont;
    ofxTextBlock        Title;
    ofxTextBlock        Key;
    ofxTextBlock        credits;
        ofxTextBlock        end;
    ofxTextBlock s1;
    ofxTextBlock s2;
    ofxTextBlock s3;
    ofxTextBlock s4;
    ofxTextBlock s5;
    ofxTextBlock s6;
    TextBlockAlignment  alignment;  //constants for controlling state
    
    void scene0();
    void scene1();
    void scene2();
    void scene3();
    void scene4();
    void scene5();
    void scene6();
    
    ofxFloatSlider volume;
    ofxFloatSlider scale;
    ofxColorSlider color;
    ofxVec2Slider loc;
    ofxButton displayButton;
    ofxIntSlider deg;
    
    ofxPanel gui;
    
    ofSoundPlayer bgm;
    ofSoundPlayer s1bgm;
    ofSoundPlayer s2bgm;
    ofSoundPlayer s3bgm;
    ofSoundPlayer s4bgm;
    ofSoundPlayer s5bgm;
    ofSoundPlayer s6bgm;
    
    ofPolyline currentPolyline;
    ofPolyline s3Poly;
    ofPolyline s4Poly;
    
    ofVec2f lastPoint;
    float minDistance;
    vector <ofPolyline> polylines;
    vector <ofPolyline> s3polylines;
    vector <ofPolyline> s4polylines;
    
};
