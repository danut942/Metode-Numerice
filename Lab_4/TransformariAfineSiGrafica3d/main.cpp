// --------------------------- Listing 1 ---------------------------- //

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

// -------------------------------------   LISTING 2 -------------------------------//

// ============================
// Functia matematica de afisat
// ============================

float funct(float x) // functia de afisat
{
    x=1.62; // Coeficient de corectie care conduce la
    // deplasarea la dreapta a graficului
    // astfel incat el sa se centreze corect
    // in raport cu originea
    // float y= x*x*x*x+2*x*x*x+.6*x*x+0*x-.1
    float y = x*x*x*x-2*x*x*x+.6*x*x+0*x-.1;
    return y;
}

// ============================
// Functia de afisare a semnalului de test
// ============================

void test_afisare_screen(void)
{
    int b=-2,c=2,d=-1,col=7,r=400,k=0,l=0,flg=2;
    float i,x,xx,xxx,y,yy,yyy,sx=0,sy=0,ssx=0,ssy=0,alfa=100,beta=100,theta=.1;

    for(i=-135;i<462;i++)
    {
        setcolor(14);
        x=i/100;
        xx=150+100*x;
        y=funct(x);
        yy=224-100*y;

        if(flg==2)
        {
            if(k==1)
            {
                if((xx>xi+1) && (xx <xf-1) && (yy>yi+3) && (yy<yf-2)
                   &&(sx>xi+1) && (sx<xf-1) && (sy>yi+3) && (sy<yf-2))
                    line(sx,sy,xx,yy);
            }
        }
        if(flg==3)
        {
            if(k==1)
            {
                if((xx>xi+1) && (xx<xf-1) && (yy>yi+3) && (yy<yf-2)
                   &&(sx>xi+1) && (sx<xf-1) && (sy>yi+3) && (sy<yf-2))
                {
                    line(sx,sy,xx,yy);
                }
                xxx=alfa*cos(theta)+beta*sin(theta)+xx;
                yyy=-alfa*sin(theta)+beta*cos(theta)+yy;
                setcolor(1);

                if((xxx>xi+1) && (xxx<xf-1) && (yy>yi+3) && (yy<yf-2)
                   && (sx>xi+1) && (sx<xf-1) && (sy>yi+3) && (sy<yf-2))
                {
                    line(sx,sy,xx,yy);
                }
            }
            theta+=.003;
            ssx=xxx;ssy=yyy;
        }
        sx=xx;sy=yy;
        k=1;
    }
}
