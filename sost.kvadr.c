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
    double (*functions[])(double)={func_1,func_2,func_3};
    double (*true_integrals[])(double,double)={true_integral1,true_integral2,true_integral3};
    const char *vivod[]={"sin(x)", "1/x", "10/(1+25x^2)"};
	
	
 for (int i=0;i<3;i++)
{
        double a,b;
        int N;

        printf("function: %s\n",vivod[i]);
        printf("enter a and b:  ");
        scanf("%lf %lf", &a,&b);

        printf("enter N:  ");
        scanf("%d",&N);

        double h=(b - a)/(N - 1);
        double app=0.0;
        double x=a;

        while(x<b)
      {
            app+=gauss2(x,x+h,functions[i]);
            x+=h;
      }
      double t=true_integrals[i](a,b);
      double error=fabs(t - app);

        printf("%s  app: %.6f   exacly: %.6f   error: %.6f\n\n",vivod[i], app, t, error);
 }
	
return 0;
} 
