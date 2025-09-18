#include <iostream>

using namespace std;
int salary;

namespace rent
{
  int cost;
}

namespace communal
{
  int cost;
}

namespace food
{
  int cost;
}

namespace transport
{
  int cost;
}

int main()
{
  cout<<"введите сумму,которую составояет ваша месячная заработная плата: "<<endl;
  cin>>salary;
  cout<<"введите сумму,которую вы тратите на аренду жилья в месяц: "<<endl;
  cin>>rent::cost;
  cout<<"введите сумму,которую вы тратите на коммунальные услуги в месяц: "<<endl;
  cin>>communal::cost;
  cout<<"введите сумму,которую вы тратите на продукты питания в месяц: "<<endl;
  cin>>food::cost;
  cout<<"введите сумму,которую вы тратите на транспорт в месяц: "<<endl;
  cin>>transport::cost;
  cout<<"в месяц у вас остается "<<salary -( rent::cost + communal::cost + food::cost + transport::cost)<<" на личные траты"<<endl;
  
return 0;
}
