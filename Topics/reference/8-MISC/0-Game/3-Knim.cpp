/*
 * K-Nim Game Strategy:
 * it's game which you have n pills, and each player can take anyamount from at most k pills. players take turns, and the player who cannot make a move loses.
 * 1. Convert the size of each pile into binary.
 * 2. Count the number of 1s at each bit position across all piles.
 * 3. Take the total count of 1s at each bit position modulo (k + 1).
 * 4. If ANY bit position has a sum modulo (k + 1) != 0, it is a winning position (First player wins).
 * 5. If ALL bit positions have a sum modulo (k + 1) == 0, it is a losing position (Second player wins).
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve(vector<ll> X, ll k) {
    vector<ll> bit_counts(62, 0);
    
    for (ll x : X) {
        for (int i = 0; i < 62; i++) {
            if ((x >> i) & 1) {
                bit_counts[i]++;
            }
        }
    }
    
    for (int i = 0; i < 62; i++) {
        if (bit_counts[i] % (k + 1) != 0) {
            return true;
        }
    }
    
    return false;
}