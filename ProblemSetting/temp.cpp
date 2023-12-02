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

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int a, b;
    
    a = inf.readInt(1, 999, "a");
    
    ensure(a % 2, "input must be odd");
    
    inf.readEoln();
    inf.readEof();
}