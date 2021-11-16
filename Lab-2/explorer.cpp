#include <iostream>
#include "explorer.h"

File::File() {};

File::~File() {};

File::File(string new_catalog_name, string new_file_name, float new_file_size)
{
    catalog_name = new_catalog_name;
    file_name = new_file_name;
    file_size = new_file_size;
};

void File::setCatalogName(string new_catalog_name)
{
    catalog_name = new_catalog_name;
};

void File::setFileName(string new_file_name)
{
    file_name = new_file_name;
};

void File::setFileSize(float new_file_size)
{
    file_size = new_file_size;
};

string File::getCatalogName()
{
    return catalog_name;
};

string File::getFileName()
{
    return file_name;
};

float File::getFileSize()
{
    return file_size;
};

