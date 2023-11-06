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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "Yes\n"; return;}
#define NO {cout << "No\n"; return;}

const int MODE = 998244353;

using namespace std;

void solve(int tc) {
    ll n;
    string s;

    cin >> n >> s;

    mc X;

    for (auto a : s)
        X[a]++;

    cout << (min(X['L'], X['R']) + min(X['U'], X['D'])) * 2;
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}