#include "testApp.h"
#include "Poco/Delegate.h"
#include "Poco/Timestamp.h"
//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(50,50,50);

	nInstances = 1024; // we have to pre-define the number of the instances
	myClassObject = new myClass*[nInstances];	// initialize myClassObject 
	nodeId = 0;
    enabled=false;
}


//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofDrawBitmapString("nodeId: " + ofToString(nodeId), 20, 220);
	ofDrawBitmapString(floatMsg, 20, 20);
	ofDrawBitmapString(intMsg, 20, 40);
	ofDrawBitmapString("click to enable/disable events", 20, 60);
	ofDrawBitmapString(testFloatMsg, 20, 80);
	ofDrawBitmapString(testIntMsg, 20, 100);
	ofDrawBitmapString("click to enable/disable events 2", 20, 120);
}

void testApp::gLine(float & f){
	//ofLine(ofRandom(0,100),200,200,200);
	cout << "skjhgshg" << endl;
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
	if (key == 'o' && nodeId != 0)	
	{	
		nodeId--;
		myClassObject[nodeId]->disable();
		myClassObject[nodeId]->~myClass();

	}
	if (key == 'p')	
	{
		myClassObject[nodeId] = new myClass();
		ofAddListener(myClassObject[nodeId]->newFloatEvent, this, &testApp::newTestFloat);
		myClassObject[nodeId]->enable();
		nodeId++;
	}

	if (key == 'z')	
	{
		myClassObject[0]->enable();
	}
	if (key == 'Z')	
	{
		myClassObject[0]->disable();
	}
	if (key == 'x')	
	{
		myClassObject[1]->enable();
	}
	if (key == 'X')	
	{
		myClassObject[1]->disable();
	}
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
		for (int i = 0; i < 500; i++)	
			{
			evObject.disable();
			myClassObject[i]->disable();
		}
    } else {
		for (int i = 0; i < 500; i++)	
		{
			evObject.enable();
			myClassObject[i]->enable();
		}
	};
    enabled=!enabled;

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
}

