#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "explorer.h"

using namespace std;

int getMaxCatalogLength(File* files, int rows)
{
    int length = 8;
    for(int i = 0; i < rows; i++)
    {
        if(files[i].getCatalogName().length() > length)
        {
            length = files[i].getCatalogName().length();
        };
    };
    return length + 4;
};

int getMaxFileLength(File* files, int rows)
{
    int length = 8;
    for(int i = 0; i < rows; i++)
    {
        if(files[i].getFileName().length() > length)
        {
            length = files[i].getFileName().length();
        };
    };
    return length + 4;
};

void change_row(File* row)
{
    string catalog_name, file_name; float file_size;
    cout << "Введите новое название каталога: ";
    cin >> catalog_name;
    cout << "Введите новое имя файла: ";
    cin >> file_name;
    cout << "Введите новый размер файла, MB: ";
    cin >> file_size;
    row->setCatalogName(catalog_name); row->setFileName(file_name); row->setFileSize(file_size);
    cout << endl;
};

void get_catalog_size(File* pointer, int rows)
{
    int col1len = getMaxCatalogLength(pointer, rows); int col2len = 8; 
    cout << setw(col1len) << "Catalog" << setw(col2len) << "Size, MB" << endl;
    cout << setw(col1len) << "-------" << setw(col2len) << "--------" << endl;
    string catalog_list = "";
    for(int i = 0; i < rows; i++)
    {
        int cat_size = 0;
        string cur_catalog_name = pointer[i].getCatalogName();
        for(int j = 0; j < rows; j++)
        {
            if(cur_catalog_name == pointer[j].getCatalogName())
            {
                cat_size += pointer[j].getFileSize();
            }
        }
        if(catalog_list.find(cur_catalog_name) != string::npos)
        {
            cout << "";
        }
        else cout << setw(col1len) << cur_catalog_name << setw(col2len) << cat_size << endl;
        catalog_list += cur_catalog_name;
    }
    cout << endl;
};

void print_file_table(File* table, int rows)
{
    int col1Len = 2; int col2len = getMaxCatalogLength(table, rows); int col3len = getMaxFileLength(table, rows); int col4len = 8;
    cout << endl;
    cout << setw(col1Len) << left << "#" 
        << setw(col2len) << "Catalog" 
        << setw(col3len) << "File" 
        << setw(col4len) << "Size, MB" << endl;
    cout << setw(col1Len) << left << "-" 
        << setw(col2len) << "-------" 
        << setw(col3len) << "----" 
        << setw(col4len) << "--------" << endl;

    for(int j = 0; j < rows; j++)
    {
        cout << setw(col1Len) << j+1 <<
                setw(col2len) << table[j].getCatalogName() << 
                setw(col3len) << table[j].getFileName() <<
                setw(col4len) << table[j].getFileSize() << endl;
    }
    cout << endl;
};

int main()
{
    setlocale(LC_ALL, "");
    system("clear");

    File first_file;
    first_file.setCatalogName("Catalog-1");
    first_file.setFileName("File-1"); 
    first_file.setFileSize(100); 
    
    File second_file("Catalog-1", "File-2", 200);

    int rows_count = 6;
    File files[rows_count]; 
    files[0] = first_file;
    files[1] = second_file;
    
    print_file_table(files, 2);
    
    for(int i = 2; i < rows_count; i++)
    {
        change_row(&files[i]);
    };

    bool Continue = true;
    string activity;
    int row_to_change;
    system("clear");
    print_file_table(files, rows_count);
    do
    {
        cout << "Что дальше: " << endl 
             << "[1] Изменить строку" << endl
             << "[2] Посчитать объем файлов в каталогах" << endl
             << "[3] Выйти" << endl << ":";
        cin >> activity;
        if(activity == "1")
        {
            cout << endl;
            cout << "Какую строку менять? -> ";
            cin >> row_to_change;
            change_row(&files[row_to_change-1]);
            system("clear");
            print_file_table(files, rows_count);
        }
        else if(activity == "2")
        { 
            system("clear");
            print_file_table(files, rows_count);
            get_catalog_size(files, rows_count);
        }
        else if(activity == "3")
        {
            Continue = false;
        }
        else system("clear");
    }
    while(Continue);
    system("clear");
}
