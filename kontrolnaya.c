#include <stdio.h>

#include <stdlib.h>

#include <math.h>



int main()

{

   double b;

    FILE *fX = fopen("input1.txt", "r");

    FILE *fY = fopen("input2.txt", "r"); 

    int n1;

  fscanf(fX,"%d",&n1);

  int n2;

  fscanf(fY,"%d",&n2);

  if(n1!=n2)

  {

	   printf("matrici nelzya slojit\n");

	   return 0; 

  }  

    double *x = (double*)malloc(n1 * n1 * sizeof(double)); 

    double *y = (double*)malloc(n2 * n2 * sizeof(double)); 

    double *sum = (double*)malloc(n1 * n1 * sizeof(double));

   

    FILE *fRESULT = fopen("output.txt", "w"); 

    if (fX == NULL || fY == NULL) 

    {

        printf("Error opening files.\n");

        return 1;

    } 

   double b;

   int k1=0,k2=0;

   

    for (int i = 0; i < n1; i++) 

    {

        for (int j = 0; j < n1; j++) 

        {

           if( fscanf(fX, "%lf", &x[i * n1 + j])==1 ) k1++;

        }

    }

if(k1<n1*n1)

{

	printf("v matrice X nedostatocno elementov");

	return 2;

}

      

    for (int i = 0; i < n2; i++) 

    {

        for (int j = 0; j < n2; j++) 

        {

            if(fscanf(fY, "%lf", &y[i * n2 + j])==1 ) k2++;

        }

    }



   if(k2<n2*n2)

{

	printf("v matrice Y nedostatocno elementov");

	return 3;

}



    double a=y[0];

    

    for(int i = 1 ;i < n2*n2; i++)

    {   

		if(fabs(a)<fabs(y[i]))

		a=y[i];

	}

	

	for(int i = 0; i < n1; i++)

    {

	   b+=x[i];

	}

    

    for (int i = 0; i < n1; i++) 

    {

        for (int j = 0; j < n1; j++) 

        {

            x[i * n1 + j] *=a;

        }

    }

    

     for (int i = 0; i < n2; i++) 

     {

        for (int j = 0; j < n2; j++) 

        {

            y[i * n2 + j] *=b;

        }

    }

    

        for (int i = 0; i < n1; i++) 

    {

        for (int j = 0; j < n1; j++)

        {

			 sum[i * n1 + j] = x[i * n1 + j] + y[i * n2 + j];

		}	 

    }



    for (int i = 0; i < n1; i++) 

    {

        for (int j = 0; j < n1; j++)

        {

            fprintf(fRESULT,"[%lg] ", sum[i * n1 + j]);

        }

        fprintf(fRESULT,"\n");

    }

    return 0;

}

