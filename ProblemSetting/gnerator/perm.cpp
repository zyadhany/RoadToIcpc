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

void req(vii &TES, vi &X, int n, int m) {
    if (m == n) {
        TES.push_back(X);
        return;
    }

    for (int i = 0; i <= 5; i++)
    {
        X.push_back(i);
        req(TES, X, n, m + 1);
        X.pop_back();
    }
    
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    vii TES;

    for (int i = 1; i <= 5; i++)
    {
        vi X;
        req(TES, X, i, 0);
    }
    

    cout << TES.size() << '\n';
    for (auto X : TES) {
        cout << X.size() << '\n';
        for (int i = 0; i < X.size(); i++)
        {
            cout << X[i];
            if (i != X.size() - 1) cout << ' ';
        }
        cout << '\n';
    }
}

/*
<#list 1..10 as i >
     igen --m 10 ${i} > $ 
</#list>
*/