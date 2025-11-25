#include "Bracket.hpp"
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> players = {"Anna","Ben","Chou","Dara","Ean","Faye","Gita","Hout"};
    Bracket tournament(players);

    // Print initial bracket
    tournament.printBracket();

    // Record leaf match results (Match 8–15)
    tournament.recordResult(8, "Anna");
    tournament.recordResult(9, "Ben");
    tournament.recordResult(10, "Chou");
    tournament.recordResult(11, "Dara");
    tournament.recordResult(12, "Ean");
    tournament.recordResult(13, "Faye");
    tournament.recordResult(14, "Gita");
    tournament.recordResult(15, "Hout");

    // Quarterfinals: 4–7
    tournament.recordResult(4, "Anna"); // 8 vs 9
    tournament.recordResult(5, "Chou"); // 10 vs 11
    tournament.recordResult(6, "Faye"); // 12 vs 13
    tournament.recordResult(7, "Hout"); // 14 vs 15

    // Semifinals: 2–3
    tournament.recordResult(2, "Anna"); // 4 vs 5
    tournament.recordResult(3, "Faye"); // 6 vs 7

    // Final: 1
    tournament.recordResult(1, "Anna"); // 2 vs 3

    // Print final bracket
    tournament.printBracket();
}