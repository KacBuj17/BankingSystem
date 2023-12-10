//#pragma once
//#include "Save_Load.h"
//using namespace std;
//
//template <typename T> vector<T> Save_Load<T>::Load(const string& fileName)
//{
//    vector<T> objects;
//    ifstream file(fileName + ".txt");
//
//    if (file.is_open())
//    {
//        T object{};
//        while (file >> object)
//        {
//            objects.push_back(object);
//        }
//        file.close();
//    }
//    else
//    {
//        cout << "Nie udalo sie otworzyc pliku!" << std::endl;
//    }
//
//    return objects;
//}
//
//template <typename T> void Save_Load<T>::Save(const vector<T>& objects, const std::string& fileName)
//{
//    ofstream file(fileName + ".txt");
//
//    if (file.is_open())
//    {
//        for (const auto& object : objects)
//        {
//            file << object << std::endl;
//        }
//        file.close();
//    }
//    else
//    {
//        cout << "Nie udalo sie otworzyc pliku!" << std::endl;
//    }
//}
