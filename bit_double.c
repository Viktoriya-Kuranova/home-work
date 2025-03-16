#include<stdio.h>
void printBits(void *a)
{
 int i; long long x;
 x=*(long long *)a;
 for( i=63; i>=0; i--) {
   if((x & ((long long)1<<i))!=0) printf("1");
   else printf("0");
   if(i==63) printf(" ");
   if(i==62) printf(" ");
   if(i==52) printf(" ");
 
 }

}
int main()
{
 
 double a;
 scanf("%lf",&a);
 printBits( &a);



}





	
	
