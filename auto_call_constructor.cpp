#include <iostream>
using namespace std;

class A 
{
public:
    A() 
    {
        cout<<"Конструктор A"<<endl;
    }
};

class B 
{
private:
    A a;  
public:
    B() 
    {
        cout<<"Конструктор B"<<endl;
    }
};

int main() 
{
    B b;
    return 0;
}
