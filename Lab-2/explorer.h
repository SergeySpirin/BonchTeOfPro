#ifndef _EXPLORER_H
#define _EXPLORER_H

#include <string>

using namespace std;

class File
{    
    string catalog_name;    
    string file_name;
    float file_size;

public:
    File();
    ~File(); 
    File(string new_catalog_name, string new_file_name, float new_file_size);    

    void setCatalogName(string new_catalog_name);
    void setFileName(string new_file_name);
    void setFileSize(float new_file_size);

    string getCatalogName();
    string getFileName();
    float getFileSize();
};

#endif
