#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofTrueTypeFont.h"


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
    
    ofxFloatSlider speed;
    ofxFloatSlider height;
  ofxFloatSlider tempChange;
    ofxIntSlider textChange;
    ofTrueTypeFont myFont;
    ofSpherePrimitive sphere;
    ofConePrimitive cone;
    ofCylinderPrimitive cylinder;
    ofLight pointLight;
    ofLight pointLight2;
    ofLight pointLight3;
    ofLight pointLight4;
    ofMaterial material;
    ofMaterial mat2;
    ofTexture mTex;
    ofEasyCam cam;
    ofVboMesh mesh;
    ofNode meshNode;
    ofPolyline spring;
    
    ofxPanel gui;
    
};
