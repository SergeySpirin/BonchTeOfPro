#include <iostream>
#include <string>

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

void get_file(File* pointer)
{
        cout << "Введите название каталога: ";
        cin >> pointer->catalog_name;
        cout << "Введите имя файла: ";
        cin >> pointer->file_name;
        cout << "Введите размер файла, MB: ";
        cin >> pointer->file_size;
        
        //cout << "Каталог: " << pointer->catalog_name << endl;
        //cout << "Файл: " << pointer->file_name << endl;
        //cout << "Размер, MB: " << pointer->file_size << endl;
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

void calc_catalog_size()
{
    if
};

int main()
{
    int rows_count = 2;
    File files[rows_count];
    Catalog catalog_list[rows_count];
    bool Continue = true;
    string activity;
    int row_to_change;
    
    for (int i = 0; i < rows_count; i++)
    {
        get_file(&files[i]);
    }
    print_file_table(files, rows_count);

    do
    {
        cout << "Что дальше: " << endl << "[1] Изменить строку" << endl << "[2] Выйти" << endl;
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
    }
    while(Continue);
}
