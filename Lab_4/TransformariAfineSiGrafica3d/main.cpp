#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

using namespace std;

int col=7,r=400;
float Y0=200;
float i,j=0,ax=1,ay=1,x0=ax*150,x,y,xx,yy,x1=x0+60,x2,Y1=Y0+80,y2,D=100,d=ay*D;

void initializare_mod_grafic()
{

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"d:\\borlandc\\bgi");
}

void axe()
{
    line(ax,r-200,ax*550,r-200); //axa absciselor
    line(ax*150,r-400,ax*150,480);  //axa ordonatelor
    line(ax,r-201,ax*550,r-201);//axa absciselor
    line(ax*150+1,r-400,ax*150+1,480); //axa ordonatelor
    line(ax,r-199,ax*550,r-199);    //axaabsciselor
    line(ax*150-1,r-400,ax*150-1,480);  //axa ordonatelor
}

void caroiaj()
{
    circle(x0,Y0,3);    //punctul(0,0)
    circle(ax*50,r-200,2);
    circle(ax*250,r-200,2);
    circle(ax*150,r-300+(D-d),2);
    circle(ax*150,r-100-(D-d),2);
    for(i=-100;i<110;i+=10)
    {
        line(ax*150+i,r-300,ax*150+i,r-100);
    }
}


int main()
{
    int gd=DETECT,gm;
    float theta=0,mod,unu,doi;
    initializare_mod_grafic();
    setcolor(LIGHTGRAY);
    caroiaj();
    setcolor(YELLOW);
    axe();
    setcolor(WHITE);
    for(theta=0;theta<6.28;theta+=.1)
    {

        x2=(x1-x0)*cos(theta)+(Y1-Y0)*sin(theta)+x0;
        y2=-(x1-x0)*sin(theta)+(Y1-Y0)*cos(theta)+Y0;
        line(x0,Y0,x1,r-Y1);
        line(x0,Y0,x2,r-y2);
        delay(100);
    }
    setcolor(BLACK);
    for(theta=0;theta<6.28;theta+=.1)
    {
        x2=(x1-x0)*cos(theta)+(Y1-Y0)*sin(theta)+x0;
        y2=-(x1-x0)*sin(theta)+(Y1-Y0)*cos(theta)+Y0;
        line(x0,Y0,x1,r-Y1);
        line(x0,Y0,x2,r-y2);
        delay(100);
    }
    setcolor(LIGHTGRAY);
    caroiaj();
    setcolor(YELLOW);
    axe();
    for(theta=0;theta<6.28;theta+=.1)
    {
        setcolor(WHITE);
        x2=(x1-x0)*cos(theta)+(Y1-Y0)*sin(theta)+x0;
        y2=-(x1-x0)*sin(theta)+(Y1-Y0)*cos(theta)+Y0;
        line(x0,Y0,x1,r-Y1);
        line(x0,Y0,x2,r-y2);
        delay(100);
        setcolor(BLACK);
        line(x0,Y0,x1,r-Y1);
        line(x0,Y0,x2,r-y2);
    }
    setcolor(LIGHTGRAY);
    caroiaj();
    setcolor(YELLOW);
    axe();



    return 0;
}
