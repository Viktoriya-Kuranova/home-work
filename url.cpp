#include <iostream>
#include <cstdlib>
using namespace std;
class array {
int size;
char *p;
public:
array(int num);
~ array() { delete [] p; }
char &put(int i);
char get(int i) ;
};
array::array(int num)
{
p = new char [num];
if(!p) {
cout << "Ошибка выделения памяти\n";
exit (1);
}
size = num;
}

char &array::put(int i)
{

if (i<0  || i>=size) {
cout <<"Ошибка, нарушены границы массива! ! !\n";
exit(1);
}
return p[i];
} 
char array:: get (int i)
{
if (i<0 || i>=size) {
cout << "Ошибка, нарушены границы массива! !! \n";
exit(1);
}
return p[i];
}
int main ( )
{
array a (10) ;
a.put(3) = 'X';// if you write the string number 23 without &, it returning a copy of the simbol
//else & works like an url to an array element and doesn`t loose variable value; after that a.put(3) can work with X
a. put (2) = 'R';
cout << a.get(3) << a. get (2);
cout << "\n";
a.put(11) = '!';
return 0;
}
