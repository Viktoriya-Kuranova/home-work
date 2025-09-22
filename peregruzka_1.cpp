#include <iostream>
using namespace std;
int minuus(int a, int b) 
{
 return a - b;
}
double minuus(double a, double b) 
{
 return a - b;
}
int main()
{
 cout << minuus(10, 2) << endl;        
 cout << minuus(8.7, 3.2) << endl;   
 
 return 0;
}
