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
    void exit();

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
    
    LineOnOff lineOnOffs;
    ofEvent<LineOnOff> onOff[20];
    void onOffTest(LineOnOff & _lineOnOffs);
    
    int cameraDevice;
    int doubleTouchCount;
    bool bFrontCam;
    ofVideoGrabber grabber;
    ofTexture tex;
    unsigned char * pix;
    
//    AVCaptureConnection         *videoConnection;
//    AVCaptureVideoDataOutput    *videoOutput;
//    AVCaptureDeviceInput        *videoInput;
    
    
    vector<ofColor> pixelColor;
    vector<ofColor> twentyPixelColor;
    vector<float> colorNumber;
    vector<float> randomYPos;
    int leftTwentyLineNumber;
    
    vector<LineColor> linecolors;
    vector<CircleMoving> circleMovings;
    vector<InputMovie> inputVideo;
    
    int cameraWidth, cameraHeight;
    
    float touchMovY;
    
    float parameter1, parameter2, parameter3, parameter4, parameter5;
    float secondParameter1, secondParameter2, secondParameter3, secondParameter4, secondParameter5;
    
    int spectrogramWidth, spectrogramWidth2;

	ofMutex soundMutex;
    vector<float> drawBuffer, middleBuffer, audioBuffer;
    vector<float> drawBins, middleBins, audioBins;

    vector<float> drawBuffer2, middleBuffer2, audioBuffer2;
    vector<float> drawBins2, middleBins2, audioBins2;

	int plotHeight, bufferSize;

    void plot(vector<float>& buffer, float scale, float offset);

    int spectrogramOffset;
	ofImage spectrogram;

    int spectrogramOffset2;
	ofImage spectrogram2;

    vector<int> spectrum1PosX, spectrum2PosX;
    
    int circleMovigSpeed;
    
};


