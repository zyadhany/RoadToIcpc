#define _CRT_SECURE_NO_WARNINGS
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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    vp X(3);

    for (int i = 0; i < 3; i++)
        cin >> X[i].first >> X[i].second;

    for (int i = 0; i < 100; i++)
    {
        ll l = i % 3;
        ll r = (i + 1) % 3;

        if (X[l].second + X[r].second <= X[r].first) {
            X[r].second += X[l].second;
            X[l].second = 0;
        } else {
            X[l].second -= X[r].first - X[r].second;
            X[r].second = X[r].first;
        }
    }
        
    for (int i = 0; i < 3; i++)
        cout << X[i].second << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
