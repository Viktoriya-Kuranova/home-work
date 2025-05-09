#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n;
   printf("matrix size: ");
   scanf("%d", &n);
   double *a=(double*)malloc(n*n*sizeof(double));
   int i=0,j=0;
   
  printf("matrix written by rows:\n");
   for(i=0;i<n;i++)
   {
	   for(j=0;j<n;j++) a[i*n+j]=1.0/(1+i+j);
	  
	  a[i*n+i]+=1;
	}
	for(i=0;i<n;i++)
   {
	   for(j=0;j<n;j++) printf("[%lg]",a[i*n+j]);
	  
	  printf("\n");	
	}
	 printf("\n");	

	 printf("matrix written by columns:\n");
	 
    for(i=0;i<n;i++)
   {
	   for(j=0;j<n;j++) a[j*n+i]=1.0/(1+i+j);
	  
	  a[i*n+i]+=1;
	}
	
	for(i=0;i<n;i++)
   {
	   for(j=0;j<n;j++) printf("[%lg]",a[j*n+i]);
	  
	  printf("\n");	
	}
	 printf("\n");	
	 
	 
	 
	 
	 
return 0;
}
