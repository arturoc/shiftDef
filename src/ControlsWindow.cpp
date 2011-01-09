/*
 * ControlsWindow.cpp
 *
 *  Created on: 08/01/2011
 *      Author: arturo
 */

#include "ControlsWindow.h"
#include "testApp.h"

ControlsWindow::ControlsWindow(testApp * _app) {
	app = _app;
}

ControlsWindow::~ControlsWindow() {
	// TODO Auto-generated destructor stub
}


void ControlsWindow::fensterSetup(){
	fenster->setFPS(10);
	ofxWidget::setEventsObject(&ofxFensterEvents);
	gui.init("main");
	ofAddListener(gui.addGroupedToggle("play women",&(app->playingWomen),"MAIN").boolEvent,app,&testApp::playWomen);
	ofAddListener(gui.addGroupedToggle("play sound",&(app->playingSound),"MAIN").boolEvent,app,&testApp::activateSound);
	ofAddListener(gui.addGroupedToggle("play dresses",&(app->playingDresses),"MAIN").boolEvent,app,&testApp::playDresses);

	gui_sound.init("sound");
	gui_sound.addSpinSlider("front s. depth",&app->front_sound_depth,20,150);
	gui_sound.addSpinSlider("front focus",&app->front_focus,100,500);
	gui_sound.addSpinSlider("front aperture",&app->front_aperture,0,0.06);
	gui_sound.addSpinSlider("front p.factor",&app->front_pfactor,1,3);
	gui_sound.addSpinSlider("front fov",&app->front_fov,60,80);
	gui_sound.addSpinSlider("front one in",&app->front_onein,1,8);
	gui_sound.addSpinSlider("front x",&app->front_x,0,300);
	gui_sound.addSpinSlider("front y",&app->front_y,0,300);
	gui_sound.addSpinSlider("front z",&app->front_z,-1000,1000);
	gui_sound.addSpinSlider("front tilt",&app->front_tilt,0,12);
	gui_sound.addSpinSlider("front depth",&app->frontDepth,0,500);


	gui_sound.addSpinSlider("back s. depth",&app->back_sound_depth,20,150);
	gui_sound.addSpinSlider("back focus",&app->back_focus,100,800);
	gui_sound.addSpinSlider("back focus",&app->back_aperture,0,0.06);
	gui_sound.addSpinSlider("back p.factor",&app->back_pfactor,1,3);
	gui_sound.addSpinSlider("back fov",&app->back_fov,60,160);
	gui_sound.addSpinSlider("back one in",&app->back_onein,1,4);
	gui_sound.addSpinSlider("back x",&app->back_x,0,300);
	gui_sound.addSpinSlider("back y",&app->back_y,0,300);
	gui_sound.addSpinSlider("back z",&app->back_z,-1000,1000);
	gui_sound.addSpinSlider("back tilt",&app->back_tilt,0,12);
	gui_sound.addSpinSlider("back depth",&app->backDepth,200,1000);

	gui_sound.addLoadButton("settings.xml","settings");
	gui_sound.addSaveButton("settings.xml","settings");

	gui_sound.loadFrom("settings.xml","settings");

	gui_women.init("women");
	gui_women.addSpinSlider("y",&app->women_y,0,1000);
	gui_women.addSpinSlider("w",&app->women_w,400,512);
	gui_women.addSpinSlider("x offset",&app->women_x_offset,-50,50);
	gui_women.addLoadButton("settings_W.xml","settings");
	gui_women.addSaveButton("settings_W.xml","settings");

	gui_women.loadFrom("settings_W.xml","settings");
}

void ControlsWindow::fensterUpdate(){

}

void ControlsWindow::fensterDraw(){
	ofDrawBitmapString("frame: " + ofToString(app->kPlayer.getFrameNum()),250,200);
	ofDrawBitmapString("sound_depth: " + ofToString(app->sound_depth),250,220);
	ofDrawBitmapString("focus: " + ofToString(app->focus),250,240);
	ofDrawBitmapString("aperture: " + ofToString(app->aperture),250,260);
	ofDrawBitmapString("pfactor: " + ofToString(app->pfactor),250,280);
	ofDrawBitmapString("one_in: " + ofToString(app->one_in),250,300);
	ofDrawBitmapString("objectDepth: " + ofToString(app->objectDepth),250,320);
	ofDrawBitmapString("framerate: " + ofToString(app->fps),250,340);
	ofDrawBitmapString("color alpha: " + ofToString(app->color_renderer.pointBrightness),250,360);
	ofDrawBitmapString("bw alpha: " + ofToString(app->bw_renderer.pointBrightness),250,380);
	ofDrawBitmapString("kinect tilt: " + ofToString(app->tilt),250,400);
	ofDrawBitmapString("fov: " + ofToString(app->fov),250,420);
	ofDrawBitmapString("x: " + ofToString(app->x),250,440);
	ofDrawBitmapString("y: " + ofToString(app->y),250,460);
	ofDrawBitmapString("z: " + ofToString(app->z),250,480);
}

void ControlsWindow::fensterKeyPressed  (int key){

}

void ControlsWindow::fensterKeyReleased(int key){

}

void ControlsWindow::fensterMouseMoved(int x, int y ){

}

void ControlsWindow::fensterMouseDragged(int x, int y, int button){

}

void ControlsWindow::fensterMousePressed(int x, int y, int button){

}

void ControlsWindow::fensterMouseReleased(int x, int y, int button){

}

void ControlsWindow::fensterWindowResized(int w, int h){

}
