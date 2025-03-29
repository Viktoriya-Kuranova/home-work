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
 
*x1_p=-(b+sign(b)*sqrt(d))/2;
 *x2_p=c/ *x1_p;
 return 1;
 }
 
 int main()
 {
   double x1,x2,b,c,x1_p,x2_p;
   printf("‚¢¥¤¨â¥ ª®à­¨ ãà ¢­¥­¨ï:\n");
   scanf("%lg %lg", &x1,&x2);	
   	
   if(fabs(x1)<fabs(x2))
   {
	   double t=x2;
	   x2=x1;
	   x1=t;
	}
	
   b=-(x1+x2);
   c=x1*x2;
   
   kvadr(b,c,&x1_p,&x2_p);
   
   printf("à¨¡«¨§¨â¥«ì­ë¥ ª®à­¨ ãà ¢­¥­¨ï: %lf %lf\n ", x1_p,x2_p);
   
   printf("€¡á®«îâ­ ï ¯®£à¥è­®áâì 1-£® ª®à­ï: %lf\n", abs_error(x1, x1_p));
   printf("€¡á®«îâ­ ï ¯®£à¥è­®áâì 2-£® ª®à­ï: %lf\n", abs_error(x2, x2_p));
   printf("Žâ­®á¨â¥«ì­ ï ¯®£à¥è­®áâì 1-£® ª®à­ï: %lf\n", rel_error(x1, x1_p));
   printf("Žâ­®á¨â¥«ì­ ï ¯®£à¥è­®áâì 2-£® ª®à­ï: %lf\n", rel_error(x2, x2_p));
 }

