#include <iostream>
#include <fstream>
#include <vector>
#include<string>

using namespace std;

void initializeResults(vector<string> &nameOfTheTeam, int &teams, vector<int> results);

int main() {

    vector<string> teamName;
    int teamAmount = 0;
    vector<int> teamResults;
    initializeResults(teamName, teamAmount, teamResults);

    return 0;
}

void initializeResults(vector<string> &nameOfTheTeam, int &teams, vector<int> results) {

    ifstream inFile;
    int score = 0;
    int opponentNumber = 0;
    int teamNumber = 0;
    char c = 0;
    string teamName = "";

    inFile.open(R"(C:\Users\alekz29\Documents\GitHub\OP_LR1\premier_league1.csv)");
    if (!inFile.is_open()) cout << "It is not open" << endl;
    inFile >> teams;
    inFile.get(c);
    for (int i = 0; i < teams; i++) {
        inFile.get(c);
        while (c != ',') {
             teamName += c;
            inFile.get(c);
        }


        while (c != '\n' && inFile.eof()) {

            inFile >> teamNumber;
            inFile.get(c);
            inFile >> opponentNumber;
            if (teamNumber > opponentNumber)
                score += 3;
            else if (teamNumber == opponentNumber)
                score += 1;
            inFile.get(c);
        }
        nameOfTheTeam.push_back(teamName);
        teamName="";
        results.push_back(score);
        score=0;
    }


    inFile.close();
}





