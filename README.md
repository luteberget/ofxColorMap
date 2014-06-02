ofxColorMap
===========

Colorize your grayscale images with a linear segmented color map, as used in scientific plotting. Maps are taken from [Matplotlib](http://matplotlib.org/).


## Usage
* Add an ofxColorMap object to your app.
* Select a colormap
    * Use a preset colormap. See list of preset maps below.
      ```
      colormap.setMapFromName("summer")
      ``` 

    * Alternatively, make your own color map. See matplotlib documentation for an explanation of the parameters.
      ```
      ofxColorMap::ColorMapChannel r ; r .push_back(ofVec3f( 0.0,0.0,0.0 )); r .push_back(ofVec3f( 1.0,1.0,1.0 ));
      ofxColorMap::ColorMapChannel g ; g .push_back(ofVec3f( 0.0,0.5,0.5 )); g .push_back(ofVec3f( 1.0,1.0,1.0 ));
      ofxColorMap::ColorMapChannel b ; b .push_back(ofVec3f( 0.0,0.4,0.4 )); b .push_back(ofVec3f( 1.0,0.4,0.4 ));
      ofxColorMap::ColorMap m; m.push_back(r); m.push_back(g); m.push_back(b);
      colormap.set(m);
      ```
  
* Convert a grayscale ofImage (of type OF_IMAGE_GRAYSCALE) to a color image (allocated to same size with type OF_IMAGE_COLOR).

   ```
   colormap.apply(inputImage, outputImage);
   ```



## Examples/screenshots
![](/screenshots/example_screenshot.png)
![](/screenshots/example_screenshot2.png)
![](/screenshots/example_screenshot3.png)

## Available maps (from Matplotlib).

See: http://matplotlib.org/examples/color/colormaps_reference.html

![](/screenshots/colormaps_reference_00.png)
![](/screenshots/colormaps_reference_01.png)
![](/screenshots/colormaps_reference_02.png)
![](/screenshots/colormaps_reference_03.png)
![](/screenshots/colormaps_reference_04.png)
