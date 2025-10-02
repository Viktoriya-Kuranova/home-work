#include <iostream>
using namespace std;

class truck;

class car{
  
  int passenger, speed;

 public:
 car(int p, int s) : passenger(p), speed(s) {}
 
 int sp_greater(truck t);
 
};

class truck {
  
 int weight, speed;
   
 public:
 truck(int w, int s) : weight(w), speed(s) {}
 
 friend int car::sp_greater(truck t);
     
};

int car::sp_greater(truck t){
 return speed-t.speed;
}

int main()
{
 int t;
 car c1(4,70), c2(5,100);
 truck t1(1000,0), t2(5000,70);
 t=c1.sp_greater(t1);
 if(t<0) cout<<"Грузовик быстрее"<<endl;
  else if(t==0) cout<<"Скорость машин равны"<<endl;
    else cout<<"Легковая машина быстрее"<<endl;
    
  t=c2.sp_greater(t2);  
 if(t<0) cout<<"Грузовик быстрее"<<endl;
  else if(t==0) cout<<"Скорость машин равны"<<endl;
    else cout<<"Легковая машина быстрее"<<endl;
 return 0;  
}
