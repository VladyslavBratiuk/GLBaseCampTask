#pragma once


#define WIN32_LEAN_AND_MEAN     
#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
using namespace std;
namespace FileSearchLibrary {
   
    void SearchFile(string path, string search_name, vector<string>& result);
}

#endif 


