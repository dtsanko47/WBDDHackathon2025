//
// Created by danie on 9/27/2025.
//

#ifndef DATA_H
#define DATA_H
#include <iostream>
#include<vector>
#include <string>
#include "TeamsPerYear.h"
using namespace std;

class Data{
    public:
        Data(string);

        void loadData();

    private:
        string m_file;
        vector<TeamsPerYear*> m_teams;
};


#endif //DATA_H
