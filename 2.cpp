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
    
    int x;
    while(fin>>x)
    cout<<x<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    fin.close();
    ofstream fout(argv[2]);
    if (!fout.is_open()) 
    {
        cout<< "Не удалось открыть 2 файл\n"<<endl;
        return 2;
    }

    if (!fin.eof()) 
    {
        cout<< "Ошибка чтения: конец файла не достигнут (возможна повреждённая запись)\n"<<endl;
        return 3;
    }

    cout << "Копирование успешно завершено\n"<<endl;
    return 0;
}
