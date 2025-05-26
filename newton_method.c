#include <stdio.h>

#include <math.h>



int nf;



double funk_1(double x)

{

    nf++;

    return x*x*x+4*x*x-10;

}





double dfunk_1(double x)

{

    return 3*x*x+8*x;

}





double funk_2(double x)

{

    nf++;

    return x*x*x+4*x*x-15;

}





double dfunk_2(double x)

{

    return 3*x*x+8*x;

}





double funk_3(double x)

{

    nf++;

    return sin(x)*sin(x)-x*x+1;

}





double dfunk_3(double x)

{

    return sin(2*x)-2*x;

}



// newton

int root_newton(double* x,double x0,double(*f)(double),double(*df)(double),double epsilon)

{

    int k;

    double fx,dfx;



    *x=x0;

    for(k=1;k<1000;k++) // "ploxoe usloviye"

    {

        fx=f(*x);

        dfx=df(*x);

        if(fabs(dfx)<1e-15) return 0; // - deleniye na 2



        double x_new=*x-fx/dfx;



        if(fabs(x_new-*x)<epsilon)

        {

            *x=x_new;

            return k;

        }

        *x=x_new;

    }

    return 0; 

}



int main()

{

    double x;

    int res;

  

    nf = 0;

    printf("1) х^3+4x^2-10=0\n");

    res=root_newton(&x,2.0,funk_1,dfunk_1,1.e-15); // 1th priblijeniye 2.0

    if(res)

    {

        printf("x = %lg\nkolicestvo iteraciy  = %d\n",x,res);

        printf("cislo obraweniy k funkciyi = %d\n",nf);

        printf("abs error: %lg\n",fabs(x-1));

    }

    else

    {

        printf("metod ne primenim\n");

    }



    // 2

    nf=0;

    printf("\n2) x^3+4x^2-15=0\n");

    res=root_newton(&x,1.0,funk_2,dfunk_2,1.e-15);

    if(res)

    {

        printf("x = %lg\nkolicestvo iteraciy = %d\n",x,res);

        printf("cislo obraweniy k funkciyi = %d\n",nf);

        printf("abs error: %lg\n",fabs(x-0));

    }

    else

    {

        printf("metod ne primenim\n");

    }

    // 3

    nf = 0;

    printf("\n3)sin(x^2-x)=0\n");

    res = root_newton(&x,1.5,funk_3,dfunk_3,1.e-15);

    if(res)

    {

        printf("x = %lg\nkolicestvo iteraciy = %d\n",x,res);

        printf("cislo obraweniy k funkciyi  = %d\n",nf);

        printf("abs error: %lg\n",fabs(x-2));

    }

    else

    {

        printf("metod ne primenim\n");

    }

    return 0;

}

