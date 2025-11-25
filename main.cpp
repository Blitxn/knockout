#include "Bracket.hpp"
#include <vector>
using namespace std;

int main() {
    vector<string> players = {"Anna","Ben","Chou","Dara","Ean","Faye","Gita","Hout"};
    Bracket tournament(players);

    // Leaf matches (matches 8–15)
    tournament.recordResult(8, "Anna");
    tournament.recordResult(9, "Ben");
    tournament.recordResult(10, "Chou");
    tournament.recordResult(11, "Dara");
    tournament.recordResult(12, "Ean");
    tournament.recordResult(13, "Faye");
    tournament.recordResult(14, "Gita");
    tournament.recordResult(15, "Hout");

    // Quarterfinals
    tournament.recordResult(4, "Anna");
    tournament.recordResult(5, "Chou");
    tournament.recordResult(6, "Faye");
    tournament.recordResult(7, "Hout");

    // Semifinals
    tournament.recordResult(2, "Anna");
    tournament.recordResult(3, "Faye");

    // Final
    tournament.recordResult(1, "Anna");

    // Print bracket
    tournament.printBracket();
}




