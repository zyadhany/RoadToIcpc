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

    ll n, k;

    n = inf.readInt(1, 200'000, "n");
    inf.readSpace();
    k = inf.readInt(0, 1000'000'000, "k");
    inf.readEoln();
    M += n;

    ensuref(M <= 200'000, "summ of n exeeds 2*10^5");

    for (int i = 0; i < n; i++)
    {
        inf.readInt(1, 1000'000'000);
        if (i != n - 1) inf.readSpace();
    }

    inf.readEoln();
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int Test;

    Test = inf.readInt(1, 10'000, "t");
    inf.readEoln();
    
    for (int i = 1; i <= Test; i++) {
        solve(i);
    }

    inf.readEof();
}