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
<<<<<<< HEAD
ll N = 0;

//inf.readToken("[a-z]{1,100}", "s");
string StringToken(string tok = "[a-z]", int len) {
    string token = tok + to_string(len);
    return (token);
}

void solve(int tc){
    setTestCase(tc);

    ll n, m;

    n = inf.readInt(1, 200'000, "n");
    inf.readSpace();
    m = inf.readInt(1, 200'000, "m");
    inf.readEoln();
    N += n;
    M += m;

    ensuref(N <= 2e5, "summ of n exeeds 2e5");
    ensuref(M <= 2e5, "summ of m exeeds 2e5");

    

    for (int i = 0; i < m; i++)
    {
        inf.readInt(1, 1000'000);
        if (i != m - 1) inf.readSpace();
    }

    inf.readToken(StringToken("[a-z]", n));
    inf.readEoln();
    inf.readToken(StringToken("[a-z]", m));
=======

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

>>>>>>> bcdcd2f53b59a63e88d320e74449ed4844e3ba0e
    inf.readEoln();
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int Test;

<<<<<<< HEAD
    Test = inf.readInt(1, 1e4, "t");
=======
    Test = inf.readInt(1, 10'000, "t");
>>>>>>> bcdcd2f53b59a63e88d320e74449ed4844e3ba0e
    inf.readEoln();
    
    for (int i = 1; i <= Test; i++) {
        solve(i);
    }

    inf.readEof();
}