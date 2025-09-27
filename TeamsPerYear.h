#ifndef TEAMSPERYEAR_H //Header guard (Protects against multiple inclusion)
#define TEAMSPERYEAR_H //Header guard
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
using namespace std;
class TeamsPerYear
{
public:
    void InsertTeam(string name, int wins, int losses, double winDif, int goals, int lgoals, double goalDif, int position);

    void DisplayYearOfTeams();


private:
    Node* m_head; //Head (first node) in Document (linked list)
    int m_lineCount; //Count of number of lines in Document
};
#endif
