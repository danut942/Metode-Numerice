/*==============================
Modulul declaratiilor biblioteca
===============================*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<iostream>
#include<stdlib.h>
/*=========================
Modulul functie principala
==========================*/

int main()
{
    double i, j,x,y,dist,p, L, N=10000, M=10000,m, pi=M_PI, med=0;
    system("cls");
  //  randomize();
    printf("\n\n\nValoarea acceptata pentru PI: \t\t%f",pi);
    printf ("\tASTEAPTA!");
    for(j=0; j<M; j++)
    {
        L=0;
        for (i=0; i<N; i++)
        {
            x= (double) (rand() %1000) /1000;
            y= (double) (rand() %1000) /1000;
            dist= (double) sqrt (x*x+y*y);
            if (dist<1)
                L++;
        }
        p=4*L/N;
        med+=p;
    }
    system("cls");

    printf("\n\n\nValoarea acceptata pentru PI: \t\t%f",pi);
    med=med/M;
    printf ("\n\n\nPrin metoda Monte Carlo: \t\t%f",med) ;
    printf ("\tASTEAPTA !");
    x=0;
    y=0;
    L=0;
    for(j=0; j<M; j++)
    {
        x=0;
        for (i=0; i<N; i++)
        {
            x=i/N; // printf("\n\n\n\t\t\t%f",x);
            y=j/M;
            dist= (double) sqrt (x*x+y*y);
            if (dist<=1)
                L++;
        }
    }
    p=4*L/N/M;
    system("cls");

    printf("\n\n\nValoarea acceptata pentru PI: \t\t%f",pi);
    printf("\n\n\nPrin metoda Monte Carlo: \t\t%f",med);
    printf("\n\n\nPrin metoda euristica: \t\t\t%f",p);
    printf ("\tAPASA ENTER!");
    getch();
}
