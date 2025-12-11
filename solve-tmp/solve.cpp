// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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

const int MODE = 1e9 + 7;

using namespace std;

const int MAXSZ = 1e7 + 1;
int prime[MAXSZ] = {0};
 
void INIT() {
    for (int i = 0; i < MAXSZ; i++) prime[i] = i;
    for (int i = 2; i * i < MAXSZ; ++i) if (prime[i] == i)
        for (int j = i; j < MAXSZ; j += i) if (prime[j]==j) prime[j] = i;
}

const ll K = 60*24;

void solve() {
    ll n;
    cin >> n;

    string s = "";
    n -= 1;

    for (int i = 0; i < n; i++)
    {
        if (i%2) s += 'B';
        else s += 'F';
    }
    
    cout << s.size() << '\n' << s << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve();
}
