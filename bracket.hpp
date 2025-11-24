#ifndef BRACKET_HPP
#define BRACKET_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    string leftPlayer;
    string rightPlayer;
    string winner;
};

class Bracket {
private:
    vector<Node> rounds;  
    int leafStart;       

public:
    Bracket(const vector<string>& players) {
        int n = players.size();
        int L = 1;
        while (L < n) L *= 2;              
        int totalMatches = 2*L - 1;         
        rounds.resize(totalMatches + 1);    
        leafStart = totalMatches - L + 1;
        for (int i = 0; i < L; i++) {
            rounds[leafStart + i].leftPlayer = (i < n) ? players[i] : "BYE";
            rounds[leafStart + i].rightPlayer = "BYE";
            rounds[leafStart + i].winner = rounds[leafStart + i].leftPlayer;
        }
        for (int i = leafStart - 1; i >= 1; i--) {
            rounds[i].leftPlayer = "?";
            rounds[i].rightPlayer = "?";
            rounds[i].winner = "?";
        }
    }

    void recordResult(int matchId, const string& winner) {
        Node &m = rounds[matchId];
        if (m.winner != "?") {
            cout << "Cannot record match " << matchId << ", already decided!\n";
            return;
        }

        if (m.leftPlayer == "?" || m.rightPlayer == "?") {
            cout << "Cannot record match " << matchId << ", participants not ready!\n";
            return;
        }

        if (m.leftPlayer == "BYE") m.winner = m.rightPlayer;
        else if (m.rightPlayer == "BYE") m.winner = m.leftPlayer;
        else m.winner = winner;
        int parent = matchId / 2;
        while (parent >= 1) {
            int left = 2*parent, right = 2*parent + 1;
            rounds[parent].leftPlayer = rounds[left].winner;
            rounds[parent].rightPlayer = rounds[right].winner;
            rounds[parent].winner = "?"; 
            parent /= 2;
        }
    }

    void printBracket() {
        cout << "\n=== TOURNAMENT BRACKET ===\n";
        for (int i = 1; i < rounds.size(); i++) {
            string left = rounds[i].leftPlayer;
            string right = rounds[i].rightPlayer;
            string winner = rounds[i].winner;

            if (right == "BYE") {
                cout << "Match " << i << ": " << left << " has a BYE  " << left << " advances!\n";
            } else if (winner != "?") {
                cout << "Match " << i << ": " << left << " vs " << right << "  " << winner << " wins!\n";
            } else {
                cout << "Match " << i << ": " << left << " vs " << right << "  match not yet played\n";
            }
        }
    }

    pair<int,int> wouldMeet(const string &a, const string &b) {
        int indexA=-1, indexB=-1;
        for (int i=1;i<rounds.size();i++){
            if (rounds[i].winner == a) indexA=i;
            if (rounds[i].winner == b) indexB=i;
        }
        if(indexA==-1) {
            for (int i=leafStart;i<rounds.size();i++){
                if (rounds[i].leftPlayer==a) indexA=i;
            }
        }
        if(indexB==-1){
            for (int i=leafStart;i<rounds.size();i++){
                if (rounds[i].leftPlayer==b) indexB=i;
            }
        }
        int x=indexA, y=indexB;
        while(x!=y){ x/=2; y/=2; }
        int meetMatch=x;
        int totalRounds = log2(rounds.size());
        int meetLevel = log2(meetMatch);
        int roundNumber = totalRounds - meetLevel;
        return {meetMatch, roundNumber};
    }

    vector<int> pathToFinal(const string &player) {
        vector<int> path;
        int index=-1;
        for (int i=leafStart;i<rounds.size();i++){
            if (rounds[i].leftPlayer==player) index=i;
        }
        while(index>=1){
            path.push_back(index);
            index/=2;
        }
        return path;
    }
};

#endif



