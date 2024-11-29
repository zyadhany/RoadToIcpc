#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9;

using namespace std;

ll k;

void get() {
    cin >> k;
    string s;
    for (int i = 0; i < k; i++) cin >> s;
}

void solve(int tc) {
    do {
        cout << "next ";
        for (int i = 1; i <= 9; i++) cout << i << ' ';
        cout << endl;
        get();
        cout << "next 9" << endl;
        get();
    } while (k == 3);
    
    while (k == 2) {
        cout << "next ";
        for (int i = 0; i <= 9; i++) cout << i << ' ';
        cout << endl;
        get();
    }
    
    cout << "done" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("cruise.in", "r", stdin);
    // freopen("cruise.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
