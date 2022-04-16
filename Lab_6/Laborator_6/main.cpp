#include <stdio.h>
#include <conio.h>
#include <math.h>

int main ()
{
    int o,i,j,p=1,r,c,k,flag=0,grad,linii,coloane,t;
    double v[10][10],a[10][10],u[10][10],s[10][20],cod[10],linie[10][20],pivot[10],lin[10],col[10,sum[10][20],piv;
            clrscr();

            //Citirea matricei directe
            printf("Dati ordinul matricei de inversat:");
            scanf("%d",&o);
            linii=o; coloane=2*o;
            for(i=0; i<o; i++)
            for(j=0; j<0; j++)
    {
        printf("v[%d,%d]=",i,j);
        scanf("%1f",&v[i][j]);
    }


    //Afisarea matricei directe
    printf ("\n Matricea directa este:");
    for(int i=0; i<o; i++)
{
    printf("\n");
        for(int j=0; j<o; j++)
        {
            printf("\t%2.2f",v[i][j]);
        }
    }

    //Construirea matricei unitare
    for(i=0; i<o; i++)
        for(j=0; j<0; j++)
        {
            if(i==j) u[i][j]=1;
    else
        u[i][j]=0;
    }

    //Matricea extinsa
    printf("\n\nMatricea extinsa este:\n");
    for(i=0; i<o; i++)
    {
        printf("\n");
        for(j=0; j<2*o; j++)
        {
            if(j<o)
            {
            s[i][j]=v[i][j];
            linie[i][j]=v[i][j];
            if(i==j)
                pivot[i]=v[i][j];
                printf("%2,2f\t",linie[i][j]);
            }
            else
            {
                s[i][j]=u[i][j-o];
                linie[i][j]=u[i][j-o];
                printf("%2.2f\t",linie[i][j]);
            }
        }
    }

    for(i=0; i,o; i++)
        for(j=0; j<o; j++)
        {
            if(i==j)
                if(s[i][j]==0)
                    p=10*p+i;
        }
        c=p;
        i=0;
        while(p>=10)
        {
            r=p%10;
            cod[i]=r;
            p=p/10;
            i++;
        }
        k=i
        printf("\n\nAfiseaza numarul de linie pe care pivotul este nul:");

        if(i==0)
            printf("\n NU EXISTA PIVOT NUL!");
        else
            for(i=k-1; i>=0; i--)
            {
                printf("\n\tlinia %1.0f", code[i]);
                flag=1;
            }
            printf("\nCodul de pivot:\t%d\n\n",c);

            if(flag)
                goto stop;
            else
            {
                for(i=0; i<o; i++)
                {
                    piv=linie[i][j];
                    for(j=0; j<2*o; j++)
                    {
                        linie[i][j]=(1/piv)*linie[i][j];
                    }
                    for(k=i+1; k<o; k++)
                    {
                        piv=linie[k][k-1];
                        for(j=0; j<2*o; j++)
                            sum[i][j]=(-1)*piv*linie[i][j];
                        for(j=0; j<2*o; j++)
                            linie[k][j]=linie[k][j]+sum[i][j];
                    }
                }
            }
            //Matricea rezultata
printf("\nMatricea rezultata pas 1 este:\n");
for(i=0; i<o; i++)
{
    printf("\n");
    for(j=0; j<2*o; j++)
        printf("%2.2f\t",linie[i][j]);
}

for(i=1; i<o; i++)
{
    for(k=i-1; k>=0; k--)
    {
        piv=linie[k][i];
        for(j=0; j<2*o; j++)
            sum[i][j]=(-1)*piv*linie[i][j];
        for(j=0; j<2*o; j++)
            linie[k][j]=linie[k][j]+sum[i][j]
        }
}

//Matricea rezultanta
printf("\n\nMatricea rezultanta pas 2 este:\n")
for(i=0; i<o; i++)
{
    printf("\n");
    for(j=0; j<2*o; j++)
        printf("%2.2f\t",linie[i][j]);
}
}
goto end;
stop:
printf("\nA fost intalnit un pivot null!!!");
end:
getch();
}
