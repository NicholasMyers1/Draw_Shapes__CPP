#include "includesVoids.h"
void INIT(){
	if(INIT_==true){
		//SHAPES
			SHAPE.press=0;
			SHAPE.pointLineSize=1;
			SHAPE.mode=-1;
			SHAPE.listSize=1;
				SHAPE.listID.resize(SHAPE.listSize);
				SHAPE.x.resize(SHAPE.listSize);
				SHAPE.y.resize(SHAPE.listSize);
					SHAPE.size_.resize(SHAPE.listSize);
					SHAPE.r.resize(SHAPE.listSize);
					SHAPE.g.resize(SHAPE.listSize);
					SHAPE.b.resize(SHAPE.listSize);
		//BUTTONS
			buttonSelected=-1;
			BUTTON[0].x=0;	BUTTON[0].y=0;		BUTTON[0].width=30;	BUTTON[0].height=20;	BUTTON[0].text="test";//reset		//50,75
			BUTTON[1].x=0;	BUTTON[1].y=25;		BUTTON[1].width=30;	BUTTON[1].height=20;	BUTTON[1].text="test";//square or rectangle
			BUTTON[2].x=0;	BUTTON[2].y=46;		BUTTON[2].width=30;	BUTTON[2].height=20;	BUTTON[2].text="test";//circle
			BUTTON[3].x=0;	BUTTON[3].y=67;		BUTTON[3].width=30;	BUTTON[3].height=20;	BUTTON[3].text="test";//triangle
			BUTTON[4].x=0;	BUTTON[4].y=88;		BUTTON[4].width=30;	BUTTON[4].height=20;	BUTTON[4].text="test";//line
			BUTTON[5].x=0;	BUTTON[5].y=109;	BUTTON[5].width=30;	BUTTON[5].height=20;	BUTTON[5].text="test";//point
			
			BUTTON[10].x=0/*100*/;	BUTTON[10].y=130/*400*/;	BUTTON[10].width=30/*50*/;	BUTTON[10].height=20/*75*/;	BUTTON[10].text="test";//create shape with cursor position;
			
				BUTTON[6].x=0;	BUTTON[6].y=480;	BUTTON[6].width=30;	BUTTON[6].height=10;	BUTTON[6].text="test";//color
				BUTTON[7].x=0;	BUTTON[7].y=495;	BUTTON[7].width=30;	BUTTON[7].height=10;	BUTTON[7].text="test";//color
				BUTTON[8].x=0;	BUTTON[8].y=510;	BUTTON[8].width=30;	BUTTON[8].height=10;	BUTTON[8].text="test";//color
					BUTTON[9].x=0;	BUTTON[9].y=525;	BUTTON[9].width=30;	BUTTON[9].height=10;	BUTTON[9].text="test";//color actual
					
				BUTTON[12].x=0;	BUTTON[12].y=546;	BUTTON[12].width=30;	BUTTON[12].height=20;	BUTTON[12].text="test";//color picker
				

	}		
			BUTTON[24].x=winW-50;	BUTTON[24].y=winH-75;	BUTTON[24].width=50;	BUTTON[24].height=75;	BUTTON[24].text="test";//exit//11
			
			//adding a new shape: add init, keymouse, button_logic, draw;button is n-1; starting at 1;
		INIT_=false;
	
}/*END INIT*/
