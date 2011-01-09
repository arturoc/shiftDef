#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ControlsWindow.h"
#include "ofxKinectPlayer.h"
#include "ofxKinect.h"
#include "SCRenderer.h"
#include "ofxTween.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

		void drawSound();

		void playWomen(bool & pressed);
		void playDresses(bool & pressed);
		void activateSound(bool & pressed);

		void audioReceived( float * input, int bufferSize, int nChannels );

		ControlsWindow * controlsWindow;

		ofVideoPlayer women1, women2, dresses;

		float front_sound_depth,back_sound_depth,sound_depth;
		float front_focus,back_focus,focus;
		float front_aperture,back_aperture,aperture;
		float front_pfactor,back_pfactor,pfactor;
		float front_fov,back_fov,fov;
		float front_onein,back_onein,one_in;
		float front_x,back_x,x;
		float front_y,back_y,y;
		float front_z,back_z,z;
		float front_tilt,back_tilt,tilt,prevTilt;
		float rot_y;
		float women_y,women_w,women_x_offset;

		float frontDepth, backDepth;

		float objectDepth;

		ofxKinectPlayer kPlayer;
		ofxKinect 		kinect;

		SCRenderer bw_renderer,color_renderer;

		ofxEasingSine easing;

		ofImage bokehTex;

		int fps;

		bool playingWomen,playingSound,playingDresses;
};

#endif
