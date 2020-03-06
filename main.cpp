#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void initializeResults(vector<int> &team, vector<int> &opponent, vector<string> &nameOfTheTeam, int &teams);

int main() {
    vector<int> resultsOfTeam = {};
    vector<int> resultsOfOpponent = {};
    vector<string> nameOfTeam;
    int numberOfTeams = 0;
    return 0;
}

void initializeResults(vector<int> &team, vector<int> &opponent, vector<string> &nameOfTheTeam, int &teams) {

    ifstream inFile;
    int counter = 0;
    int opponentNumber = 0;
    int teamNumber = 0;

    string teamName;
    inFile.open("premier_league1.csv");
    if (!inFile.is_open()) cout << "It is not open" << endl;
    inFile >> teams;

    while (!inFile.eof()) {
        while (inFile.get() != '/n') {
            while (inFile.get() != ',') teamName += inFile.get();
            nameOfTheTeam.push_back(teamName);

            if (counter % 2 == 0) {
                inFile >> teamNumber;
                team.push_back(teamNumber);
            } else {
                inFile >> opponentNumber;
                opponent.push_back(opponentNumber);
            }
            counter++;
        }

    }
    inFile.close();
}

