#include <iostream>
#include <fstream>
#include <vector>
#include<string>

using namespace std;

void initializeResults(vector<string> &nameOfTheTeam, int &teams, vector<int> &results);
void sortTeams(vector<string> &nameOfTheTeam, int &teams, vector<int> &results);
void noteResults(vector<string> &nameOfTheTeam, int &teams, vector<int> &results);
int main() {

    vector<string> teamName;
    int teamAmount = 0;
    vector<int> teamResults;

    initializeResults(teamName, teamAmount, teamResults);
    sortTeams(teamName, teamAmount, teamResults);
    noteResults(teamName, teamAmount, teamResults);
    return 0;
}

void initializeResults(vector<string> &nameOfTheTeam, int &teams, vector<int> &results) {

    fstream inFile;
    int score = 0;
    int opponentNumber;
    int teamNumber;
    char c = 0;
    string teamName;

    inFile.open(R"(C:\Users\alekz29\Documents\GitHub\OP_LR1\premier_league1.csv)");
    if (!inFile.is_open()) cout << "It is not open" << endl;

    inFile >> teams;
    inFile.get(c);

    for (int i = 0; i < teams; i++) {
        inFile.get(c);
        string fullName;
        while (c != ',') {
            fullName += c;
            inFile.get(c);
        }
        nameOfTheTeam.push_back(fullName);

        while (c != '\n' && !inFile.eof()) {
            inFile >> teamNumber;
            inFile.get(c);

            inFile >> opponentNumber;
            if (teamNumber > opponentNumber)
                score += 3;
            else if (teamNumber == opponentNumber)
                score += 1;
            inFile.get(c);
        }


        results.push_back(score);
        score = 0;
    }


    inFile.close();
}

void sortTeams(vector<string> &nameOfTheTeam, int &teams, vector<int> &results) {

    string name;
    int result;

    for (int i = 0; i < teams; i++) {
        for (int j = 0; j < teams-1; j++) {
            if (results[j] > results[j + 1]) {
                result = results[j];
                results[j] = results[j + 1];
                results[j + 1] = result;

                name = nameOfTheTeam[j];
                nameOfTheTeam[j] = nameOfTheTeam[j + 1];
                nameOfTheTeam[j + 1] = name;
            }
        }
    }
}

void noteResults(vector<string> &nameOfTheTeam, int &teams, vector<int> &results){
    fstream outFile;
    outFile.open(R"(C:\Users\alekz29\Documents\GitHub\OP_LR1\results.csv)");
    if (!outFile.is_open()) cout << "It is not open" << endl;
    for(int i=0; i<teams; i++){
        outFile<<nameOfTheTeam[i]<<','<<results[i]<<endl;
    }
}