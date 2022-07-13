#pragma once
#include "GView.h"
#include "GWorld.h"
#include "GObject.h"

// GShape.h
class GShape {
protected:
	GWorld::GFlags flags;
	GWorld::GSHType type;
	GWorld::GPoint* points;
	long n;
	GWorld::GPoint* scaledPoints;
	GObject* parent;
	GShape* prev;
	GShape* next;
	GWorld::GColor pen;
	GWorld::GColor fill;
	GWorld::GStyle style;
	GWorld::GThickness thickness;
public:
	virtual void Draw() {};
};

class GLine : GShape {
public:
	void Draw() {
		void* _DC = parent->parent->DC;
		drawLine(DC, scaledPoints, n, pen, fill, style, thickness);
	};
};