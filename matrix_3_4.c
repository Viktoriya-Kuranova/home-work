#include <stdio.h>
#include <stdlib.h>
int main()
{
   int n;
   printf("matrix size: ");
   scanf("%d", &n);
   int i=0,j=0;
   double **a=(double**)malloc(n*sizeof(double*));
   for(i=0;i<n;i++) a[i]=(double*)malloc(n*sizeof(double));
 
    printf("matrix written by rows:\n");
   for(i=0;i<n;i++)
  {
	 for(j=0;j<n;j++)a[i][j]=1.0/(1+i+j);
	a[i][i]+=1;
	  
  }
  for(i=0;i<n;i++)
  {
	   for(j=0;j<n;j++)printf("[%lg]",a[i][j]); 
	   
	printf("\n");	   
  }
  
  printf("matrix written by columns:\n");
   for(i=0;i<n;i++)
  {
	 for(j=0;j<n;j++)a[j][i]=1.0/(1+i+j);
	 
	a[i][i]+=1;  	
  }
  for(i=0;i<n;i++)
  {
	 for(j=0;j<n;j++)printf("[%lg]",a[j][i]); 
	 
	  printf("\n");	
  }
  return 0;
}
