// Listingul 1
float beta(float x,float xivect,float xkvect,int i,int k)
{
float y;
if(xkvect!=xivect)
{
y=(x-xivect)/(xkvect-xivect);
return y;
}
else return 1;
}

float alfa(float x,float xvect, int k)
{
int i;
float y=1;
for(i=0;i<n;i++)
if(i!=k)
y-y*beta(x,xv[i],xv[k],i,k);
return y;
}

float funct(float x) // FUNCTIA DE AFISAT
{
int k;

xv[0]=-3.000; xv[1]=-2.500; xv[2]=-2.000; xv[3]=-1.500; xv[4]-1.000;
yv[0] +0.900; yv[1]=+0.625; yv[2] +0.400; yv[3] +0.225; yv[4] +0.100;

xv[5]=-0.500; xv[6]=+0.000; xv[7]=+1.000; xv[8]=+2.000; xv[9]=+3.000;
yv[5]=+0.025; yv[6]=-0.000; yv[7]=+0.100; yv[8]=+0.500; yv[9]=+0.900;

float y=0;
for(k=0;k<n;k++)
y=y+yv[k]*alfa(x,xv[k],k);

return y;
}
