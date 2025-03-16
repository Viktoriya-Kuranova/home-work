#include<stdio.h>
void printfBits_float(void *a)
{
  int i; unsigned x;
  x=*(unsigned*)a;
  
  for(i=31;i>=0;i--)
  {
    if((x & ((unsigned)1<<i))!=0) printf("1");
     else printf("0");
     
     if(i==31) printf(" ");
     if(i==23) printf(" ");
  }
}
int main()
{
  float a=1.0, b=0.0, c;
  c=a/b;

 printfBits_float( &c);printf("\n");
 printf("%g\n",c);


}
