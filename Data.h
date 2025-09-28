
#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <sstream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
#include "TeamsPerYear.h"
using namespace std;
const char DELIMITER = ',';

class Data{
public:
    Data(string);

    void getData();

    void loadData(string teamName, string year, string loses, string winPrecentage,
                  string goals, string goalsAgainst, string goalDif);

    void dataToHtml();

private:
    string m_file;
    vector<TeamsPerYear*> m_teams;

};


#endif //DATA_H
