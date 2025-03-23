 #include <stdio.h>
#include <math.h>

int sign(double x)
{
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
double abs_error(double x, double x_p)
{
  return fabs(x-x_p);
  
}
double rel_error(double x, double x_p)
{
  return fabs(x_p/x -1);
  
}
 int kvadr(double b, double c, double *x1_p, double *x2_p)
 {
 double d;
 d=b*b-4*c;
 if(d<0) return 0;
 
*x1_p=(-b+sign(b)*sqrt(d))/2;
 *x2_p=c/ *x1_p;
 return 1;
 }
 
 int main()
 {
   double x1,x2,b,c,x1_p,x2_p;
   printf("Введите корни уравнения:\n");
   scanf("%lg %lg", &x1,&x2);	
   	
   if(x1>x2)
   {
	   double t=x2;
	   x2=x1;
	   x1=t;
	}
	
   b=-(x1+x2);
   c=x1*x2;
   
   kvadr(b,c,&x1_p,&x2_p);
   
   printf("Приблизительные корни уравнения: %lf %lf\n ", x1_p,x2_p);
   
   printf("Абсолютная погрешность 1-го корня: %lf\n", abs_error(x1, x1_p));
   printf("Абсолютная погрешность 2-го корня: %lf\n", abs_error(x2, x2_p));
   printf("Относительная погрешность 1-го корня: %lf\n", rel_error(x1, x1_p));
   printf("Относительная погрешность 2-го корня: %lf\n", rel_error(x2, x2_p));
 }

