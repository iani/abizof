#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
		ofSetBackgroundAuto(false);
		ofEnableSmoothing();
		ofEnableAlphaBlending(); 
		//glutSetCursor(GLUT_CURSOR_CYCLE);  // change cursor icon (http://pyopengl.sourceforge.net/documentation/manual/glutSetCursor.3GLUT.html)
		cout << "LSystem app recieving OSC at port: 12345 " << PORTlisten << "\n";
		receiver.setup( PORTlisten );
		current_msg_string = 0;
				
		ofSetWindowTitle("LSystem study");
		ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.

		LSystem.setup();

}

//--------------------------------------------------------------
void testApp::update(){
	for ( int i=0; i<NUM_MSG_STRINGS; i++ )	{
		if ( timers[i] < ofGetElapsedTimef() )
			msg_strings[i] = "";
	}	
	while( receiver.hasWaitingMessages() )
	{
		ofxOscMessage m;
		receiver.getNextMessage( &m ); 

		if ( m.getAddress() == "/lsystem" )	{
				//lsystemString = m.getArgAsString( 0 );
				//cout << lsystemString << endl;
				LSystem.lsystemString = m.getArgAsString( 0 );
				LSystem.length = m.getArgAsInt32( 1 );
				LSystem.theta = m.getArgAsFloat( 2 );
				LSystem.scale = m.getArgAsFloat( 3 );				
				LSystem.noise = m.getArgAsFloat( 4 );	
				lsystemGeneration = m.getArgAsInt32( 5 );
				
				if	(lsystemGeneration == 0)	{
					LSystem.startGeneration = true;
				}				
				
//				cout << LSystem.depthLength <<	endl;
//				cout << LSystem.scale <<	endl;
//				cout << LSystem.depthLength <<	endl;								
				LSystem.recieveString();		

							
			}
		}

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

