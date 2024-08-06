#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int format;
    cin >> format;
    
    // Determine the format multiplier based on the game format
    int formatMultiplier;
    if (format == 50) formatMultiplier = 50;  // ODI
    else if (format == 20) formatMultiplier = 20;  // T20
    else if (format == 100) formatMultiplier = 100;  // Test
    else formatMultiplier = 100; // Default (if needed)

    vector<vector<string>> players(n, vector<string>(4));
    
    // Input player names
    for (int i = 0; i < n; i++) {
        cin >> players[i][0];
    }
    
    // Input runs scored
    for (int i = 0; i < n; i++) {
        cin >> players[i][1];
    }
    
    // Input balls faced
    for (int i = 0; i < n; i++) {
        cin >> players[i][2];
    }
    
    // Input outs
    for (int i = 0; i < n; i++) {
        cin >> players[i][3];
    }
    
    int k;
    cin >> k;
    
    vector<tuple<int, int, int, int>> scores(n); // (Basra, Balls Faced, Player Index, Runs)
    
    for (int i = 0; i < n; i++) {
        int runs = stoi(players[i][1]);
        int balls = stoi(players[i][2]);
        int outs = stoi(players[i][3]);
        
        // Calculate Strike Rate
        double strikeRate = (double)runs / balls * 100;
        
        // Calculate Average
        double average = (double)runs / max(1, outs);
        
        // Calculate Basra Score
        double basraScore = (strikeRate * (100 - formatMultiplier)) + average;
        
        // Store Basra score, balls faced, and player index
        scores[i] = make_tuple(basraScore, balls, i, runs);
    }
    
    // Sort the scores based on Basra score and balls faced
    sort(scores.begin(), scores.end(), [](const tuple<double, int, int, int> &a, const tuple<double, int, int, int> &b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
        return get<1>(a) < get<1>(b);
    });
    
    // Get the player at the k-th position
    int idx = get<2>(scores[k - 1]);
    string name = players[idx][0];
    int runs = stoi(players[idx][1]);
    int outs = stoi(players[idx][3]);
    int balls = stoi(players[idx][2]);
    double basra = get<0>(scores[k - 1]);
    
    cout << name << " Basra=" << basra << " runs=" << runs << " outs=" << outs << " balls=" << balls;
    return 0;
}
