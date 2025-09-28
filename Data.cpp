
#include "Data.h"

Data::Data(string file) {
    m_file = file;
    for(int i = 1990; i < 2012; i++) {
          m_teams.push_back(nullptr);
    }
    vector<TeamsPerYear> teams = {};
    getData();
}

void Data::getData() {
    string teamName;
    string year;
    string loses;
    string winPrecentage;
    string goals;
    string goalsAgainst;
    string goalDif;
    fstream file(m_file);
    if(file.is_open()){
        while(getline(file, teamName, DELIMITER)){
            getline(file, year, DELIMITER);
            getline(file, loses, DELIMITER);
            getline(file, winPrecentage, DELIMITER);
            getline(file, goals, DELIMITER);
            getline(file, goalsAgainst, DELIMITER);
            getline(file, goalDif, DELIMITER);
            // clears buffer
            if (file.peek() == '\n') {
                file.ignore();
            }
            if (file.peek() == ' ') {
                file.ignore();
            }
            loadData(teamName, year, loses, winPrecentage,
                      goals, goalsAgainst, goalDif);
        }
    }
}


void Data::loadData(string teamName, string year, string loses, string winPrecentage,
                      string goals, string goalsAgainst, string goalDif) {
    int yearInt = stoi(year);
    int losesInt = stoi(loses);
    double winPrecentageInt = stod(winPrecentage);
    int goalsInt = stoi(goals);
    int goalDifInt = stoi(goalDif);
    Node *team = new Node(teamName, yearInt, losesInt, winPrecentageInt,
                          goalsInt, goalsInt, goalDifInt);
    if(m_teams.at(2010 - yearInt) == nullptr){
         TeamsPerYear *teamsPerYear = new TeamsPerYear(yearInt);
         m_teams.at(2010 - yearInt) = teamsPerYear;
         teamsPerYear->setHead(team);
    }
    else{
        m_teams.at(2010 - yearInt)->InsertTeam(team);
    }
}

void Data::dataToHtml() {
    for(TeamsPerYear *year : m_teams) {
        ostringstream filename;
        filename << "teams_" << year->getTeamYear() << ".txt";
        ofstream out(filename.str());
        out << "Year: " << year << "\n";
        out << "Name,Wins,Losses,WinDiff,Goals,GoalsAgainst,GoalDiff\n";
        Node* curr = year->getHead();
        while(curr != nullptr) {
            out << curr->GetName() << ","
            << curr->GetWins() << ","
            << curr->GetLosses() << ","
            << curr->GetWinPrecentage() << ","
            << curr->GetGoals() << ","
            << curr->GetLGoals() << ","
            << curr->GetGoalDif() << "\n";
            curr = curr->GetNext();
        }
    }
}

