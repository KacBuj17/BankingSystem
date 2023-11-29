#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T> class Save_Load
{
public:
    static vector<T> Load(const std::string& fileName);
    static void Save(const vector<T>& objects, const std::string& fileName);
};

#include "Save_Load.cpp"
