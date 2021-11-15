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

void changeRow(File* row)
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

void getCatalogSize(File* pointer, int rows)
{
    int col1len = getMaxCatalogLength(pointer, rows); int col2len = 8; 
    cout << setw(col1len) << "Catalog" << setw(col2len) << "Size, MB" << endl;
    cout << setw(col1len) << "-------" << setw(col2len) << "--------" << endl;
    string* catalog_list = new string[rows];
    for(int i = 0; i < rows; i++)
    {
        int cat_size = 0; bool print = true;
        string cur_catalog_name = pointer[i].getCatalogName();
        for(int j = 0; j < rows; j++)
        {
            if(cur_catalog_name == pointer[j].getCatalogName())
            {
                cat_size += pointer[j].getFileSize();
            }
            if(cur_catalog_name == catalog_list[j])
            {
                print = false;
            }
        }
        if(print)
        {
            cout << setw(col1len) << cur_catalog_name << setw(col2len) << cat_size << endl;
        }
        catalog_list[i] = cur_catalog_name;
    }
    cout << endl;
};

void printFileTable(File* table, int rows)
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

    int rows_count = 4;
    File files[rows_count]; 
    files[0].setCatalogName("Catalog-1");
    files[0].setFileName("File-1");
    files[0].setFileSize(100);
    files[1] = File("Catalog-1", "File-2", 200); 
   
    printFileTable(files, 2);
    
    for(int i = 2; i < rows_count; i++)
    {
        cout << "Строка №" << i + 1 << endl;
        changeRow(&files[i]);
    };

    bool Continue = true;
    int activity;
    int row_to_change;
    system("clear");
    printFileTable(files, rows_count);
    do
    {
        cout << "Что дальше: " << endl 
             << "[1] Изменить строку" << endl
             << "[2] Посчитать объем файлов в каталогах" << endl
             << "[3] Выйти" << endl << ":";
        cin >> activity;
        switch (activity){
            case 1:
            {
                cout << endl;
                cout << "Какую строку менять? -> ";
                cin >> row_to_change;
                changeRow(&files[row_to_change-1]);
                system("clear");
                printFileTable(files, rows_count);
                break;
            }
            case 2:
            { 
                system("clear");
                printFileTable(files, rows_count);
                getCatalogSize(files, rows_count);
                break;
            }
            case 3:
            {
                Continue = false;
                break;
            }
            default: 
                system("clear");
                break;
        }
    }
    while(Continue);
    system("clear");
}
