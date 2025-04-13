#include <stdio.h>
#include <math.h>

double gauss2(double a, double b,double (*f)(double))
{
    double x1=(a+b)/2 - (b-a)/(2*sqrt(3.0));
    double x2=(a+b)/2 + (b-a)/(2*sqrt(3.0));
    return (b-a)/2 * (f(x1)+f(x2));
                                                                      }
double func_1(double x)
{
  return sin(x);
	                   }
	                   
double func_2(double x)
{
  return 1.0 / x;
		                }

double func_3(double x)
{
  return 10.0/(1.0 +25.0*x*x);
			                                 }
double true_integral1(double a,double b) 
{
   return -cos(b)+cos(a);
                                     }
double true_integral2(double a,double b) 
{
   return log(fabs(b))-log(fabs(a));
                                                  }
double true_integral3(double a,double b) 
{
  return 2*atan(5*b)-2*atan(5*a);
                                                  }

int main()
{
	double a,b; double h;double t,error;  int N;
	double app=0.0;
	a=0; b=2*M_PI; 
	N=10;
	h=(b-a)/(N-1);
	t=true_integral1(a,b);
	   while(a<b)
	  {
		app+=gauss2(a,a+h,func_1);
		a+=h;
		                                            }
		error=fabs(t-app);
	printf("sinx:        priblizitelno: %.6f        tochno: %.6f       error: %.6f\n\n",app,t,error);
	a=1; b=2;
	h=(b-a)/(N-1); app=0.0;
	t=true_integral2(a,b);
	   while(a<b)
	  {
		app+=gauss2(a,a+h,func_2);
		a+=h;
		                                            }
		error=fabs(t-app);
		printf("1/x:         priblizitelno: %.6f        tocno: %.6f       error: %.6f\n\n",app,t,error);
		
		
		a=-1; b=1;
		h=(b-a)/(N-1); app=0.0;
		t=true_integral3(a,b);
		 while(a<b)
	    {
		  app+=gauss2(a,a+h,func_3);
		  a+=h;
		                                             }
		error=fabs(t-app);
		printf("10/(1+25*x^2):         priblizitelno: %.6f        tocno: %.6f       error: %.6f\n\n",app,t,error);
		
   return 0;
}
