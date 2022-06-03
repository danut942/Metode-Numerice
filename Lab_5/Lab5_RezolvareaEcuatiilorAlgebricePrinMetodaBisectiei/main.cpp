// Exemplu de aplicatie ce utilizeaza algoritmul bisectiei

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int col=7,r=400;
float i,x,y,xx,yy,x1,x2,ax=1,ay=1,D=100,d=ay*D;

/*
---------------------
Modulul functii apel
---------------------
*/

void initializare_mod_grafic()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"d:\\borland\\bgi");
}

void caroiaj()
{
    line(ax,r-200,ax*550,r-200); //Axa absciselor
    line(ax*150,r-400,ax* 150,480); //Axa ordonatelor
    circle(ax* 150,r-200,2); //Punctul (0,0)
    circle(ax*50,r-200,2); //Punctul (-1,0)
    circle(ax*250,r-200,2); //Punctul (1,0)
    circle(ax*150,r-300+(D-d),2); //Punctul (0,1)
    circle(ax*150,r-100-(D-d),2); //Punctul (0,-1)
}
float f(float x)
{
    float y;
    y=cos(x);
    return y;
}

void presetare_prim_punct()
{
    i=-140;
    x-i/100;
    xx=150+100*x;
    y=f(x);
    yy=200-100*y;
    moveto(ax*xx,yy);
}

void afisare_grafic()
{
    for(i=-140; i<401; i++)
    {
        x=i/100;
        xx=150+100*x;
        y=f(x);
        yy=200-100*ay*y;
        lineto(ax*xx,yy);
    }
}

void definire_interval()
{
    printf("\nIntrodu capetele intervalului: \na=");
    scanf("%f",&x1);
    printf("b=");
    scanf("%f",&x2);
}

void calcul_solutie()
{
    float a,b,c,e1,e2,x0,xs,eps1=0.001,eps2=0.001,k=1;
    a=x1;
    b=x2;
    c=(x1+x2)/2;
    if(fabs(f(a))<eps1)
        xs=a;
    if(fabs(f(b)) <eps1)
        xs=b;
    if(fabs(f(c))<eps1)
        xs=c;
    if(fabs(a-b)<eps2)
        xs=a;
    e1=fabs(f(c));
    e2=fabs(b-a);
    while((e1>eps1)&&(e2>eps2)&&(k<1000))
    {
        k++;
        if((f(a)*f(c)) <0)
            b=c;
        else
            a=c;
        c=(a+b)/2;
        xs=c;
        e1=fabs(f(c));
        e2=fabs(b-a);
        if(k<1000)
            printf("\nSolutia este: %f",xs);
        else
            printf("\n\n\n\t\t\tNu exista solutie pe acest interval!");
    }
}

/*
==============================
    Modulul functie principala
==============================
*/
int main()
{
    initializare_mod_grafic();
    system("cls"); //Implicit LIGHTGRAY
    setcolor(RED);
    caroiaj();
    setcolor(BLUE);
    presetare_prim_punct();
    afisare_grafic();
    definire_interval();
    calcul_solutie();
    getch();
}

