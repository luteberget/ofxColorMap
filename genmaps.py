# Generates the file namedMaps.cpp used by
# openframeworks addon ofxColorMap.
#
# Extracts color maps from matplotlib (pylab).
#


import pylab
import inspect
import numpy
import sys

print """
#include "ofxColorMap.h"
map<string, ofxColorMap::ColorMap> ofxColorMap::createNamedMaps() {
    map<string, ColorMap> m;
    """


discrete_n = 10

for name,colormap in pylab.cm.cmap_d.iteritems():
	if not type(colormap) is pylab.matplotlib.colors.LinearSegmentedColormap:
		continue

	print "{"

	for channel in ('red','green','blue'):
		assert(channel in colormap._segmentdata.keys())

		print "ColorMapChannel",channel[0],";",

		d = colormap._segmentdata[channel]

		if inspect.isfunction(d):
			newd = []
			x = numpy.linspace(0,1,discrete_n)
			y = numpy.clip(numpy.array(d(x), dtype=numpy.float), 0, 1)

			for i in xrange(discrete_n):
				newd.append((x[i], y[i], y[i]))

			d = newd

		for i in d:
			print channel[0],".push_back(ofVec3f(",
			print str.join(",",map(str,i)),
			print "));",

		print
	print "ColorMap a; a.push_back(r); a.push_back(g); a.push_back(b);"
	print "m[\"%s\"] = a;"%(name)
	print "}"

print "return m;"
print "}"
