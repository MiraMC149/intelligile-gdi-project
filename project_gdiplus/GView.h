#pragma once
#include "GObject.h"
#include "IIIGDI.cpp"
// GView.h;
class GView {
public:
	GObject* TopGObj;
	GObject* BottomGobj;
	void* DC;

	void draw();
};
