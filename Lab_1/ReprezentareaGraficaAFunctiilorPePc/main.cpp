//Exemplu de program de ridicare a graficului functiei polinomiale de grad 5

/*
--------------------------------
Modulul declaratiilor biblioteca
--------------------------------
*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

/*
--------------------------------
Modulul functii apel
--------------------------------
*/

float f (float x)
{
    float a=1.8, b=1.3, c=-3.9, d=1.6, e=1.0, g=0, y;
    y=a*x*x*x*x*x+b*x*x*x*x+c*x*x*x+d*x*x+e*x+g;
    return y;
}

/*
--------------------------------
Modulul functie principala
--------------------------------
*/

int main()
{
    int gd=DETECT, gm, col=7, r=400;
    float i, x, y, xx, yy, ax=1, ay=1, D=100, d=ay*D;

    system ("clear");

   // initgraph(&gd, &gm, "c:\Program Files\CodeBlocks\MinGW\x86_64-w64-mingw32\lib");
    initgraph(&gd,&gm,"d:\\borlandc\\bgi");
    system ("cls"); //Implicit LIGHGRAY

    setcolor(RED);
    line(ax, r-200,ax*550, r-200); // Axa absciselor
    line(ax*150, r-400,ax*150, 480); // Axa ordonatelor
    circle (ax*150, r-200, 2); // Punctul (0,0)
    circle (ax*50, r-200, 2); // Punctul (-1,0)
    circle(ax*250, r-200, 2); // Punctul (1,0)
    circle (ax*150, r-300+(D-d),2); // Punctul (0,1)
    circle (ax*150, r-100-(D-d),3); // Punctul (0,-1)

    setcolor(BLUE);
    i=-150;
    x=i/100;
    xx=150+100*x;
    y=f(x);
    yy=200-100*y;
    moveto(ax*xx,yy);

    for(i=-150;i<200;i++)
    {
        x=i/100;
        xx=150+100*x;
        y=f(x);
        yy=200-100*ay*y;
        lineto(ax*xx,yy);
    }

    getch();

    return 0;
}
