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

vii maketree(ll n) {
    vi ND(n-1);
    for (int i = 0; i < n-1; i++)
    {
        ND[i] = i+1;
    }
    shuffle(ND.begin(), ND.end());
    
    vi AV(1, 0);

    vii adj(n);

    for (auto x : ND)
    {
        ll p = AV[rnd.next(0,(int)AV.size()-1)];
        adj[p].push_back(x);
        adj[x].push_back(p);
        AV.push_back(x);
    }
}

void writeTest(ll n, ll m) {
    cout << n << '\n';

    auto adj = maketree(n);
    for (int i = 0; i < n; i++) {
        cout << adj[i].size();
        for (auto x : adj[i]) {
            cout << ' ' << x + 1;
        }
        cout << '\n';
    }
    
    cout << m << '\n';

    adj = maketree(m);
    for (int i = 0; i < m; i++) {
        cout << adj[i].size();
        for (auto x : adj[i]) {
            cout << ' ' << x + 1;
        }
        cout << '\n';
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int TEST = 100;

    auto VN = rnd.partition(TEST, 100'000, 1);
    auto VM = rnd.partition(TEST, 100'000, 1);
    
    cout << TEST << '\n';
    for (int i = 1; i <= TEST; i++)
        writeTest(VN[i-1], VM[i-1]);
}

