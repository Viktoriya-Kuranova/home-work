#include <iostream>
using namespace std;
int func(int a, int b=3) 
{
    if(b==2) return a;  
   return a+b;             
}
int main() 
{
    cout << "первый параметр: " << func(5) << endl;    
    cout << "сумма: " << func(7,10) << endl; 
  return 0;
}
