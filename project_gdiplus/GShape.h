#pragma once
#include "GView.h"
#include "GWorld.h"
#include "GObject.h"

class GShape : public GObject{
public:
	GWorld::GFlags flags;
	GWorld::GSHType type;
	GWorld::GPoint* points;
	uint32_t n;
	GWorld::GPoint scaledPoints[4];
	GObject* parent;
	GShape* prev;
	GShape* next;
	GWorld::GColor pen;
	GWorld::GColor fill;
	GWorld::GStyle style;
	GWorld::GThickness thickness;
	GWorld::GColor* themeColor;

	void Draw() {};
};
