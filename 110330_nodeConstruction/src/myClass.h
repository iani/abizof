/*
 * myClass.h
 *
 *  Created on: 17-dic-2008
 *      Author: art
 */

#ifndef MYCLASS_H_
#define MYCLASS_H_

#include "ofMain.h"
#include "ofEvents.h"

class myClass {
public:
	//~myClass() {}
	myClass(){
	    counter = 0;
	}

	void enable(){
	    ofAddListener(ofEvents.draw, this, &myClass::update);
	}

	void disable(){
	    ofRemoveListener(ofEvents.draw, this, &myClass::update);
	}

	void update(ofEventArgs & args){
		counter+=0.3;
		int intCounter=(int)counter;
		ofNotifyEvent(newFloatEvent, counter, this);
		ofNotifyEvent(newIntEvent, intCounter, this);
		//ofNotifyEvent(gLine, intCounter, this);
		
		ofLine(float(intCounter % 600), 300.0, 400.0, 200.0);
	}

	//ofEvent<float> gLine;

	ofEvent<float> newFloatEvent;
	ofEvent<int> newIntEvent;
	

private:
	float counter;
};
#endif /* OFXEVENTSADDON_H_ */
