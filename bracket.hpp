#ifndef BRACKET_HPP
#define BRACKET_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string leftPlayer;
    string rightPlayer;
    string winner;
};

class Bracket {
private:
    vector<Node> rounds;
    int leafStart; // first leaf match
    int numPlayers;

public:
    Bracket(const vector<string>& players) {
        numPlayers = players.size(); // 8 players
        int totalMatches = numPlayers - 1; // internal matches
        int totalNodes = totalMatches + numPlayers; // total matches
        rounds.resize(totalNodes + 1); // 1-based indexing

        leafStart = totalMatches + 1; // first leaf match

        // Leaves: players
        for (int i = 0; i < numPlayers; i++) {
            rounds[leafStart + i].leftPlayer = players[i];
            rounds[leafStart + i].rightPlayer = "";
            rounds[leafStart + i].winner = players[i]; // initially, the player themselves
        }

        // Internal matches placeholders
        for (int i = leafStart - 1; i >= 1; i--) {
            int left = 2 * i;
            int right = 2 * i + 1;
            rounds[i].leftPlayer = left < rounds.size() ? rounds[left].winner : "?";
            rounds[i].rightPlayer = right < rounds.size() ? rounds[right].winner : "?";
            rounds[i].winner = "?";
        }
    }

    void recordResult(int matchId, const string& winner) {
        rounds[matchId].winner = winner;

        // Update parent matches
        int parent = matchId / 2;
        while (parent >= 1) {
            int left = 2 * parent;
            int right = 2 * parent + 1;
            string leftWinner = left < rounds.size() ? rounds[left].winner : "?";
            string rightWinner = right < rounds.size() ? rounds[right].winner : "?";
            rounds[parent].leftPlayer = leftWinner;
            rounds[parent].rightPlayer = rightWinner;
            rounds[parent].winner = "?";
            parent /= 2;
        }
    }

    void printBracket() {
        cout << "=== TOURNAMENT BRACKET ===\n\n";

        // Quarterfinals: matches 4-7
        cout << "Quarterfinals:\n";
        for (int i = 4; i <= 7; i++) {
            cout << "Match " << i << ": " << rounds[i].leftPlayer
                 << " vs " << rounds[i].rightPlayer
                 << " -> Winner: " << rounds[i].winner << "\n";
        }
        cout << "\n";

        // Semifinals: matches 2-3
        cout << "Semifinals:\n";
        for (int i = 2; i <= 3; i++) {
            cout << "Match " << i << ": " << rounds[i].leftPlayer
                 << " vs " << rounds[i].rightPlayer
                 << " -> Winner: " << rounds[i].winner << "\n";
        }
        cout << "\n";

        // Final: match 1
        cout << "Final:\n";
        cout << "Match 1: " << rounds[1].leftPlayer
             << " vs " << rounds[1].rightPlayer
             << " -> Winner: " << rounds[1].winner << "\n\n";

        cout << "Champion: " << rounds[1].winner << "!\n";
    }
};

#endif








