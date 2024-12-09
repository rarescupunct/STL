#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include<algorithm>
#include<vector>
#define endl '\n'


using namespace std;


struct problema{
    int durata;
    int prioritate;
    string id_problema;
    string specializare;
};

struct doctor {
    int timp = 9;
    string id_doctor;
    string specializare;
    vector<string>asignate;
};

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int no_problems, no_doctors;
    string name, speciality;
    inFile >> no_problems;
    vector<problema> problems(no_problems);

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> problems[i].id_problema >> problems[i].specializare >> problems[i].durata >> problems[i].prioritate;
    }


    auto comparare=[](const problema& a, const problema& b) {
        return a.prioritate < b.prioritate;
    };

    priority_queue<problema, vector<problema>, decltype(comparare)> pq(comparare);

    for(int i = 0; i < no_problems; i++)
        pq.push(problems[i]);

    inFile >> no_doctors;
    vector<doctor> doctors(no_doctors);

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> doctors[i].id_doctor >> doctors[i].specializare;
    }

     while(!pq.empty()) {
         auto problema_curenta = pq.top();
        auto gasit = find_if(doctors.begin(), doctors.end(),
            [& problema_curenta](const doctor& d){
            return d.timp + problema_curenta.durata <= 17 && problema_curenta.specializare == d.specializare;
        });
         if(gasit != doctors.end()) {
            gasit->timp += problema_curenta.durata;
             gasit-> asignate.push_back(problema_curenta.id_problema);
         }
         pq.pop();
     }
    for(const auto& doctor:doctors) {
        if(!doctor.asignate.empty()) {
            outFile << doctor.id_doctor << ' ' << doctor.asignate.size() << ' ';
            for(const auto& problema:doctor.asignate) {
                outFile << problema << ' ';
            }
            outFile << endl;
        }
    }
    return 0;
}