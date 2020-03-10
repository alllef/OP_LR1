#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include <Windows.h>

using namespace std;

void initializeResults(vector<string> &nameOfTheTeam, int &teams, vector<int> &results, vector<string> &file, int &number);

void sortTeams(vector<string> &nameOfTheTeam, int &teams, vector<int> &results);


void noteResults(vector<string> &nameOfTheTeam, int &teams, vector<int> &results);

void makeMenu(vector<string> &name, int &number);

int main() {

    SetConsoleOutputCP(CP_UTF8);
    vector<string> fileName;
    vector<string> teamName;
    int teamAmount = 0;
    vector<int> teamResults;
    int fileNumber;

    makeMenu(fileName, fileNumber);
    initializeResults(teamName, teamAmount, teamResults, fileName, fileNumber);
    sortTeams(teamName, teamAmount, teamResults);
    noteResults(teamName, teamAmount, teamResults);

    return 0;
}


void initializeResults(vector<string> &nameOfTheTeam, int &teams, vector<int> &results, vector<string> &file, int &number) {

    fstream inFile;
    int score = 0;
    int opponentNumber;
    int teamNumber;
    char c = 0;
    string teamName;
int totalTeamNumber=0;

for(int i=0; i<number; i++) {
    inFile.open(file[i]);
    if (!inFile.is_open()) cout << "It is not open" << endl;

    inFile >> totalTeamNumber;
    teams+=totalTeamNumber;
    inFile.get(c);

    for (int j = 0; j < teams; j++) {
        inFile.get(c);
        string fullName;
        while (c != ',') {
            fullName += c;
            teamName += c;
            inFile.get(c);
        }
        nameOfTheTeam.push_back(fullName);


        while (c != '\n' && !inFile.eof()) {
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
            teamName = "";
            results.push_back(score);
            score = 0;
        }


        inFile.close();
    }
}
}

void sortTeams(vector<string> &nameOfTheTeam, int &teams, vector<int> &results) {

    string name;
    int result;

    for (int i = 0; i < teams; i++) {
        for (int j = 0; j < teams - 1; j++) {
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

void noteResults(vector<string> &nameOfTheTeam, int &teams, vector<int> &results) {
    fstream outFile;
    outFile.open(R"(C:\Users\alekz29\Documents\GitHub\OP_LR1\results.csv)");
    if (!outFile.is_open()) cout << "It is not open" << endl;
    for (int i = 0; i < teams; i++) {
        outFile << nameOfTheTeam[i] << ',' << results[i] << endl;
    }
}

void makeMenu(vector<string> &name, int &number) {
    string fileName;
    cout << "Введите количество файлов:\n";
    cin >> number;
    for (int i = 0; i < number; i++) {
        cout << "Введите полное название файла:\n";
        cin >> fileName;
        name.push_back(fileName);
    }
}