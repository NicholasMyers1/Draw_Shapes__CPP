#include "includesVoids.h"
void mousemoveunpressed(int x, int y){
}//end void;
	int count=0;
	static vector<double> tempDrawWithMouse[2];
	static int vecSize=1;
void mousemotion(int x, int y){
	if(SHAPE.press==1){//preview when drawing: 
		SHAPE.rX=x;
		SHAPE.rY=y;
	}
	if(SHAPE.mode==5&&SHAPE.press==1){
		if(SHAPE.pX>(BUTTON[0].x+BUTTON[0].width)&&SHAPE.rX>(BUTTON[0].x+BUTTON[0].width)){
			if(count==0){
				tempDrawWithMouse[0].resize(vecSize);
				tempDrawWithMouse[1].resize(vecSize);
				
				SHAPE.listSize+=1;
				//resize: 
				SHAPE.listID.resize(SHAPE.listSize+1);
				SHAPE.x.resize(SHAPE.listSize+1);
				SHAPE.y.resize(SHAPE.listSize+1);
					SHAPE.size_.resize(SHAPE.listSize+1);
					SHAPE.r.resize(SHAPE.listSize+1);
					SHAPE.g.resize(SHAPE.listSize+1);
					SHAPE.b.resize(SHAPE.listSize+1);
					//set: 
				SHAPE.x[SHAPE.listSize-1]=SHAPE.pX;
				SHAPE.y[SHAPE.listSize-1]=SHAPE.pY;
					SHAPE.size_[SHAPE.listSize-1]=SHAPE.pointLineSize;
					SHAPE.r[SHAPE.listSize-1]=colorVal[0]/255;
					SHAPE.g[SHAPE.listSize-1]=colorVal[1]/255;
					SHAPE.b[SHAPE.listSize-1]=colorVal[2]/255;
				//draw: 
				count=1;
			}
			if(count==1){
				vecSize+=1;
				tempDrawWithMouse[0].resize(vecSize+1);
				tempDrawWithMouse[1].resize(vecSize+1);
				tempDrawWithMouse[0][vecSize-1]=SHAPE.rX-SHAPE.pX;
				tempDrawWithMouse[1][vecSize-1]=SHAPE.rY-SHAPE.pY;
				glNewList(SHAPE.listSize-1,GL_COMPILE);
					glBegin(GL_LINE_STRIP);
						for(int n=0;n<vecSize;n++){
							glVertex2f(tempDrawWithMouse[0][n],tempDrawWithMouse[1][n]);
						}						
					glEnd();
				glEndList();
			}
		}
	}
}
void mouseclick(int button, int state, int x, int y){
	if(count==1&&state==GLUT_UP){//this is specifically a case for drawing at the mouse;
		SHAPE.press=0;
		count=0;
		vecSize=1;
	}
	//press: how many times the mouse was clicked. 
	//mode: what object is currently being constructed. 
	if(SHAPE.press==0&&state==GLUT_DOWN){//start point;
		SHAPE.pX=x;SHAPE.pY=y;
		SHAPE.rX=x;SHAPE.rY=y;
		SHAPE.press=1;
	}
	else if(SHAPE.press==1&&state==GLUT_UP){
		if(SHAPE.pX>(BUTTON[0].x+BUTTON[0].width)&&SHAPE.rX>(BUTTON[0].x+BUTTON[0].width)&&SHAPE.mode!=5&&SHAPE.mode!=-1){//greater than the furthest button width: 
			SHAPE.listSize+=1;
			//resize: 
			SHAPE.listID.resize(SHAPE.listSize+1);
			SHAPE.x.resize(SHAPE.listSize+1);
			SHAPE.y.resize(SHAPE.listSize+1);
				SHAPE.size_.resize(SHAPE.listSize+1);
				SHAPE.r.resize(SHAPE.listSize+1);
				SHAPE.g.resize(SHAPE.listSize+1);
				SHAPE.b.resize(SHAPE.listSize+1);
			//set: 
			SHAPE.x[SHAPE.listSize-1]=SHAPE.pX;
			SHAPE.y[SHAPE.listSize-1]=SHAPE.pY;
				SHAPE.size_[SHAPE.listSize-1]=SHAPE.pointLineSize;
				SHAPE.r[SHAPE.listSize-1]=colorVal[0]/255;
				SHAPE.g[SHAPE.listSize-1]=colorVal[1]/255;
				SHAPE.b[SHAPE.listSize-1]=colorVal[2]/255;
			//draw: 
			glNewList(SHAPE.listSize-1,GL_COMPILE);
				glBegin(GL_POLYGON);
					if(SHAPE.mode==0){//square or rectangle
						glVertex2f(0,0);
						glVertex2f(SHAPE.rX-SHAPE.pX,0);
						glVertex2f(SHAPE.rX-SHAPE.pX,SHAPE.rY-SHAPE.pY);
						glVertex2f(0,SHAPE.rY-SHAPE.pY);
					}
					else if(SHAPE.mode==1){//circle
						for(int n=0;n<360;n++){
							glVertex2f(sin(n)*(SHAPE.rX-SHAPE.pX),cos(n)*(SHAPE.rX-SHAPE.pX));
						}
					}
					else if(SHAPE.mode==2){//triangle
						glVertex2f(0,0);
						glVertex2f(SHAPE.rX-SHAPE.pX,0);
						glVertex2f(SHAPE.rX-SHAPE.pX,SHAPE.rY-SHAPE.pY);
					}
					else if(SHAPE.mode==3){//line
						glBegin(GL_LINES);
						glVertex2f(0,0);
						glVertex2f(SHAPE.rX-SHAPE.pX,SHAPE.rY-SHAPE.pY);
					}
					else if(SHAPE.mode==4){//point
						glBegin(GL_POINTS);
						glVertex2f(SHAPE.rX-SHAPE.pX,SHAPE.rY-SHAPE.pY);
					}
				glEnd();
			glEndList();
		}
		SHAPE.press=0;
	}
	//buttons: 
	if(state==GLUT_UP){//MOUSE RELEASE FROM BUTTON: 
		for(int n=0;n<25;n++){//button collision: 
			if(x>BUTTON[n].x&&x<(BUTTON[n].x+BUTTON[n].width)&&y>BUTTON[n].y&&y<(BUTTON[n].y+BUTTON[n].height)){
				BUTTON_LOGIC(n);
				break;
			}
		}
	}
	if(SHAPE.mode==-1){//NOT DRAWING STUFF: 
		if(buttonSelected>=6&&buttonSelected<=8){//COLORS: 
			if(x>BUTTON[buttonSelected].x+(BUTTON[buttonSelected].width*.5)&&x<BUTTON[buttonSelected].x+BUTTON[buttonSelected].width){
				colorVal[buttonSelected-6]+=1;
				cout<<"up";
			}
			if(x<BUTTON[buttonSelected].x+(BUTTON[buttonSelected].width*.5)&&x>BUTTON[buttonSelected].x){
				colorVal[buttonSelected-6]-=1;
				cout<<"down";
			}
			if(colorVal[buttonSelected-6]>=255)colorVal[buttonSelected-6]=255;
			if(colorVal[buttonSelected-6]<=0)colorVal[buttonSelected-6]=0;
			SHAPE.press=1;
			buttonSelected=-1;
		}
		else if(buttonSelected==12){//COLOR PICKER: 
			if(SHAPE.press==1){
				GLubyte xx[3];
				glReadPixels(x,winH-y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&xx);
				//float color[3]={xx[0],xx[1],xx[2]};
				colorVal[0]=xx[0];
				colorVal[1]=xx[1];
				colorVal[2]=xx[2];
				buttonSelected=-1;
				//cout<<"(R: "<<color[0]<<", G: "<<color[1]<<", B: "<<color[2]<<");\n";
			}
		}
	}
}//end void;
void skeyd (int key, int x, int y){
}//end void;
void keyPressed(unsigned char key, int x, int y){//glutKeyboardFunc(keyPressed);
if(key=='w')SHAPE.pointLineSize+=1;
if(key=='q')SHAPE.pointLineSize-=1;
}//end void;
