#include "TeamsPerYear.h"


void TeamsPerYear::InsertTeam(string name, int wins, int losses, double winDif, int goals, int lgoals, double goalDif, int position) {
    Node* newNode = new Node(name, wins,losses, winDif, goals, lgoals, goalDif);

    // Insert at beginning or empty list
    if (position == 1 || m_head == nullptr) {
        newNode->SetNext(m_head);
        m_head = newNode;
    }
    else {
        Node* current = m_head; // Pointer to traverse the list
        int currentPos = 1; // Tracks the  current position while traversing

        // Traverse to position before inserting
        while (current->GetNext() != nullptr && currentPos < position - 1) {
            current = current->GetNext();
            currentPos++;
        }

        // Inserting
        newNode->SetNext(current->GetNext());
        current->SetNext(newNode);
    }
    m_lineCount++;
}


// DisplayYearOfTeams
// Prints the league and stats for the year
void TeamsPerYear::DisplayYearOfTeams() {
    // Check if document is  empty
    if (m_lineCount == 0) {
        cout << "No Data" << endl;
    }
    else {
        Node* current = m_head; // Pointer to traverse the list

        // Display all lines
        for (int i = 1; i <= m_lineCount; i++) {
            cout << i << ": " << current->GetName() << current->GetWins() <<
                current->GetLosses() << current->GetWinDif() << current->GetGoals() <<
                    current->GetLGoals() << current->GetGoalDif() << endl;
            current = current->GetNext();
        }
    }
}

//Mayve destrucotr
// Maybe a get element of something but u can get the elements by Node* value = m_head --> traverse till value->GetName() = value->Getname.getnext or wtvr and then value->GetWins() etc
