// SearchLibrary.cpp : Defines the functions for the static library.
//

#include "Search.h"
#include <Windows.h>
#include <iostream>
#include<string>
#include <vector>


using namespace std;

void SearchFile(string path, string search_name, vector<string>& result) {

    WIN32_FIND_DATAA file;
    string str_path = path + "\\*";
    HANDLE search_handle = FindFirstFileA((LPCSTR)str_path.c_str(), &file);

    if (search_handle)
    {
        do
        {
            string a = file.cFileName;
            if (a[0] == '.') {
                continue;
            }
            string filename = path + "\\" + string(file.cFileName); //review on filename 
            if (search_name == string(file.cFileName)) {
                result.push_back(filename);
            }
            if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                SearchFile(filename, search_name, result);
            }

        } while (FindNextFileA(search_handle, &file));
        FindClose(search_handle);

    }

}
