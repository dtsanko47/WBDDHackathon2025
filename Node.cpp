#include "Node.h"


Node::Node() : m_name(""), m_wins(0), m_losses(0), m_winPrecentage(0), m_goals(0), m_goalsAgainst(0), m_goalDif(0) {
    cout << "No Team" << endl;
}

Node::Node(string name, int wins, int losses, double winDif, int goals, int goalsAgainst, int goalDif):
    m_name(name), m_wins(wins), m_losses(losses), m_winPrecentage(winDif),
    m_goals(goals), m_goalsAgainst(goalsAgainst), m_goalDif(goalDif) {}


string Node::GetName() {
    return m_name;
}
int Node::GetWins() {
    return m_wins;
}
int Node::GetLosses() {
    return m_losses;
}
double Node::GetWinPrecentage() {
    return m_winPrecentage;
}
int Node::GetGoals() {
    return m_goals;
}
int Node::GetLGoals() {
    return m_goalsAgainst;
}
int Node::GetGoalDif() {
    return m_goalDif;
}

Node* Node::GetNext() {
    return m_next;
}

void Node::SetTeam(int wins, int losses, double winDif, int goals, int lgoals, int goalDif){
    m_wins = wins;
    m_losses = losses;
    m_winPrecentage = winDif;
    m_goals = goals;
    m_goalsAgainst = lgoals;
    m_goalDif = goalDif;
}

void Node::SetNext(Node* next) {
    m_next = next;
}
