#include <iostream>
using namespace std;
class Student 
{
private: //закрытые переменные
    string name;  
    int  score;    
public:

    void setName(string t) 
    { 
        name=t;// присвоили значение закрытой переменной name с помощью set
    }
    void setScore(int k) 
    {
        score = k; 
    }
    //с помощью get возвращаем значение закрытой переменной 
    string getName() 
    {
        return name;
    }
    int getScore() 
    {
        return score;
    }
};
int main() 
{
    Student s;
    s.setName("Самир");
    s.setScore(6);
    cout << "Имя студента: " << s.getName() << endl;
    cout << "Балл:: " << s.getScore() << endl;

//выше мы обратились к закрытым переменным через set и get,как и нужно 
//если обратиться к закрытым переменным напрямую:
//s.name(Самир); 
//s.score(6); 
//то компилятор выдаст ошибку
    return 0;
}
