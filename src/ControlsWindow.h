/*
 * ControlsWindow.h
 *
 *  Created on: 08/01/2011
 *      Author: arturo
 */

#ifndef CONTROLSWINDOW_H_
#define CONTROLSWINDOW_H_

#include "ofxFenster/ofxFenster.h"
#include "ofxWidgets/src/ofxWidgets.h"

class testApp;

class ControlsWindow: public ofxFensterListener {
public:
	ControlsWindow(testApp * app);
	virtual ~ControlsWindow();

	void fensterSetup();
	void fensterUpdate();
	void fensterDraw();

	void fensterKeyPressed  (int key);
	void fensterKeyReleased(int key);
	void fensterMouseMoved(int x, int y );
	void fensterMouseDragged(int x, int y, int button);
	void fensterMousePressed(int x, int y, int button);
	void fensterMouseReleased(int x, int y, int button);
	void fensterWindowResized(int w, int h);


	ofxWFrame gui,gui_women;
	ofxWFrame gui_sound;

private:
	testApp * app;

};

#endif /* CONTROLSWINDOW_H_ */
