#include <iostream>
#include <vector>
#include "bracket.hpp"
using namespace std;

int main() {
    vector<string> players = {"Anna","Ben","Chou","Dara","Ean","Faye","Gita","Hout"};
    Bracket tournament(players);

    cout << "=== INITIAL BRACKET ===\n";
    tournament.printBracket();

    // ROUND 1 RESULTS
    cout << "\n=== ROUND 1 RESULTS ===\n";
    vector<pair<int,string>> round1 = {
        {8,"Anna"}, {9,"Ben"}, {10,"Chou"}, {11,"Dara"},
        {12,"Ean"}, {13,"Faye"}, {14,"Gita"}, {15,"Hout"}
    };
    for (auto &r : round1) {
        cout << r.second << " automatically advances from first round!\n";
        tournament.recordResult(r.first, r.second);
    }
    tournament.printBracket();

    // QUARTERFINALS
    cout << "\n=== QUARTERFINALS ===\n";
    vector<pair<int,string>> quarterfinals = {
        {4,"Anna"}, {5,"Gita"}, {6,"Faye"}, {7,"Hout"}
    };
    for (auto &q : quarterfinals) {
        cout << q.second << " wins the quarterfinal match!\n";
        tournament.recordResult(q.first, q.second);
    }
    tournament.printBracket();

    // SEMIFINALS
    cout << "\n=== SEMIFINALS ===\n";
    vector<pair<int,string>> semifinals = {
        {2,"Anna"}, {3,"Faye"}
    };
    for (auto &s : semifinals) {
        cout << s.second << " wins the semifinal match!\n";
        tournament.recordResult(s.first, s.second);
    }
    tournament.printBracket();

    // FINAL
    cout << "\n=== FINAL ===\n";
    cout << "Anna wins the final and is the champion!\n";
    tournament.recordResult(1,"Anna");
    tournament.printBracket();

    return 0;
}

