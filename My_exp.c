#include <stdio.h>
#include <math.h>
double my_exp(double x)
{
double sum=1.0, h, eps=1.e-16; int i=2;
h=x;
do
{
sum+=h;
h*=x/i;
i++;
}
while( fabs(h)>eps );
return sum;
}
int main ()
{ 
	double x,y1,y2,abs,otn;
	FILE*fp=fopen("output.txt","w");
	double mas[]={5,10,24,50,-5,-10,-24,-50,-72};
	fprintf(fp,"  x       exp(x)         Абс.погреш.     Относ.погреш.\n");
	fprintf(fp,"-------------------------------------------------------------\n");
	for(int i=0;i<9;i++)
	{
		x=mas[i];
		if(x<0){
			y1=1/my_exp(-x);
			}
		else 
		y1=my_exp(x);
		y2=exp(x);
		abs=fabs(y2-y1);
		otn=fabs((y2-y1)/y2);
		fprintf(fp,"%5.1lf |  %10.5le |  %12.7le |  %12.7le\n",x,y2,abs,otn);
	}
	return 0;
	}
