#pragma once
#include "GShape.h"
#include "GWorld.h"
#include "IIIGDI.cpp"

class GLine : public GShape {
public:
	int height, width;

	void Draw() {
		void* _DC = parent->Viewparent->DC;	
		drawEllipse(_DC, &scaledPoints[1], fill, pen, style, thickness, themeColor, width, height);
	};
};