#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) 
{
	if (argc<3)
	{
	  cout<<"в программу переданы не все названия файлов\n"<<endl;
	  return 1;
	}
    ifstream fin(argv[1]);
    if (!fin.is_open()) 
    {
        cout<< "не удалось открыть 1 файл\n"<<endl;
        return 2;
    }
   
  
    ofstream fout(argv[2]);
    if (!fout.is_open()) 
    {
        cout<< "Не удалось открыть 2 файл\n"<<endl;
        return 2;
    }

    string name,surname,father;
    int birthday;
    double score;
    if(fin>>surname>>name>>father>>birthday>>score)
    {cout<<"1"<<endl;
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
