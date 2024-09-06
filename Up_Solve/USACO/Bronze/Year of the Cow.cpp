#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    vector<string> Month = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake",
    "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

    map<string, int> mm; 
    for (int i = 0; i < 12; i++)
        mm[Month[i]] = i;

    map<string, int> X;

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<string> Z(8);
        for (int j = 0; j < 8; j++)
            cin >> Z[j];
        string s, t;
        s = Z[0]; t = Z.back();

        ll cur = (X[t] % 12 + 12) % 12;
        ll gol = mm[Z[4]];

        ll opp = 1;
        if (Z[3] == "previous") opp = -1;

        gol -= cur;
        if (gol * opp > 0) X[s] = X[t] + gol;
        else X[s] = X[t] + opp * (12 - abs(gol));
    }
    
    cout << abs(X["Elsie"]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("whereami.in", "r", stdin);
    //freopen("whereami.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
