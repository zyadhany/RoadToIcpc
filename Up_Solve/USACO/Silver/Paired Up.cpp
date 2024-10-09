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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;    

void solve(int tc) {
    ll n;

    cin >> n;

    deque<pl> X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i].second >> X[i].first;
    sortx(X);

    ll mx = 0;

    while (!X.empty())
    {
        if (X.size() == 1) {
            ll tk = X[0].first * (1 + (X[0].second > 1));
            mx = max(mx, tk);
            X.pop_back();
            continue;
        }

        ll re = min(X.front().second, X.back().second);
        mx = max(mx, X.front().first + X.back().first);

        X.front().second -= re;
        X.back().second -= re;
        if (!X.front().second) X.pop_front();
        if (!X.back().second) X.pop_back();
    }
    
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
