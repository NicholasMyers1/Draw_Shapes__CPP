#ifndef INCLUDESVOIDS_H
#define INCLUDESVOIDS_H
		#include <future>
		#include <math.h>
		#include <ctime>
		#ifdef WIN32
			#define WIN32_LEAN_AND_MEAN
			#include <windows.h>
		#endif
		#include <iostream>
		#include <stdlib.h>
		#include <stdio.h>
		#include <stdarg.h>
		#include <cstring>
		#include <fstream>
	#define GLEW_STATIC
		#include <GL/glew.h>
		#include <gl\gl.h>
		#include <gl\glext.h>
		#include <gl\glaux.h>
		#include <gl\glu.h>
		#include <GL\glut.h>
		#include <assert.h>
		#include <sstream>
		#include <iomanip>
		#include <ctime>
		#include <cstring>
		#include <cmath>
		#include <limits.h>
		#include <random>
		#include <fstream>
		#include <time.h>
		#include <string.h>
		#include <string>
		#include <cstdlib>
		#include <cstdio>
		#include <gl\glfw.h>
		#include <vector>
		#include <conio.h>
		#include <new>
	using namespace std;
	//DEFINITIONS: 
	//VOIDS: 
		void INIT();
			void BUTTON_LOGIC(int buttonNumber);
			void mousemoveunpressed(int x, int y);
			void mousemotion(int x, int y);
			void mouseclick(int button,int state,int x,int y);
			void skeyd (int key,int x,int y);
			void keyPressed(unsigned char key,int x,int y);
		void DRAW2D();
		void DRAW3D();
	//STRUCTURES:
		//buttons; 
		struct _BUTTONS{
			int x,y;
			double width,height;
			string text;
		};extern _BUTTONS BUTTON[25];
		extern int buttonSelected;
		extern double colorVal[3];//
		//shapes;
		struct _SHAPES{
				vector<int> listID;
				vector<int> x;vector<int> y;
				vector <int> size_;
				vector<double> r; vector<double> g; vector<double> b;
				int listSize;
			int press;
			int mode;
			int pointLineSize;
			int pX,pY,rX,rY;
		};extern _SHAPES SHAPE;
	//GLOBALS: 
		extern bool INIT_;
		//WINDOW: 
			extern int winW,winH;
			extern bool fullScreen;
#endif
