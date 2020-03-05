#include "ofApp.h"
//why r has to be global?

float r=0;
float r2=0;
ofVec2f center1(490,285), rightB1(460, 280), rightB2(520, 290),
center2(415,415), m1(390, 420),m2(390, 440),m3(420, 430),m4(450, 410);
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int num = ofGetFrameNum()/60;
    ofNoFill();
    //face
    ofDrawBezier(330, 310, 340, 510, 430, 520, 520, 340 );
    //hair low
    ofDrawBezier(520, 400, 590, 160, 310, 90, 300, 400 );
    //hair top
    ofDrawBezier(540, 300, 570, 70, 210, 30, 290, 600 );
    
    
    //happy
    if(num % 12 >= 0 && num % 12 < 2){
        //left eye
        ofDrawBezier(330, 280, 340, 310, 380, 320, 400, 300 );
        //right eye
        ofDrawBezier(450, 310, 450, 330, 490, 340, 520, 320 );
        //nose and left brow
        ofDrawBezier(350, 250, 380, 230, 480, 260, 390, 400 );
        //right brow
        //ofDrawBezier(460, 280, 470, 260, 520, 260, 520, 290 );
        ofDrawLine(460,280,520,290);
        //mouth
        ofDrawBezier(390, 420, 390, 440, 420, 430, 450, 410 );
    }
    
    //sad
    if(num % 12 >= 2 && num % 12 < 5){
        //why deg has to be local?
        float deg = 0;
        // deg+=3;
        if(num % 12>=2 && num % 12 < 3){
            deg+=3;
            rightB1.rotate(deg/6, center1);
            rightB2.rotate(deg/6, center1);
            
            m1.rotate(deg, center2);
            m2.rotate(deg, center2);
            m3.rotate(deg, center2);
            m4.rotate(deg, center2);
        }
        
        //right brow
        ofDrawLine(rightB1.x, rightB1.y, rightB2.x, rightB2.y);
        //mouth
        ofDrawBezier(m1.x, m1.y, m2.x, m2.y, m3.x, m3.y, m4.x, m4.y);
        
        //left eye
        ofDrawBezier(330, 280, 340, 310, 380, 320, 400, 300 );
        //right eye
        ofDrawBezier(450, 310, 450, 330, 490, 340, 520, 320 );
        //nose and left brow
        ofDrawBezier(350, 250, 380, 230, 480, 260, 390, 400 );
    }
    //surprise
    if(num % 12 >= 5 && num % 12 < 8){
        
        if(num % 12 >=5 && num % 12 <6){
            r +=0.1;
            r2+=1;
        }
        if(r>6){r=0;}
        if(r2>60){r2=0;}
        
        //left eye
        ofDrawCircle(365, 290, r);
        //right eye
        ofDrawCircle(485, 315, r);
        //right brow
        ofDrawLine(rightB1.x, rightB1.y, rightB2.x, rightB2.y);
        //mouth
        ofDrawEllipse(410, 415, r2, r2/6);
        //nose and left brow
        ofDrawBezier(350, 250, 380, 230, 480, 260, 390, 400 );
    }
    
    
    //angry
    if(num % 12 >= 8 && num % 12 < 11){
        float deg =0;
        if(num % 12 >=8 && num % 12 <9){
            deg-=0.8;
            r +=0.15;
            rightB1.rotate(deg, center1);
            rightB2.rotate(deg, center1);
        }
        
        if (r>15){r=0;}
        //left eye
        ofDrawCircle(365, 290, r);
        //right eye
        ofDrawCircle(485, 315, r);
        //right brow
        ofDrawLine(rightB1.x, rightB1.y, rightB2.x, rightB2.y);
        //mouth
        ofDrawBezier(m1.x, m1.y, m2.x, m2.y, m3.x, m3.y, m4.x, m4.y);
        //nose and left brow
        ofDrawBezier(350, 250, 380, 230, 480, 260, 390, 400 );
    }
    
    //angry to happy
    if(num % 12 >= 11 && num % 12 < 12){
        float deg =0;
        deg+=0.3;
        rightB1.rotate(deg, center1);
        rightB2.rotate(deg, center1);
        
        m1.rotate(deg*10, center2);
        m2.rotate(deg*10, center2);
        m3.rotate(deg*10, center2);
        m4.rotate(deg*10, center2);
        
        //left eye
        ofDrawBezier(330, 280, 340, 310, 380, 320, 400, 300 );
        //right eye
        ofDrawBezier(450, 310, 450, 330, 490, 340, 520, 320 );
        //right brow
        ofDrawLine(rightB1.x, rightB1.y, rightB2.x, rightB2.y);
        //mouth
        ofDrawBezier(m1.x, m1.y, m2.x, m2.y, m3.x, m3.y, m4.x, m4.y);
        //nose and left brow
        ofDrawBezier(350, 250, 380, 230, 480, 260, 390, 400 );
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
