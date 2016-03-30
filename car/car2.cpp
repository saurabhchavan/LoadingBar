#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<alloc.h>
void   *buffer;
unsigned int size; 
int main()
{
	int gd=DETECT,gm;
	int i=0,m=0;
	initgraph(&gd,&gm,"..\\bgi");
    setbkcolor(1);
    setfillstyle(1,RED);
    setfillstyle(2,GREEN);
    while(!kbhit())
	{
		cleardevice();
		i++;
		if(i>getmaxx())
			i-=670;
		line(80+i,300,90+i,270); //1
		line(90+i,270,120+i,270);//2
		line(120+i,270,160+i,240);//3
		line(160+i,240,230+i,240);//4
		line(230+i,240,275+i,270);//5
		line(275+i,270,280+i,270);//6
		line(280+i,270,120+i,270);//vertical line
		line(280+i,270,335+i,270);//7
		line(335+i,270,335+i,300);//8
		line(255+i,300,335+i,300);//9
		line(180+i,300,210+i,300);//10
		line(80+i,300,135+i,300);//11
		//line(105,300,0,300);
		arc(232+i,300,0,180,23);
		arc(157+i,300,0,180,23);
		circle(232+i,300,18);
		circle(157+i,300,18);
		pieslice(232+i,300,0+m,90+m,18);
		pieslice(232+i,300,180+m,270+m,18);
		pieslice(157+i,300,0+m,90+m,18);
		pieslice(157+i,300,180+m,270+m,18);
		if(m<-360)
			m=90;
		m-=3;	
	delay(1);
	}
	setbkcolor(WHITE);
    settextstyle(2,0,10);
    outtextxy(0,200,"MOVING CAR");
	getch();
	closegraph();
}
