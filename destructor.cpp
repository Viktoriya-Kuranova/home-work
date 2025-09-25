#include <iostream>
using namespace std;

class Simple 
{
public:
    Simple() 
    {
        cout<<"В конструкторе!"<<endl;
    }
    ~Simple() 
    {
        cout<<"В деструкторе!"<<endl;
    }
};

int main() 
{
    for (int i=0;i<3;i++)
    {
        cout<< "Итерация "<<i+1<<endl;
        Simple s; 
        cout<<"Объект используется"<<endl;
    }
    cout<<"Цикл завершён"<<endl;
    return 0;
}
