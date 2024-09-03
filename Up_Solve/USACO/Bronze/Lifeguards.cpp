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
    ll n;

    cin >> n;

    ll mx = 0;
    vp X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i].first >> X[i].second;
    
    for (int i = 0; i < n; i++)
    {
        ll re = 0;
        vi Z(1001, 1);
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            for (int h = X[j].first; h < X[j].second; h++)
            {
                re += Z[h];
                Z[h] = 0;
            }
        }
        mx = max(mx, re);
    }
    
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
