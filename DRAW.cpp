#include "includesVoids.h"
void DRAW3D(){
}
void DRAW2D(){
	for(int n=0;n<25;n++){//BUTTONS;
		glLoadIdentity();
		glTranslatef(BUTTON[n].x,BUTTON[n].y,0);
			glColor3f(0,0,0);
			if(buttonSelected==n)glColor3f(.2,1,.2);
			if(n==6)glColor3f(1,0,0);
			if(n==7)glColor3f(0,1,0);
			if(n==8)glColor3f(0,0,1);
			if(n==9){glColor4f(colorVal[0]/255,colorVal[1]/255,colorVal[2]/255,1);}
			glBegin(GL_POLYGON);
				glVertex2f(0,0);
				glVertex2f(BUTTON[n].width,0);
				glVertex2f(BUTTON[n].width,BUTTON[n].height);
				glVertex2f(0,BUTTON[n].height);
			glEnd();
			glTranslatef(BUTTON[n].width*.5,BUTTON[n].height*.3,0);//.5,.5
			glBegin(GL_POLYGON);
			glColor3f(1,0,1);
				if(n==1){//square or rectangle;
					glVertex2f(-5,-5);
					glVertex2f(-5,5);
					glVertex2f(5,5);
					glVertex2f(5,-5);
				}
				if(n==2){//circle;
					for(int m=0;m<360;m++){
						glVertex2f(sin(m)*(5),cos(m)*(5));
					}
				}
				if(n==3){//triangle
					glVertex2f(0,0);
					glVertex2f(5,10);
					glVertex2f(-5,10);
				}
				if(n==4){//line
					glBegin(GL_LINES);
						glVertex2f(5,10);
						glVertex2f(-5,10);
				}
				if(n==5){//point
					glBegin(GL_POINTS);
						glVertex2f(0,0);
				}
				if(n==10){//move with cursor
					glBegin(GL_POINTS);
						glVertex2f(0,0);
				}
				if(n==24){//exit//11
					glBegin(GL_LINES);
						glVertex2f(-5,-5);
						glVertex2f(5,5);
					glEnd();
					glBegin(GL_LINES);
						glVertex2f(-5,5);
						glVertex2f(5,-5);
				}
			glEnd();
	}
	for(int n=0;n<SHAPE.listSize;n++){//SHAPES;
			glLoadIdentity();
				glPointSize(SHAPE.size_[n]);
				glLineWidth(SHAPE.size_[n]);
				glColor3f(SHAPE.r[n],SHAPE.g[n],SHAPE.b[n]);
				glTranslatef(SHAPE.x[n],SHAPE.y[n],0);
			glCallList(n);
				glPointSize(1);
				glLineWidth(1);
	}
	if(SHAPE.press==1){//draw the preview: 
		glLoadIdentity();
		glColor3f(0,1,1);
			glBegin(GL_POLYGON);
				if(SHAPE.mode==0){//square or rectangle;
					glVertex2f(SHAPE.pX,SHAPE.pY);
					glVertex2f(SHAPE.pX,SHAPE.rY);
					glVertex2f(SHAPE.rX,SHAPE.rY);
					glVertex2f(SHAPE.rX,SHAPE.pY);
				}
				else if(SHAPE.mode==1){//circle;
					for(int n=0;n<360;n++){
						glVertex2f(SHAPE.pX+sin(n)*(SHAPE.rX-SHAPE.pX),SHAPE.pY+cos(n)*(SHAPE.rX-SHAPE.pX));
					}
				}
				else if(SHAPE.mode==2){//triangle;
					glVertex2f(SHAPE.pX,SHAPE.pY);
					glVertex2f(SHAPE.rX,SHAPE.rY);
					glVertex2f(SHAPE.rX,SHAPE.pY);
				}
				else if(SHAPE.mode==3){//line;
					glBegin(GL_LINES);
						glVertex2f(SHAPE.pX,SHAPE.pY);
						glVertex2f(SHAPE.rX,SHAPE.rY);
				}
				else if(SHAPE.mode==4){//point;//not needed?
					glBegin(GL_POINTS);
						glVertex2f(SHAPE.pX,SHAPE.pY);
				}
				else if(SHAPE.mode==5){//move with shape;//not needed?
					glBegin(GL_POINTS);
						glVertex2f(SHAPE.pX,SHAPE.pY);
				}
			glEnd();
	}
}
