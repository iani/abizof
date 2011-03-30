#include "testApp.h"
#include "Poco/Delegate.h"
#include "Poco/Timestamp.h"
//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(50,50,50);

    enabled=false;

	// add the newFloat method to listen for eventsAddon newFloatEvent
	ofAddListener(evObject.newFloatEvent, this, &testApp::newFloat);

	// add the newFloat method to listen for eventsAddon newIntEvent
	ofAddListener(evObject.newIntEvent, this, &testApp::newInt);

	// add the newFloat method to listen for myClass newFloatEvent
	ofAddListener(myClassObject.newFloatEvent, this, &testApp::newTestFloat);
	
	// add the newFloat method to listen for myClass newFloatEvent
	ofAddListener(myClassObject.newIntEvent, this, &testApp::newTestInt);
}


//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofDrawBitmapString(floatMsg, 20, 20);
	ofDrawBitmapString(intMsg, 20, 40);
	ofDrawBitmapString("click to enable/disable events", 20, 60);
	ofDrawBitmapString(testFloatMsg, 20, 80);
	ofDrawBitmapString(testIntMsg, 20, 100);
	ofDrawBitmapString("click to enable/disable events 2", 20, 120);
}

//--------------------------------------------------------------
void testApp::newFloat(float & f){
	floatMsg = "newFloat event:  " + ofToString(f);
}

//--------------------------------------------------------------
void testApp::newInt(int & i){
	intMsg = "newInt   event:  " + ofToString(i);
}

//--------------------------------------------------------------
void testApp::newTestFloat(float & f){
	testFloatMsg = "newTESTFloat event:  " + ofToString(f);
}

//--------------------------------------------------------------
void testApp::newTestInt(int & i){
	testIntMsg = "newTESTInt   event:  " + ofToString(i);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(enabled) {
        evObject.disable();
		myClassObject.disable();
    } else {
        evObject.enable();
		myClassObject.enable();
	};
    enabled=!enabled;

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
}

