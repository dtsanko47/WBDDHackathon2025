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
    TeamsPerYear(int year);

    ~TeamsPerYear();

    void InsertTeam(Node* team);

    void DisplayYearOfTeams();

    Node* getTeam(string name);

    Node* getHead();

    Node* setHead(Node* head);

    int getTeamYear();

    void setTeamYear(int year);

private:
    Node* m_head; //Head (first node) in Document (linked list)
    //    int m_lineCount; //Count of number of lines in Document
    int m_teamCount;

    int m_year;
};
#endif
