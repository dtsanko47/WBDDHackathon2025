
#ifndef NODE_H //Header guard
#define NODE_H //Header guard
#include <iostream>
#include <string>

using namespace std;


class Node{
public:
    //Default constructor
    Node();
    //Overloaded
    Node(string name, int wins, int losses, double winDif, int goals, int goalsAgainst, int goalDif);
    //Getter for object
    string GetName();

    int GetWins();

    int GetLosses();

    double GetWinPrecentage();

    int GetGoals();

    int GetLGoals();

    int GetGoalDif();

    //Getter for next node
    Node* GetNext();
    //Setter for the team
    void SetTeam(int wins, int losses, double winDif, int goals, int lgoals, int goalDif);

    //Setter for the next node
    void SetNext(Node* next);

private:
    string m_name;
    int m_wins;
    int m_losses;
    double m_winPrecentage;
    int m_goals;
    int m_goalsAgainst;
    int m_goalDif;

    //Pointer to the next node
    Node* m_next;
};
#endif
