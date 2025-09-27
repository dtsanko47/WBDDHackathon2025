#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Team{
 public:

  int m_wins;
  int m_losses;
  double m_winDif;
  int m_goals;
  int m_lgoals;
  double m_goalDif;

  Team(){}
  Team(int wins, int losses, double winDif, int goals, int lgoals, double goalDif) {
    m_wins = wins;
    m_losses = losses;
    m_winDif = winDif;
    m_goals = goals;
    m_lgoals = lgoals;
    m_goalDif = goalDif;
  }
};

#endif

