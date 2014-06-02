#pragma once
#include "ofMain.h"

#define NCOLORS 256

class ofxColorMap {
public:
    typedef vector<unsigned char> LookupTable;
    typedef vector<LookupTable> ColorTable;

    typedef vector<ofVec3f> ColorMapChannel;
    typedef vector<ColorMapChannel> ColorMap;

    static void makeLookupTable1D(const ColorMapChannel& data, LookupTable& table, int n, float gamma = 1.0f);

    void setMapFromName(string name);
    void setMapFromIndex(int n);

    void setMap(const ColorMap& m);

    void apply(ofImage& img1, ofImage& img2);
    ofColor use(ofColor c);
    ofColor use(unsigned char value);

    ofxColorMap();
    ~ofxColorMap() {}
    static const map<string, ColorMap> namedMaps;

private:
    ColorTable lookup;
    static map<string, ColorMap> createNamedMaps();
};
