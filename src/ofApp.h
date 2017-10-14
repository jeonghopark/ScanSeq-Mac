#pragma once

#include "ofMain.h"
#include "ofxTonic.h"

using namespace Tonic;


struct InputMovie {
    ofColor color;
    int index;
};


struct LineColor {
    float fRed;
    float fGreen;
    float fBlue;
    
    float movingFactor;
    float movVertical;
    bool bMovingTrigger;
    bool bNoteTrigger;
    int index;
};


struct CircleMoving{
    float movingFactor;
    float movVertical;
    bool bMovingTrigger;
    int index;
    float position;
};


struct LineOnOff{
    int index;
    bool bOnOff;
};


class ofApp : public ofBaseApp{
	
    ofxTonicSynth synth1;
    ofxTonicSynth synth2;
    ofxTonicSynth synth3;
    ofxTonicSynth synth4;
    ofxTonicSynth synthMain;

    
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void audioRequested(float * output, int Buffersize, int nChannels);

    ofSoundStream soundStream;

    
    LineOnOff lineOnOffs;
    ofEvent<LineOnOff> onOff[20];
    void onOffTest(LineOnOff & _lineOnOffs);
    
    int cameraDevice;
    int doubleTouchCount;
    bool bFrontCam;
    ofVideoGrabber grabber;
    ofTexture tex;
    unsigned char * pix;
    
    
    vector<ofColor> pixelColor;
    vector<ofColor> twentyPixelColor;
    vector<float> colorNumber;
    vector<float> randomYPos;
    int leftTwentyLineNumber;
    
    vector<LineColor> linecolors;
    vector<CircleMoving> circleMovings;
    vector<InputMovie> inputVideo;
    
    int cameraWidth, cameraHeight;
    
    int circleMovigSpeed;
    
};


