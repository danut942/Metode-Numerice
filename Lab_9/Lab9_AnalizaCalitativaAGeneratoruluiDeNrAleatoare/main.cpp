/*=========================== Listing 1 ==========================*/

//Exemplu de program de test a generatorului de numere aleatoare
//G. Mahalu aprilie 2006
/*==============================
Modulul declaratiilor biblioteca
===============================*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>
//
///*==========================
//Modulul functie principala
//===========================*/
//int main()
//{
//int i;
//system("cls");
////randomize();
//for (i=0; i<100; i++)
//printf ("%d\t", rand () %100);
//getch();
//}

/*=========================== Listing 2 ==========================*/

//Exemplu de program pentru studiul repartitiei primelor cifre semnificative
//G. Mahalu aprilie 2006
/*
Modulul declaratiilor biblioteca
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<iostream>
#include<time.h>
int col=7, r=400;
float i, j=0, ax=1, ay=1, x0=ax*150,yo=200, x, y, xx,yy, x1=x0+60, x2, y1=y0+80, y2, D=100, d=ay*D;

/*==================
Modulul functii apel
==================*/
void initializare_mod_grafic ()
{
    int gd=DETECT, gm;
    initgraph (&gd, &gm, "d:\\borlandc\\bgi");
// initgraph (&gd, & gm, "d: \\tc\\bgi");
}

void axe ()
{
    line (ax, r-200, ax*550, r-200); //Axa absciselor
    line (ax*150, 1-400, ax*150, 480); //Axa ordonatelor
    line (ax, r-201, ax*550, r-201); //Axa absciselor
    line (ax*150+1, r-400, ax*150+1, 480); //Axa ordonatelor
    line (ax, r-199, ax*550, r-199); //Axa absciselor
    line (ax*150-1, r-400, ax*150-1, 480); //Axa ordonatelor
}

void caroiaj ()
{
    circle (x0, y0,3); //Punctul (0,0)
    circle (ax*50, r-200, 2); //Punctul (-1,0)
    circle (ax*160,1-200, 2); //Punctul (1,0)
    circle (ax*250,r-200, 2); //Punctul (10,0)
    circle (ax*350, r-200, 2); //Punctul (100,0)
    circle (ax*450, r-200,2); //Punctul (1000,0)
    circle (ax*550, r-200, 2); //Punctul (10000,0)
    circle (ax*150, r-300+ (D-d), 2); //Punctul (0,1)
    circle (ax *150, r-100-(D-d), 2); //Punctul (0,-1)
    for (i=-100; i<110; i+=10)
        line (ax, r-200+i, ax*550, r-200+i); //Linii orizontale de caroiaj
    for (i=-100; i<410; i+=10)
        line (ax*150+i, r-300, ax*150+i, r-100); //Linii verticale de caroiaj
}

float prob (float x)
{
    float p;
    if (x<5)
        p=1;
    if (4<x&&x<10)
        p=4/x;
    if (9<x&&x<50)
        p=(x-5) /x;
    if (49<x&&x<100)
        p=44/x;
    if (99<x&&x<500)
        p= (x-55)/x;
    if (499<x&&x<1000)
        p=444/x;
    if (999<x&&x<5000)
        p= (x-555)/x;
    if (4999<x&&x<10000)
        p=4444/x;
    return p;
}

/*
Modulul functie principala
*/
void main(void)
{
    int gd-DETECT, gm;
    float p,s, theta=0, mod, unu, doi;
    double rez;
    char c;
jump:
    initializare_mod_grafic ();
    clrscr();
    setcolor (BLACK) ;
    caroiaj ();
    setcolor (RED);
    axe ();
    setcolor (WHITE);
    cout<<"Doriti scara normala sau logaritmica? <n/1>";
    cin>>&c;
    if (c=='n')
    {
        moveto (x0, y0);
        for (8-1; s<10000; s++)
        {
            p=prob (s);
            rez=s;
            lineto (rez+x0, y0-100*p);
        }
        else
        {
            moveto (x0, y0);
            for (s=1; s<10000; s++)
            {
                p=prob (s);
                rez-log10 (s);
                lineto (rez*100+x0, y0-100*p);
            }
            cout<<"Doriti reluarea programului? <d/n>";
            cin>>&c;
            if (c=='d')
                goto jump;
        }
