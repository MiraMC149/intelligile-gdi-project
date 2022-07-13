#pragma once
#include "GObject.h"
// GView.h;
class GView {
private:
	GObject* TopGObj;
	GObject* BottomGobj;
	void* DC;
public:
	void draw();
};
