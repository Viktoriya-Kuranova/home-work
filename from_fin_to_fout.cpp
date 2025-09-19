#include <iostream>
#include <fstream>
#include <string>

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

    string line;
    while (getline(fin, line)) 
    {
        fout << line << '\n';
    }

    if (!fin.eof()) 
    {
        cout<< "конец файла не достигнут\n"<<endl;
        return 2;
    }

    cout << "Копирование успешно завершено\n"<<endl;
    return 0;
}
