#pragma once
// put in GWorld.h

namespace GWorld {
	typedef uint32_t GFlags; //change long to int32
	typedef uint32_t GColor;//change long to int32
	typedef uint32_t GStyle;
	typedef uint32_t GSHType;
	typedef uint32_t GThickness;

	//colors
	enum {
		NOCOLOR = 0xffffffff,
		GINDEXEDCOLOR = 0x80000000,
		COLORINDEXMASK = 0x0000ffff,
		RGBMASK = 0x00ffffff
	};
	enum {
		AlphaShift = 24,
		RedShift = 16,
		GreenShift = 8,
		BlueShift = 0
	};

	enum {
		AlphaMask = 0xff000000,
		RedMask = 0x00ff0000,
		GreenMask = 0x0000ff00,
		BlueMask = 0x000000ff
	};

	typedef struct gpoint_struct {
		double x;
		double y;
	}GPoint;

	typedef struct gdimension_struct {
		double w;
		double h;
	}GDimension;
};
typedef unsigned int uint32_t
