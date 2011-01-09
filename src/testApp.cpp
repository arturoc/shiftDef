#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	/*front_sound_depth=136.99;
	back_sound_depth=123.29;
	front_focus=698.63;
	back_focus=front_focus;
	front_aperture=0.01;
	back_aperture=front_aperture;
	front_pfactor=1.99;
	back_pfactor=1.40;
	front_fov=60;
	back_fov=116;
	front_onein=4;
	back_onein=2;
	front_x=136.99;
	back_x=243;
	front_y=136.99;
	back_y=150;
	front_z=0;
	back_z=547.9;
	front_tilt=9;
	back_tilt=2;
	rot_y=0;
	frontDepth=139;
	backDepth=500;*/

	prevTilt=0;
	tilt=front_tilt;

	ofDisableArbTex();
	bokehTex.loadImage("point_bokeh.png");

	ofEnableArbTex();

	//kPlayer.setup("../../../shift/bin/data/depth.bin",true);
	//kPlayer.fps=30;
	kinect.init();
	kinect.open();

	bw_renderer.setup();
	color_renderer.setup();
	bw_renderer.pointBrightness = color_renderer.pointBrightness = 1;
	bw_renderer.rgbBrightness = color_renderer.rgbBrightness = 1;;
	bw_renderer.maxPointSize = color_renderer.maxPointSize=30;
	bw_renderer.nearThreshold = color_renderer.nearThreshold=50;
	bw_renderer.farThreshold = color_renderer.farThreshold=500;
	bw_renderer.dof = color_renderer.dof = true;

	bw_renderer.numSoundBuffers = color_renderer.numSoundBuffers=64;

	playingWomen=playingDresses=playingSound=false;

	women1.loadMovie("women1.mov");
	women2.loadMovie("women2.mov");
	dresses.loadMovie("dresses.mov");

	women_y=20;
	women_w=500;
	women_x_offset=0;


	ofSoundStreamSetup(0,2,44100,1024,1);

	ofBackground(0,0,0);
}

//--------------------------------------------------------------
void testApp::update(){
	if(playingSound){
		kinect.update();
		float * distancePixels = kinect.getDistancePixels();
		unsigned char * rgbPixels = kinect.getCalibratedRGBPixels();

		objectDepth = color_renderer.getObjectDepth();
		color_renderer.update(kinect.getDepthPixels(),640,480);
		color_renderer.update(distancePixels,rgbPixels,640,480);


		objectDepth = bw_renderer.getObjectDepth();
		bw_renderer.update(kinect.getDepthPixels(),640,480);
		bw_renderer.update(distancePixels,640,480);




		sound_depth = ofMap(objectDepth,frontDepth,backDepth,front_sound_depth,back_sound_depth,true);
		focus = ofMap(objectDepth,frontDepth,backDepth,front_focus,back_focus,true);
		aperture = ofMap(objectDepth,frontDepth,backDepth,front_aperture,back_aperture,true);
		pfactor = ofMap(objectDepth,frontDepth,backDepth,front_pfactor,back_pfactor,true);
		fov = ofMap(objectDepth,frontDepth,backDepth,front_fov,back_fov,true);
		one_in = ofMap(objectDepth,frontDepth,backDepth,front_onein,back_onein,true);
		x = ofMap(objectDepth,frontDepth,backDepth,front_x,back_x,true);
		y = ofMap(objectDepth,frontDepth,backDepth,front_y,back_y,true);
		z = ofMap(objectDepth,frontDepth,backDepth,front_z,back_z,true);
		tilt = ofMap(objectDepth,frontDepth,backDepth,front_tilt,back_tilt,true);
		color_renderer.pointBrightness = ofMap(objectDepth,frontDepth,backDepth,1,0,true);
		bw_renderer.pointBrightness = ofMap(objectDepth,frontDepth,backDepth,0,1,true);

		color_renderer.soundDepthFactor = bw_renderer.soundDepthFactor =sound_depth;
		color_renderer.focusDistance = bw_renderer.focusDistance =focus;
		color_renderer.aperture = bw_renderer.aperture =aperture;
		color_renderer.pointSizeFactor = bw_renderer.pointSizeFactor =pfactor;
		color_renderer.oneInX = bw_renderer.oneInX =one_in;
		color_renderer.oneInY = bw_renderer.oneInY =one_in;

		if(tilt!=prevTilt){
			kinect.setCameraTiltAngle(tilt);
			prevTilt = tilt;
		}
	}


	fps = ofGetFrameRate();
}


void testApp::drawSound(){
	//ofBackground(0,0,0);

	ofClear(0,0,0,255);
	ofPushMatrix();

		if(fov>0)
			ofSetupScreenPerspective(640,480,true,fov);
		else
			ofSetupScreenOrtho(640,480,true);


		ofNoFill();
		ofSetColor(255,255,255,255);

		ofTranslate(0,0,-z);

		ofTranslate(0,0,-objectDepth);
		ofRotate(rot_y,0,1,0);

		/*if(controlsWindow->doCameraEasing){
			cameraEasing.rotate();
		}*/

		ofTranslate(0,0,objectDepth);

		/*if(controlsWindow->doCameraEasing){
			cameraEasing.translate();
		}*/


		ofScale(2,2,2);
		ofTranslate(x,y);
		if(bw_renderer.pointBrightness>0.1){
			bw_renderer.draw(&bokehTex.getTextureReference());
		}
		if(color_renderer.pointBrightness>0.1){
			color_renderer.draw(&bokehTex.getTextureReference());
		}

	ofPopMatrix();

}


//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255,255,255);
	if(playingSound){
		drawSound();
	}else if(playingWomen){
		women1.update();
		women2.update();
		int x1 = (1024-women_w*2)/3;
		women1.draw(x1+women_x_offset,women_y,women_w,women_w*768/1024);
		women2.draw(x1*2+women_w+women_x_offset,women_y,women_w,women_w*768/1024);
	}else if(playingDresses){
		dresses.update();
		dresses.draw(0,0,1024,768);
	}
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

void testApp::audioReceived( float * input, int bufferSize, int nChannels ){
	if(!playingSound) return;
	bw_renderer.audioReceived(input,bufferSize,nChannels);
	color_renderer.audioReceived(input,bufferSize,nChannels);
}

//--------------------------------------------------------------
void testApp::playWomen(bool & pressed){
	if(pressed){
		women1.setPosition(0);
		women2.setPosition(0);
		women1.play();
		women2.play();
	}else{
		women1.stop();
		women2.stop();
	}
}

//--------------------------------------------------------------
void testApp::playDresses(bool & pressed){
	if(pressed){
		dresses.setPosition(0);
		dresses.play();
	}else{
		dresses.stop();
	}
}

//--------------------------------------------------------------
void testApp::activateSound(bool & pressed){
}
