 #include <stdio.h>
 #include <math.h>
 int nf; 
 
 double funk_1(double x)
 {
	 nf++;
	 return x*x*x+4*x*x+cos(x-1)-6;
 }
 
  double funk_2(double x)	 
{
	nf++;
	return atan(x);
}

 double funk_3(double x)
{
	nf++;
	return x*x+3*x-10;	
}


 int sign(double x)
 {
 if(x>0) return 1;
 else if(x<0) return-1;
 return 0;
 }
 
 int root_chords(double *x, double a, double b,
 double (*f)(double), double epsilon)
 {
 double fa,fb,fc,c[2];
 int i=0,ifa,ifb,ifc,k;
 c[0]=a; c[1]=b; fa=f(a); fb=f(b);
 
 if(fabs(fa)<epsilon){*x=a; return 1;}
 if(fabs(fb)<epsilon){*x=b; return 1;}
 ifa=sign(fa); ifb=sign(fb);
 if(ifa*ifb !=-1) return 0;
 for(k=1; fabs(c[1]-c[0])>epsilon; k++)
 {
    i=!i;
   c[i]=(a*fb-b*fa)/(fb-fa);
   fc=f(c[i]); ifc=sign(fc);
 
 if(fabs(fc)<epsilon)
    {
		*x=c[i]; return k+1;
	}

     if(ifc*ifa==1)
     {
		 a=c[i]; fa=fc;
     }
 else
  {
	  b=c[i]; fb=fc;
  }
 }
 *x=c[i]; 
 return k; 
 }
 
 int main()
 {
 double x; int res;
 nf=0;
 printf("1) x^3+4x^2+cos(x-1)-6=0\n");
 res=root_chords(&x,0.5,3,funk_1,1.e-15);
 if(res)
 {
 printf("x=%lg\n число итераций=%d\n",x,res-1);
 printf("число обращений к функции=%d\n",nf);
 printf("абсолютная погрешность:%lg\n",fabs(x-1));
 printf("абсолютная погрешность:%lg\n",fabs((x-1)/1));
 }
 else
 {
 printf("метод не применим\n");
 }
 nf=0;
  printf("2) arctg(x)=0\n");
  res=root_chords(&x,-2,2,funk_2,1.e-15);
 if(res)
 {
 printf("x=%lg\n число итераций=%d\n",x,res-1);
 printf("число обращений к функции=%d\n",nf);
 printf("абсолютная погрешность:%lg\n",fabs(x-0));
 printf("абсолютная погрешность:%lg\n",fabs((x-0)/0));
 }
 else
 {
 printf("метод не применим\n");
 }
 
  nf=0;
  printf("3) x^2+3x-10=0\n");
  res=root_chords(&x,0,2,funk_3,1.e-15);
 if(res)
 {
 printf("x=%lg\n число итераций=%d\n",x,res-1);
 printf("число обращений к функции=%d\n",nf);
 printf("абсолютная погрешность:%lg\n",fabs(x-2));
 printf("абсолютная погрешность:%lg\n",fabs((x-2)/2));
 }
 else
 {
 printf("метод не применим\n");
 }
 return 0;
 }












