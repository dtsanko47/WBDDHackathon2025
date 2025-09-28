#include "TeamsPerYear.h"

TeamsPerYear::TeamsPerYear(int year) {
    m_head == nullptr;
    m_teamCount = 0;
    m_year = year;
}

TeamsPerYear::~TeamsPerYear() {
    Node* curr = m_head;
    Node* prev = m_head;
    while (curr != nullptr) {
        curr = curr->GetNext();
        delete prev;
        prev = curr;
    }
    m_head = nullptr;
    m_teamCount = 0;
}


void TeamsPerYear::InsertTeam(Node* team){
    // Insert at beginning or empty list
    Node* temp = m_head;
    m_head = team;
    team->SetNext(temp);
    m_teamCount++;
}

Node* TeamsPerYear::getTeam(string name) {
    Node* current = m_head;
    while (current->GetNext() != nullptr and current->GetName() != name) {
        current = current->GetNext();
    }
    if(current->GetName() == name){
        return current;
    }
    return nullptr;
}

Node* TeamsPerYear::getHead(){
    return m_head;
}

Node* TeamsPerYear::setHead(Node* head){
    m_head = head;
}

int TeamsPerYear::getTeamYear(){
    return m_year;
}

void TeamsPerYear::setTeamYear(int year){
    m_year = year;
}



