/*
--------------------------------
Modulul declaratiilor biblioteca
--------------------------------
*/

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int col =7, r=400;
float i, x, y, xx, yy, x1, x2, ax=1, ay=1, D=100, d=ay*D;

/*
--------------------
Modulul functii apel
--------------------
*/

void initializare_mod_grafic()
{
    int gd=DETECT, gm;
    initgraph (&gd, &gm, "");
}
void caroiaj()
{
    line(ax, r-200, ax*550, r-200); //Axa absciselor
    line (ax*150, r-400, ax*150, 480); //Axa ordonatelor
    circle (ax*150, r-200, 2); //Punctul (0,0)
    circle (ax*50, r-200, 2); //Punctul (-1,0)
    circle (ax*250, r-200, 2); //Punctul (1,0)
    circle (ax*150, r-300 + (D-d), 2); //Punctul (0,1)
    circle (ax*150, r-100 + (D-d), 2); //Punctul (0,-1)
}

void afisare_prima_bisectoare()
{
    i=0;
    x=i/100;
    xx=150+100*x;
    y=x;
    yy=200-100*y;
    moveto(ax*xx, yy);
    for(i=0;i<101;i++)
    {
        x=i/100;
        xx=150+100*x;
        y=x;
        yy=200-100*ay*y;
        lineto(ax*xx,yy);
    }
}

float f(float x)
{
    float y;
    y=x/2;
    return y;
}

float g(float x)
{
    float y;
    y=f(x)+x;
    return y;
}

void presentare_prim_punct()
{
    i=0;
    x=i/100;
    xx=150+100*x;
    y=f(x);
    yy=200-100*y;
    moveto(ax*xx, yy);
}

void afisare_grafic()
{
    for(i=0;i<101;i++)
    {
        x=i/100;
        xx=150+100*x;
        y=f(x);
        yy=200-100*ay*y;
        lineto(ax*xx, yy);
    }
}

void definire_interval()
{
    printf("\nIntrodu capetele intervalului:\nx1=");
    scanf("%f",&x1);
    printf("x2=");
    scanf("%f",&x2);
}

void calcul_solutie()
{

    float x0,xs,e=1,eps=0.000001,k=1;
    xs=(x1+x2)/2;
    while((e>eps)&&k)
    {
        k++;
        x0=xs;
        xs=g(xs);
        e=(double)fabs(xs-x0);
        if(e>1000000)
            k=0;
    }
    if(k)
        printf("\nSolutia este: %f",xs);
    else
        printf("\nAlgoritmul diverge!");
}

/*
--------------------------------
Modulul functie principala
--------------------------------
*/

int main()
{
    initializare_mod_grafic();

    //clrscr(); //Implicit LIGHTGRAY
    setcolor(RED);
    caroiaj();

    setcolor(YELLOW);
    afisare_prima_bisectoare();

    setcolor(BLUE);
    presentare_prim_punct();

    afisare_grafic();

    definire_interval();

    calcul_solutie();

    getch();

    return 0;
}
