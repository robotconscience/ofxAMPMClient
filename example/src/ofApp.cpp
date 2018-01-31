#include "ofApp.h"

int sentX = 0;
int sentY = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    mAMPM = ofx::AMPMClient::create( 3002, 3003 );
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    mAMPM->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    string out = "This app should be run via AMPM!";
    out += "\nClick to send a message. Drag to send a custom message";
    out += "\nLast sent: x: " + ofToString(sentX) +", y: " + ofToString(sentY);
    ofDrawBitmapString(out, 20, 20);
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
    // send mouse positions to server
//    Json::Value mousePositions = Json::objectValue;
//    mousePositions["x"] = Json::intValue(event.getX());
//    mousePositions["y"] = Json::intValue(event.getY());
    
    mAMPM->sendCustomMessage( "/mouse", "{\"x\":" + ofToString(x) + ",\"y\":" + ofToString(y) + "}" );
    sentX = x;
    sentY = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofx::AMPMClient::get()->sendEvent( "category", "action", "label", 10 );

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
