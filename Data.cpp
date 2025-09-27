//
// Created by danie on 9/27/2025.
//
#include "Data.h"

Data::Data(string file) {
    m_file = file;
    loadData();
}

void Data::loadData() {
    string teamName;
    int year;
    int loses;
    double winPrecentage;
    int goals;
    int goalsAgainst;
    int goalDif;
    fstream file(m_file);

}


