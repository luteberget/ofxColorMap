#pragma once

#include "ofMain.h"

#include "ofxColorMap.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxColorMap colormap;
		ofImage noiseimg;
		ofImage colornoiseimg;
		ofImage demoimg;
		ofImage colordemoimg;

		struct ClickBox {
		    ofRectangle box;
		    bool active;
		    string text;
		};
		vector<ClickBox> boxes;
		string currentmap;

};
