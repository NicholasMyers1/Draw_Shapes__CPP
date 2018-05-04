#include "includesVoids.h"
//GLOBALS
	bool INIT_=true;//this is the only variable to initialize in the VARIABLES.cpp file;
	//STRUCT:
		_BUTTONS BUTTON[25];
			int buttonSelected;
			double colorVal[3];//
		_SHAPES SHAPE;//vectors are the sub structs;
			//RECT,CIRC,
	//WINDOW: 
		int winW,winH;
		bool fullScreen=false;//and this one;
