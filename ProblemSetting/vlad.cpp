#include <bits/stdc++.h>
#include <unordered_map>
#include "testlib.h"

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

ll M = 0;

void solve(int tc){
    setTestCase(tc);

    ll n, m;

    n = inf.readInt(1, 1000'000, "n");
    inf.readSpace();
    m = inf.readInt(1, 1000, "m");
    inf.readEoln();
    M += m;

    ensuref(M <= 1000, "summ of m exeeds 1000");

    for (int i = 0; i < m; i++)
    {
        inf.readInt(1, 1000'000);
        if (i != m - 1) inf.readSpace();
    }

    inf.readEoln();
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int Test;

    Test = inf.readInt(1, 100, "t");
    inf.readEoln();
    
    for (int i = 1; i <= Test; i++) {
        solve(i);
    }

    inf.readEof();
}