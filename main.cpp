#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct spital {
    string id, specializare;
};

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;
    vector<spital>probleme, doctori;

    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        probleme.push_back({name, speciality});
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        doctori.push_back({name, speciality});
    }

    for(auto i:probleme) {
        int cnt = 0;
        for(auto j:doctori)
            if(i.specializare == j.specializare) {
                cout << i.id << ' ' << "Acceptat\n";
                cnt++;
            }
        if(!cnt)
            cout << i.id << ' ' << "Respins\n";
    }
    return 0;
}