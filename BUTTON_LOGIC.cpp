#include "includesVoids.h"
void BUTTON_LOGIC(int buttonNum){
	if(buttonNum==0){
		INIT_=true;INIT();//reset;
	}
	else if(buttonNum==1){
		SHAPE.mode=0;
	}
	else if(buttonNum==2){
		SHAPE.mode=1;
	}
	else if(buttonNum==3){
		SHAPE.mode=2;
	}
	else if(buttonNum==4){
		SHAPE.mode=3;
	}
	else if(buttonNum==5){
		SHAPE.mode=4;
	}
	else if(buttonNum==10){
		SHAPE.mode=5;
	}
		else if(buttonNum==6){//r
			SHAPE.mode=-1;
		}
		else if(buttonNum==7){//g
			SHAPE.mode=-1;
		}
		else if(buttonNum==8){//b
			SHAPE.mode=-1;
		}
		else if(buttonNum==9){//actual color
			SHAPE.mode=-1;
		}
		else if(buttonNum==12){//color picker
			SHAPE.mode=-1;
		}
	else if(buttonNum==24/*9*/){
		exit(0);
	}
	buttonSelected=buttonNum;
}
