#include <iostream>
using namespace std;

class Pupupu
{
  private: int x,y;
    
  public:
    Pupupu(int a,int b): x(a),y(b)
    { 
		cout<<"В конструкторе: " <<x<<" и "<<y<<endl;
	}
};
int main()
{
  Pupupu p(1,2);
 return 0;
}
	


