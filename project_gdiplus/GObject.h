#pragma once
#include "GShape.h"
#include "GWorld.h"
#include "GView.h"
//GObject.h
class GObject : public GView{
public:
	GWorld::GFlags flags;
	GWorld::GPoint lowPoint;
	GWorld::GPoint highPoint;
	GWorld::GPoint location;
	GWorld::GDimension dim;
	GView* Viewparent;
	double xscale;
	double yscale;
	GWorld::GColor backColor;
	GObject* prev;
	GObject* next;
	GShape *topShape;
	GShape *botShape;

	void resize(GWorld::GDimension new_dim);
	void move(GWorld::GPoint new_loc);
	void displace(double dx, double dy);
	void moveTo(); //move to another view
};