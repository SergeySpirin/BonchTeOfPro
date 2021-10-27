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

void get_file(File* pointer, int rows)
{
    ifstream data;
    data.open("catalog.txt");
    if (data.is_open())
        {
            for(int i = 0; i < rows; i++)
            {
                data >> pointer[i].catalog_name >> pointer[i].file_name >> pointer[i].file_size;
            }
        }
    else cout << "Can't open the file!" << endl;
    data.close();
};

void save_file(File* pointer, int rows)
{
    ofstream data;
    data.open("/Users/sergey/Documents/BonchTeOfPro/Practice-5/Practice-5/catalog.txt");
    if (data.is_open())
        {
            for(int i = 0; i < rows; i++)
            {
                data << pointer[i].catalog_name << " " << pointer[i].file_name << " "  << pointer[i].file_size << endl;
            }
        }
    data.close();
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

void get_catalog_size(File* pointer, int rows)
{
    string catalog_list = "";
    for(int i = 0; i < rows; i++)
    {
        int cat_size = 0;
        string cur_catalog_name = pointer[i].catalog_name;
        for(int j = 0; j < rows; j++)
        {
            if(cur_catalog_name == pointer[j].catalog_name)
            {
                cat_size += pointer[j].file_size;
            }
        }
        if(catalog_list.find(cur_catalog_name) != string::npos)
        {
            cout << "";
        }
        else cout << cur_catalog_name << " " << cat_size << ", МБ" << endl;
        catalog_list += cur_catalog_name;
    }
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

int main()
{
    int rows_count = 4;
    File files[rows_count];
    bool Continue = true;
    string activity;
    int row_to_change;
    
    get_file(files, rows_count);
    system("clear");
    print_file_table(files, rows_count);
    do
    {
        cout << "Что дальше: " << endl << "[1] Изменить строку" << endl << "[2] Сохранить файл" << endl
             << "[3] Посчитать объем файлов в каталогах" << endl << "[4] Выйти" << endl;
        cin >> activity;
        system("clear");
        if(activity == "1")
        {
            cout << "Какую строку менять? -> ";
            cin >> row_to_change;
            change_row(&files[row_to_change-1]);
            print_file_table(files, rows_count);
        }
        else if(activity == "2")
        {
            save_file(files, rows_count);
            print_file_table(files, rows_count);
        }
        else if(activity == "3")
        {
            get_catalog_size(files, rows_count);
            print_file_table(files, rows_count);
        }
        else if(activity == "4")
        {
            Continue = false;
        }
    }
    while(Continue);
}
