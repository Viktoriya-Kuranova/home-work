#include <stdio.h>
void printBits(void *a)
{
 int i;unsigned long long x;
 x=*(unsigned long long *)a;
 for( i=63; i>=0; i--) {
   if((x & ((unsigned long long)1<<i))!=0) printf("1");        
   else printf("0");
   if(i==63) printf(" ");
   if(i==62) printf(" ");
   if(i==52) printf(" ");
 
 }

}
int main ()
{
double x=1.0, b,c; int i=0;
do
{
printf("%d: %le\n",i,x);
printBits(&x); printf("\n");
b=1+x; // Добавляем x к 1.0 и проверяем изменение
printBits(&b); printf("\n");
x/=2.0; i--;// Делим x на 2 , уменьшаем степень

c=1+x; // Дополнительная переменная для проверки выхода из цикла
}while( c>1.0 );
b=1+x;
printBits(&b); printf("\n");
return 0;
}
