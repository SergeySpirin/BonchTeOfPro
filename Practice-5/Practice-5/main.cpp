#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct File
{
    int id;
    
    string catalog_name;
    string file_name;
    float file_size;
};

struct Catalog
{
    string name;
    int size;
};

void get_file(File* pointer, int rows)
{
        ifstream data;
        data.open("catalog.txt");
        if (data.is_open())
            {
                for(int i = 0; i < rows; i++)
                {
                    cout << "1";
                    data >> pointer[i].catalog_name >> pointer[i].file_name >> pointer[i].file_size;
                }
            }
        data.close();
};

void print_file_table(File* table, int rows)
{
    cout << endl;
    cout << "Номер\t" << "Каталог\t" << "Файл\t" << "Размер, МБ\t" << endl;
    for(int j = 0; j < rows; j++)
    {
        cout << j+1 << ": \t";
        cout << table[j].catalog_name << "\t";
        cout << table[j].file_name << "\t";
        cout << table[j].file_size << "\t\n";
    }
};

void change_row(File* row)
{
        cout << "Введите новое название каталога: ";
        cin >> row->catalog_name;
        cout << "Введите новое имя файла: ";
        cin >> row->file_name;
        cout << "Введите новый размер файла, MB: ";
        cin >> row->file_size;
};

int main()
{
    int rows_count = 2;
    File files[rows_count];
    Catalog catalog_list[rows_count];
    bool Continue = true;
    string activity;
    int row_to_change;
    
    get_file(files, rows_count);

    print_file_table(files, rows_count);

    do
    {
        cout << "Что дальше: " << endl << "[1] Изменить строку" << endl << "[2] Сохранить файл" << endl << "[3] Выйти" << endl;
        cin >> activity;
        if(activity == "1")
        {
            cout << "Какую строку менять?";
            cin >> row_to_change;
            change_row(&files[row_to_change-1]);
            print_file_table(files, rows_count);
        }
        else if(activity == "2")
        {
            Continue = false;
        }
        else if(activity == "3")
        {
            Continue = false;
        }
    }
    while(Continue);
}
