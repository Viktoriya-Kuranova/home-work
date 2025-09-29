#include <iostream>
using namespace std;

class Simple 
{ int* size;
  public:
    Simple(int b) 
    {
      size=new int[b];
        cout<<"‚ ª®­áâàãªâ®à¥!"<<endl;  
    }
  
};

int main() 
{ 
    for (int i=0;i<1000000;i++)
    {
      Simple f(i);        
    }
    cout<<"–¨ª« § ¢¥àèñ­"<<endl;
    return 0;
}
