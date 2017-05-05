#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    noiseimg.allocate(ofGetWidth()/2,ofGetHeight()/4,OF_IMAGE_GRAYSCALE);
    colornoiseimg.allocate(ofGetWidth()/2,ofGetHeight()/4,OF_IMAGE_COLOR);

    demoimg.allocate(ofGetWidth()/2,ofGetHeight()/4,OF_IMAGE_GRAYSCALE);
    colordemoimg.allocate(ofGetWidth()/2,ofGetHeight()/4,OF_IMAGE_COLOR);

    size_t columnwidth = 0;
    for(map<string,ofxColorMap::ColorMap>::const_iterator it = colormap.namedMaps.begin();
                it != colormap.namedMaps.end(); it++) {
        const string& name = it->first;
        if(name.length() > columnwidth) {
            columnwidth = name.length();
        }
    }
    string defaultmap = "gray";
    int column = 0;
    int textheight = 16;
    int rowheight = textheight*1.2;
    columnwidth *= 7*1.2;

    // Make clickable boxes to select color map
    int row = 0;
    for(map<string,ofxColorMap::ColorMap>::const_iterator it = colormap.namedMaps.begin();
                it != colormap.namedMaps.end(); it++) {
        const string& name = it->first;
        ClickBox b;
	ofRectangle r;
        r.x = 2+column*columnwidth;
        r.y = 2+row*rowheight;
        if(r.y+rowheight+14 > ofGetHeight()) {
            column += 1;
            row = 0;
        } else {
            row += 1;
        }
        r.width = columnwidth-2;
        r.height = rowheight-2;
        b.text = name;
	b.active = false;
	if(name == defaultmap) {
		b.active = true;
		cout << name << endl;
	}
	b.box = r;
        boxes.push_back(b);
    }
    currentmap = defaultmap;
    colormap.setMapFromName(defaultmap);

    // Demo image with horizontal 0 -> 1 scale.
    ofPixels& p = demoimg.getPixels();
    for(size_t x = 0; x < demoimg.getWidth(); x++) {
        for(size_t y = 0; y < demoimg.getHeight(); y++) {
            int value = 255*(float)x/demoimg.getWidth();
            p[(int)(x+y*demoimg.getWidth())] = value;
        }
    }
    demoimg.update();

}

//--------------------------------------------------------------
void testApp::update(){
	// Perlin noise image
    ofPixels& p = noiseimg.getPixels();
    for(size_t x = 0; x < noiseimg.getWidth(); x++) {
        for(size_t y = 0; y < noiseimg.getHeight(); y++) {
            int value = 255*ofNoise(x/100.0,y/100.0,ofGetElapsedTimef()*0.1);
            p[(int)(x+y*noiseimg.getWidth())] = value;
        }
    }
    noiseimg.update();

    // Apply selected color map
    colormap.apply(noiseimg,colornoiseimg);
    colormap.apply(demoimg,colordemoimg);
}

//--------------------------------------------------------------
void testApp::draw(){
    demoimg.draw(ofGetWidth()/2,0*ofGetHeight()/4);
    colordemoimg.draw(ofGetWidth()/2,1*ofGetHeight()/4);
    noiseimg.draw(ofGetWidth()/2,2*ofGetHeight()/4);
    colornoiseimg.draw(ofGetWidth()/2,3*ofGetHeight()/4);

    ofColor active(0,255*0.4,0);
    ofColor notactive(0,0,0);
    for(size_t i = 0; i < boxes.size(); i++) {
        ofDrawBitmapStringHighlight(boxes[i].text, boxes[i].box.x, boxes[i].box.y+14, boxes[i].active?active:notactive);
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
	bool clicked = false;
    for(size_t i = 0; i < boxes.size(); i++) {
	    if(boxes[i].box.inside(x,y)) {
		    clicked = true;
		    currentmap = boxes[i].text;
	    }
    }

    if(clicked) {
	    for(size_t i = 0; i < boxes.size(); i++) {
		    boxes[i].active = (boxes[i].text == currentmap);
	    }

	    colormap.setMapFromName(currentmap);
    }

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
