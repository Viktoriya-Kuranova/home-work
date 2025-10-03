#include <iostream>
using namespace std;
class myclass{
  int d,f;
  public:
  myclass (int i,int j):d(i),f(j){}
  friend bool lalala(myclass ob);
};
bool lalala(myclass ob)
{
  return ob.d%ob.f==0;
} 
int main()

{
  myclass ob1(10,2),ob2(7,2);
  if(lalala(ob1)) cout<<"10 делится на 2 без остатка"<<endl;
  else cout<<"10 делится на 2 c остатка"<<endl;
  if(lalala(ob2)) cout<<"7 делится на 2 без остатка"<<endl;
  else cout<<"7 делится на 2 c остатка"<<endl;

}
