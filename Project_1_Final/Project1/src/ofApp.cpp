#include "ofApp.h"


ofPoint moveMoon = ofVec2f(0,0);
bool moonmoved = false;
bool sc0 = true;
bool sc1 = false;
bool sc2 = false;
bool sc3 = false;
bool sc4 = false;
bool sc5 = false;
bool sc6 = false;
bool sc0end = false;
bool sc1end = false;
bool sc2end = false;
bool sc3end = false;
bool sc4end = false;
bool sc5end = false;
bool sc6end = false;
bool tcend =false;
bool t1 = false;
bool t2 = false;
bool t3 = false;
bool t4 = false;
bool t5 = false;
bool t6 = false;
bool tc = false;
bool aniRun = false;
bool polyHide = false;
bool s3polyHide = false;
float i1=0;
float i =0;
float a = 0;
float offset=0;
float haloStep=0.1;
int step = 10;
float speed =0;
float movedis = 0;
float maxDis = 160;
float textSpeed = 0.03;
ofImage r1, r2, r3, r4, r5;

float g1=0;
float g2=255;

float polyScale;
float aniScale = 1;
float s3Scale = 2;
float s4Scale = 1;

int t;
int time3;

float x = -300;



//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(50);
    //ofSetCurveResolution(150);
    ofSetFullscreen(true);
    ofSetFrameRate(60);
    ofHideCursor();
    
    
    
    //gui setup
    
    gui.setup(); // most of the time you don't need a name
    
    gui.add(loc.setup("location", {ofGetWidth()*.5, ofGetHeight()*.5}, {0, 0}, {ofGetWidth(), ofGetHeight()}));
    //gui.add(color.setup("background gradient", ofColor(255), ofColor(0), ofColor(255)));
   // gui.add(scale.setup("scale",4,1,5));
    gui.add(deg.setup("rotate",0,0,180));
    
    
    //fbo setup
    fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA32F);
    fbo.begin();
    ofClear(255,255,255);
    fbo.end();
    
    
    
    //text setting
    Title.init("TrajanPro-Regular.otf", 50);
    Title.setText("Building Zobeide");
    
    end.init("TrajanPro-Regular.otf", 40);
    end.setText("The End");
    
    credits.init("TrajanPro-Regular.otf", 10);
    credits.setText("Story: Italo Calvino  Production: Jiangnan Hou");
    
    s1.init("TrajanPro-Regular.otf",10);
    s1.setText("From there, after six days and seven nights, you arrive at Zobeide, the white city, well exposed to the moon, with streets wound about themselves as in a skein.");
    
    s2.init("TrajanPro-Regular.otf",10);
    s2.setText("They tell this tale of its foundation: men of various nations had an identical dream. They saw a woman running at night through an unknown city; she was seen from behind, with long hair, and she was naked. They dreamed of pursuing her. As they twisted and turned, each of them lost her. ");
    
    s3.init("TrajanPro-Regular.otf",10);
    s3.setText("After the dream, they set out in search of that city; they never found it, but they found one another; they decided to build a city like the one in the dream. In laying out the streets, each followed the course of his pursuit; at the spot where they had lost the fugitive's trail, they arranged spaces and walls differently from the dream, so she would be unable to escape again.");
    s4.init("TrajanPro-Regular.otf",10);
    
    s4.setText("This was the city of Zobeide, where they settled, waiting for that scene to be repeated one night. None of them, asleep or awake, ever saw the woman again. The city's streets were streets where they went to work every day, with no link any more to the dreamed chase. Which, for that matter, had long been forgotten.");
    
    s5.init("TrajanPro-Regular.otf",10);
    s5.setText("New men arrived from other lands, having had a dream like theirs, and in the city of Zobeide, they recognized something from the streets of the dream, and they changed the positions of arcades and stairways to resemble more closely the path of the pursued woman and so, at the spot where she had vanished, there would remain no avenue of escape.");
    
    s6.init("TrajanPro-Regular.otf",10);
    s6.setText("The first to arrive could not understand what drew these people to Zobeide, this ugly city, this trap.");
    
    
    
    bgm.load("bgm.mp3");
    bgm.play();
    bgm.setLoop(true);
    bgm.setVolume(0.4);
    s1bgm.load("s1.mp3");
    s2bgm.load("s2.mp3");
    s3bgm.load("s3.mp3");
    s4bgm.load("s4.mp3");
    s5bgm.load("s5.mp3");
    s6bgm.load("s6.mp3");
    
    r1.load("running-01.png");
    r2.load("running-02.png");
    r3.load("running-03.png");
    r4.load("running-04.png");
    r5.load("running-05.png");
    
    
    ofSetBackgroundColor(0);
    
    //reset
    moveMoon = ofVec2f(0,0);
    moonmoved = false;
    sc0 = true;
    sc1 = false;
    sc2 = false;
    sc3 = false;
    sc4 = false;
    sc5 = false;
    sc6 = false;
    sc0end = false;
    sc1end = false;
    sc2end = false;
    sc3end = false;
    sc4end = false;
    sc5end = false;
    sc6end = false;
    tcend = false;
    t1 = false;
    t2 = false;
    t3 = false;
    t4 = false;
    t5 = false;
    t6 = false;
    tc = false;
    aniRun = false;
    polyHide = false;
    s3polyHide = false;
    i1=0;
    i =0;
    a = 0;
    offset=0;
    haloStep=0.1;
    step = 10;
    speed =0;
    movedis = 0;
    maxDis = 160;
    textSpeed = 0.03;

    g1=0;
    g2=255;

    aniScale = 1;
    s3Scale = 2;
    s4Scale = 1;

    x = -300;

}


//--------------------------------------------------------------
void ofApp::update(){
    s1bgm.setVolume(0.5);
    
    //s1 polylines
    
    float x = ofRandom(-100*polyScale,100*polyScale);
    float y = ofRandom(-100*polyScale,100*polyScale);
    float z = ofRandom(-100*polyScale,100*polyScale);
    
    float x3 = ofRandom(-100*s3Scale,100*s3Scale);
    float y3 = ofRandom(-50*s3Scale,50*s3Scale);
    float z3 = ofRandom(-100*s3Scale,100*s3Scale);
    
    if(sc1 == true && ofGetFrameNum() % 3 == 0){
        currentPolyline.curveTo(x,y,z);  // Here we are using an ofVec2f with curveTo(...)
        
        currentPolyline.simplify(0.5);
        polylines.push_back(currentPolyline);
        if(currentPolyline.size()>20){
            currentPolyline.clear();
        }
        
    }
    if(sc3 == true && ofGetFrameNum() % 5 == 0){
        
        s3Poly.curveTo(x3,y3,z3);
        s3Poly.simplify(0.5);
        s3polylines.push_back(s3Poly);
        if(s3Poly.size()>50){
            s3Poly.clear();
        }
        
    }
    if(sc4 == true){
           s4Poly.curveTo(ofRandom(-400,400),ofRandom(-100,150), ofRandom(-400,100));
           s4polylines.push_back(s4Poly);
           if(s4Poly.size()>20){
               s4Poly.clear();
           }
       }
    
    movedis = textSpeed * maxDis + (1-textSpeed )* movedis;
    
    if(polyHide == true && time(NULL)-t>=1){
        sc1end = true;}
    if(s3polyHide == true && time(NULL)-time3>=1){
        sc3end = true;}
    
   
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor(g1), ofColor(g2));
    
    if(sc0 ==true && sc0end == false){
        scene0();}
    if (sc1 == true){
        scene1();
        
        if(sc1end == true){
//            movedis =0;
//            a=0;
            s1bgm.stop();
            sc2 = true;
            s2bgm.play();
            t2 = true;
            sc1 = false;
        }
    }
    
    if (sc2 == true){
        scene2();
        g1++;
        if (g1>255){
            g1=255;
            aniRun = true;}
        g2--;
        if (g2<0){g2=0;}
    }
    if (sc3 == true){
        scene3();
        g1--;
        if (g1<0){g1=0;}
        g2++;
        if (g2>255){g2=255;}
        if(sc3end == true){
            movedis =0;
            a=0;
            s3bgm.stop();
            sc4 = true;
            s4bgm.play();
            t4 = true;
            sc3 = false;
        }
    }
    
    if (sc4 == true){
        scene4();
        t2 = false;
    }
    if (sc6 == true){
        scene6();
    }
    
    //Text
    a+=6;
    if(a>255)
    {a=255;}
    float textL = 500;
    //t1
    if(t1==true){
        
        s1.setColor(255,255,255,a);
        
        ofPushMatrix();
        ofTranslate(0, -1*movedis);
        s1.wrapTextX(textL);
        if(polyHide==true){
            ofTranslate(0, -160 + 2* movedis);
            //ofTranslate(0,100);
            s1.setColor(255,255,255,255-a);
        }
        s1.drawLeft(ofGetWidth()/2-textL*0.5,ofGetHeight());
        ofPopMatrix();
    }
    //t2
    if(t2==true){
        
        s2.setColor(255,255,255,a);
        
        ofPushMatrix();
        ofTranslate(0, -1* movedis);
        s2.wrapTextX(textL);
        if(sc3==true){
            ofTranslate(0, -160 + 2*movedis);
            s2.setColor(255,255,255,255-a);
        }
        s2.drawLeft(ofGetWidth()/2-textL*0.5,ofGetHeight());
        ofPopMatrix();
    }
    //t3
    if(t3==true){
        
        s3.setColor(255,255,255,a);
        
        ofPushMatrix();
        ofTranslate(0, -1* movedis);
        s3.wrapTextX(textL);
        if(sc4==true){
            ofTranslate(0, -160 + 2*movedis);
            s3.setColor(255,255,255,255-a);
        }
        s3.drawLeft(ofGetWidth()/2-textL*0.5,ofGetHeight());
        ofPopMatrix();
    }
    //t4
    if(t4==true){
        
        s4.setColor(255,255,255,a);
        
        ofPushMatrix();
        ofTranslate(0, -1* movedis);
        s4.wrapTextX(textL);
        if(sc5==true){
            ofTranslate(0, -160 + 2* movedis);
            s4.setColor(255,255,255,255-a);
        }
        s4.drawLeft(ofGetWidth()/2-textL*0.5,ofGetHeight());
        ofPopMatrix();
    }
    if(t5==true){
        
        s5.setColor(255,255,255,a);
        
        ofPushMatrix();
        ofTranslate(0, -1*movedis);
        s5.wrapTextX(textL);
        if(sc6==true){
            ofTranslate(0, -160 +2*movedis);
            s5.setColor(255,255,255,255-a);
        }
        s5.drawLeft(ofGetWidth()/2-textL*0.5,ofGetHeight());
        ofPopMatrix();
    }
    if(t6==true){
        
        s6.setColor(255,255,255,a);
        
        ofPushMatrix();
        ofTranslate(0, -1*movedis);
        s6.wrapTextX(textL);
        if(tc==true){
            ofTranslate(0, -160 + 2*movedis);
            s6.setColor(255,255,255,255-a);
        }
        s6.drawLeft(ofGetWidth()/2-textL*0.5,ofGetHeight());
        ofPopMatrix();
    }
    if(tc==true){
           
           credits.setColor(255,255,255,a);
           ofPushMatrix();
           maxDis = 400;
           ofTranslate(0, -1*movedis);
        end.wrapTextX(300);
        end.drawCenter(ofGetWidth()/2,ofGetHeight());
           credits.wrapTextX(250);
           credits.drawCenter(ofGetWidth()/2,ofGetHeight()+100);
           ofPopMatrix();
       }
       
    //gui.draw();
    cout<<s1.getHeight()<<endl;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == OF_KEY_LEFT)  {moveMoon.x = moveMoon.x - step;}
    if(key == OF_KEY_RIGHT) {moveMoon.x = moveMoon.x + step;}

    
    if(key == OF_KEY_DOWN && moonmoved == false ){
        speed = 0.1;
    }
    
    
    if(key == OF_KEY_DOWN && moonmoved == true ){
        sc0 = false;
        speed=0;
    }
    
    if(key == OF_KEY_DOWN && sc1 == true && polyHide == false){
        polyHide =true;
        movedis =0;
        a=0;
        t = time (NULL);
        
    }
    
    
    if(key == OF_KEY_DOWN && sc2 == true && aniRun == true ){
        sc2end = true;
    }
    
    if(key == OF_KEY_DOWN && sc3 == true && s3polyHide == false){
        s3polyHide =true;
        time3 = time (NULL);
    }
    if(key == OF_KEY_DOWN && sc4 == true ){
        sc5 = true;
        movedis =0;
        a=0;
        s4bgm.stop();
        s5bgm.play();
        t5 = true;
        t3 =false;
    }
    
    if(key == OF_KEY_DOWN && sc4end == true ){
        sc6=true;
        movedis =0;
        a=0;
        s5bgm.stop();
        s6bgm.play();
        t6 = true;
        t4 =false;
    }
    if(key == OF_KEY_DOWN && sc6end == true ){
        s6bgm.stop();
        tc = true;
    }
    if(key == OF_KEY_DOWN && tcend == true ){
        sc4 = false;
        sc6=false;
        setup();
      }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == OF_KEY_DOWN && moonmoved == false){
        moonmoved = true;
    }
    
    if(key == OF_KEY_DOWN && sc0 == false && sc0end == false){
        sc1 = true;
        t1 = true;
        movedis = 0;
        a = 0;
        s1bgm.play();
        sc0end = true;
    }
    
    
    if(key == OF_KEY_DOWN && sc2end == true && sc3 == false && sc3end == false){
        movedis =0;
        a=0;
        sc2 = false;
        s2bgm.stop();
        sc3 = true;
        s3bgm.play();
        t3 = true;
        t1 =false;
    }
    
    if(key == OF_KEY_DOWN && sc5 == true ){
        sc4end = true;
    }
    
    if(key == OF_KEY_DOWN && sc6 == true ){
        sc6end = true;
    }
    
    if(key == OF_KEY_DOWN && tc == true ){
        tcend = true;
      }
    
}

//--------------------------------------------------------------
void ofApp::scene0(){
    //scene 0
   
    ofPushMatrix();
    ofTranslate(moveMoon.x,moveMoon.y);
    //Moon
    
    ofSetColor(255,255,255);
    ofPoint moon(ofGetWidth()/2, 0);
    ofDrawCircle(moon, 200);
    
    //Halo
    ofSetColor(255,255,255,200);
    offset+=haloStep;
    if (offset>20||offset<-20)
    {haloStep *=-1;}
    
    ofDrawCircle(moon+offset, 240);
    ofDrawCircle(moon-offset, 240);
    ofPopMatrix();
    
    
    //Title
    Title.setColor(200,200,200,255);
    Title.drawCenter(ofGetWidth()/2,ofGetHeight()/2-30);
    
    //shadow
    ofSetColor(255, 255, 255, 50);
    ofPoint origin(ofGetWidth()/2, ofGetHeight()-50);
    ofPoint newOrigin(origin.x-moveMoon.x, ofGetHeight()-50);
    ofDrawEllipse(newOrigin, 300 + newOrigin.distance(origin), 50);
    
    
    //move credits and moon down
    moveMoon.y = speed * ofGetHeight()/2 + (1-speed )* moveMoon.y;
//    if(moveMoon.y*3>=ofGetHeight()/2){
//        speed =0;
//        moveMoon.y = ofGetHeight()/2/3;
//    }
    //Keydown to contitue
    ofPushMatrix();
    ofTranslate(0, ofMap(sin(ofGetFrameNum()/10),-1,1,-20,-10)+moveMoon.y);
    ofSetLineWidth(3);
    ofSetColor(255, 255, 255);
    ofDrawLine(ofGetWidth()/2-50,ofGetHeight()-85,ofGetWidth()/2,ofGetHeight()-60);
    ofDrawLine(ofGetWidth()/2-50,ofGetHeight()-65,ofGetWidth()/2,ofGetHeight()-40);
    ofDrawLine(ofGetWidth()/2+50,ofGetHeight()-85,ofGetWidth()/2,ofGetHeight()-60);
    ofDrawLine(ofGetWidth()/2+50,ofGetHeight()-65,ofGetWidth()/2,ofGetHeight()-40);
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::scene1(){
    //scene 1
    
    //lines
    fbo.begin();
    ofSetColor(0, 0, 0, 20); // background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255);
    if(polylines.size()>50){
        polylines.erase(polylines.begin());}
    for (int i=0; i<polylines.size(); i++) {
        
        ofPolyline polyline = polylines[i];
        // polyline.draw();
        
        if(polyHide==false){
            
            i1+=0.0002;
            polyScale=ofMap(sin(i1),-1,1,1.5,3);
            
        }
        if(polyHide==true){
            polyScale-=0.003;
            if(polyScale<=0){
                polyScale=0;}
        }
        
        float tangentLength = 80*polyScale;
        
        for (int p=0; p<100; p+=5) {
            ofVec3f point = polyline.getPointAtPercent(p/100.0);
            float floatIndex = polyline.getIndexAtPercent(p/100.0);
            ofVec3f tangent = polyline.getTangentAtIndexInterpolated(floatIndex) * tangentLength;
            
            ofPushMatrix();
            ofTranslate(loc->x,loc->y);
            
            
            ofScale(polyScale);
            ofRotateXDeg(ofGetFrameNum()/3);
            ofRotateYDeg(deg);
            ofDrawLine(point-tangent/2, point+tangent/2);
            ofSetLineWidth(1);
            polyline.draw();
            ofPopMatrix();
        }
    }
    fbo.end();
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(0,0);
    
}

//--------------------------------------------------------------
void ofApp::scene2(){
    //scene 2
    
    polylines.clear();
    
    //running animation
    r1.resize(625,896);
    r2.resize(625,896);
    r3.resize(625,896);
    r4.resize(625,896);
    r5.resize(625,896);
    
    ofPushMatrix();
    i+=0.05;
    float step =ofMap(sin(i),-1,1,-100+i*2.5,100-i*2.5);
    if (i>40){step = 0;}
    ofTranslate(ofGetWidth()/2+step,ofGetHeight()/2-130);
    
    if(aniRun==true){
        aniScale -= 0.001;
        if(aniScale<0.1){aniScale = 0.1;}
        ofScale(aniScale);}
    //image transparency
    ofSetColor(255,ofMap(sin(i*1.2),-1,1,10,255));
    int aniSpeed = 10;
    if(ofGetFrameNum()/aniSpeed % 5 >=0 && ofGetFrameNum()/aniSpeed % 5 <1 ){
        r1.draw(-r1.getWidth()/2,0);
    }
    if(ofGetFrameNum()/aniSpeed % 5 >=1 && ofGetFrameNum()/aniSpeed % 5 <2 ){
        r2.draw(-r1.getWidth()/2,0);
    }
    if(ofGetFrameNum()/aniSpeed % 5 >=2 && ofGetFrameNum()/aniSpeed % 5 <3 ){
        r3.draw(-r1.getWidth()/2,0);
    }
    if(ofGetFrameNum()/aniSpeed % 5 >=3 && ofGetFrameNum()/aniSpeed % 5 <4 ){
        r4.draw(-r1.getWidth()/2,0);
    }
    if(ofGetFrameNum()/aniSpeed % 5 >=4 && ofGetFrameNum()/aniSpeed % 5 <5 ){
        r5.draw(-r1.getWidth()/2,0);
    }
    ofPopMatrix();
    
}

void ofApp::scene3(){
    
    fbo.begin();
    ofSetColor(0, 0, 0, 20); // background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    if(s3polylines.size()>15){
        s3polylines.erase(s3polylines.begin());}
    
    if(s3polyHide==true){
        s3Scale-=0.04;
        if(s3Scale<=0){
            s3Scale=0;}
    }
    
    for (int i=0; i<s3polylines.size(); i++) {
        
        ofPolyline s3polyline = s3polylines[i];
        for (int p=10; p<110; p+=20) {
            ofVec3f point = s3polyline.getPointAtPercent(p/100.0);
            
            ofPushMatrix();
            
            ofTranslate(loc->x,loc->y+50);
            ofScale(s3Scale);
            ofRotateYDeg(ofGetFrameNum()/6);
            if(g1<150){
                ofSetColor(255, 255, 255);
                ofNoFill();
                ofSetRectMode(OF_RECTMODE_CENTER);
                ofDrawRectangle(point.x,point.y-35*ofNoise(point.x, point.y),point.z,50, 70*ofNoise(point.x, point.y));
                
                if(point.x>ofRandom(ofGetWidth()) && point.x<ofRandom(ofGetWidth())+30 &&ofGetFrameNum()%20 ==0 ){
                    ofSetColor(255, 255, 255);
                    //            ofDrawLine(point,point-ofVec3f(0,ofRandom(0,100),0));
                    ofFill();
                    ofDrawRectangle(point.x,point.y-35*ofNoise(point.x, point.y),point.z,50, 70*ofNoise(point.x, point.y));
                }
                else{
                    ofSetColor(255, 255, 255, 100);
                    ofFill();
                    ofDrawRectangle(point.x,point.y-35*ofNoise(point.x, point.y),point.z,50, 70*ofNoise(point.x, point.y));
                }
            }
            ofSetColor(255, 255, 255);
            ofSetLineWidth(1);
            s3polyline.draw();
            
            //ofRotateXDeg(90);
            
            ofPopMatrix();
        }
    }
    
    fbo.end();
    ofSetColor(255, 255, 255);
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::scene4(){
   // s3polylines.clear();
    fbo.begin();
    ofSetColor(0, 0, 0, 20); // background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    if(s4polylines.size()>50){
        s4polylines.erase(s4polylines.begin());}
    //
    if(sc6==true){
        s4Scale-=0.04;
        if(s4Scale<=0){
            s4Scale=0;}
    }
    
    for (int i=0; i<s4polylines.size(); i++) {
        
        ofPolyline s4polyline = s4polylines[i];
        for (int p=10; p<110; p+=5) {
            ofVec3f point = s4polyline.getPointAtPercent(p/100.0);
            
            if(sc5==true){
                if(sc6==false){
                x+=0.01;
                if(x>100){
                    x=100;
                }
                }
                if(sc6==true){
                    x=ofMap(sin(ofGetFrameNum()/60),-1,1,100,400);
                }
                ofPushMatrix();
                ofTranslate(ofGetWidth()/2,x);
                ofScale(3,2.5,2);
                ofSetColor(0, 180);
                ofSetLineWidth(3);
                s4polyline.draw();
                ofSetLineWidth(1);
                ofDrawLine(point, point+ofVec2f(0,100));
                ofPopMatrix();
            }
            
            ofPushMatrix();
            ofTranslate(loc->x,loc->y);
            ofScale(s4Scale);
            ofRotateYDeg(ofGetFrameNum()/6);
            ofSetColor(255);
            ofSetLineWidth(2);
            s4polyline.draw();
            ofSetColor(255, 200);
            ofSetLineWidth(1);
            ofDrawLine(point, point+ofVec2f(0,100));
            ofPopMatrix();
        }
    }
    
    fbo.end();
    ofSetColor(255, 255, 255);
    fbo.draw(0,0);
    
}

void ofApp::scene6(){
    //scene 6
    
    //polylines.clear();
    
    //running animation
    r1.resize(625,896);
    r2.resize(625,896);
    r3.resize(625,896);
    r4.resize(625,896);
    r5.resize(625,896);
    
    ofPushMatrix();
    i+=0.05;
    float step =ofMap(sin(i),-1,1,-100+i*2.5,100-i*2.5);
    if (i>40){step = 0;}
    ofTranslate(ofGetWidth()/2+step,ofGetHeight()/2-130);
    
    aniScale -= 0.001;
    if(aniScale<0.3){aniScale = 0.3;}
    ofScale(aniScale);
    //image transparency
    ofSetColor(255,ofMap(sin(i*1.2),-1,1,10,255));
    int aniSpeed = 10;
    if(ofGetFrameNum()/aniSpeed % 5 >=0 && ofGetFrameNum()/aniSpeed % 5 <1 ){
        r1.draw(-r1.getWidth()/2,0);
    }
    if(ofGetFrameNum()/aniSpeed % 5 >=1 && ofGetFrameNum()/aniSpeed % 5 <2 ){
        r2.draw(-r1.getWidth()/2,0);
    }
    if(ofGetFrameNum()/aniSpeed % 5 >=2 && ofGetFrameNum()/aniSpeed % 5 <3 ){
        r3.draw(-r1.getWidth()/2,0);
    }
    if(ofGetFrameNum()/aniSpeed % 5 >=3 && ofGetFrameNum()/aniSpeed % 5 <4 ){
        r4.draw(-r1.getWidth()/2,0);
    }
    if(ofGetFrameNum()/aniSpeed % 5 >=4 && ofGetFrameNum()/aniSpeed % 5 <5 ){
        r5.draw(-r1.getWidth()/2,0);
    }
    ofPopMatrix();
    
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

