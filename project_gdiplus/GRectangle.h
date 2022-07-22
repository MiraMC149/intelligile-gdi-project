#pragma once
#include "GShape.h"
#include "IIIGDI.cpp"

class GLine : public GShape {
public:
	void Draw() {
		void* _DC = parent->Viewparent->DC;
		drawLine(_DC, &scaledPoints[2], pen, thickness, themeColor);
	};
};