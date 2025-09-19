#include <iostream>
#include <fstream>


using namespace std;

int main() 
{
    ifstream fin("1.txt");
    if (!fin.is_open()) 
    {
        cout<< "не удалось открыть файл 1.txt\n"<<endl;
        return 1;
    }

    ofstream fout("2.txt");
    if (!fout.is_open()) 
    {
        cout<< "Не удалось открыть файл 2.txt\n"<<endl;
        return 1;
    }

    string name,surname,father;
    int birthday;
    double score;
    if(fin>>surname>>name>>father>>birthday>>score)
    {
	  char m;
	  if(fin>>m) cout<<"файл некорректен\n"<<endl;	
      else if (!fin.eof()) 
    {
        cout<< "конец файла не достигнут\n"<<endl;
        return 2;
    }
    else
    { 
	  fout<<surname<<" "<<name<<" "<<father<<" "<<birthday<<" "<<score;
      cout << "Копирование успешно завершено\n"<<endl;
    }
    }
    else cout<<" ошибка при чтении файла"<<endl;
    return 0;
}

