#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>
void *buf;
void firstleft();
void secondleft();
int main()
{
    int gd=DETECT,gm;
    initgraph(&gm,&gd," ");
    rectangle(0,0,getmaxx(),getmaxy());
    arc(150,100,45,135,40);//head
    ellipse(103,75,10,280,20,20);//left ear
    ellipse(197,75,-100,160,20,20);//right ear
    arc(165,112,163,215,60);//left cheek
    arc(135,111,-35,17,60);//right cheek
    ellipse(120,160,82,290,33,15);//below left cheek
    ellipse(180,160,-110,100,33,15);  //below right cheek
    ellipse(140,117,65,230,25,35);//inside of left cheek
    ellipse(160,117,-55,115,25,35);  //inside of right cheek
    ellipse(150,160,195,-15,22,45);//mouth
    ellipse(135,110,0,0,10,15);//left eye ball
    ellipse(165,110,0,0,10,15);//right eye ball
    circle(150,135,10);//nose
    arc(150,140,210,-30,30);
    //inner eye balls of left eye
    ellipse(135,115,0,0,5,7);
    ellipse(135,117,0,0,2,3);
    
    
    //inner eye balls of right eye
    ellipse(165,115,0,0,5,7);
    ellipse(165,117,0,0,2,3);
    
    //filling color in inner eyeballs of both eye
    fillellipse(135,117,2,); 
    fillellipse(165,117,2,3);
    //fills color in nose
    setfillstyle(1,0);
    floodfill(150,135,20);
    //fills color in head
    setfillstyle(1,4);
    floodfill(150,100,15);
    
       int area=imagesize(165,115,165,117);//imagesize(409,224,444,261);determines the size of the memory area required to store a bit image
buf=malloc(area);//used for dynamic memory allocation
getimage(409,224,444,261,buf);//copies an image from the screen to memory.
int i=0;
while(!kbhit())
{
if(i==0)
{
setfillstyle(1,15);
setcolor(15);
ellipse(135,115,0,0,5,7);//left eye ball
ellipse(165,115,0,0,5,7);//right eye ball
setcolor(0);
ellipse(135,117,0,0,2,3);//left eye ball
ellipse(165,117,0,0,2,3);//right eye ball

floodfill(210,133,4);
floodfill(265,133,4);


setcolor(0);
putimage(391,209,buf,1);
firstleft();
setcolor(15);
secondleft();
putimage(409,224,buf,0);
i=1;
}
else
{
setfillstyle(1,0);
setcolor(0);
ellipse(135,115,0,0,5,7);//left eye ball
ellipse(165,115,0,0,5,7);//right eye ball

floodfill(210,133,4);
floodfill(265,133,4);

setcolor(15);
ellipse(135,117,0,0,2,3);//left eye ball
ellipse(165,117,0,0,2,3);//right eye ball

floodfill(210,133,4);
floodfill(265,133,4);

setcolor(0);
putimage(409,224,buf,1);
secondleft();
setcolor(15);
firstleft();
putimage(391,209,buf,0);//puts the bit image previously saved with getimage back onto the screen
i=0;
}
delay(300);
}


    getch();
    return 0;
}
void firstleft()
{
moveto(293,260);
lineto(353,276);
lineto(395,223);
moveto(293,280);
lineto(355,296);
lineto(395,245);
}
void secondleft()
{
moveto(293,260);
lineto(363,280);
lineto(413,240);
moveto(293,280);
lineto(363,300);
lineto(413,260);
}

