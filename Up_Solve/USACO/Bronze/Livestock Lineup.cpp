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
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n;

    cin >> n;

    vector<string> names = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                            "Bella", "Blue", "Betsy", "Sue"};
    map<string, int> name_index;
    for (int i = 0; i < names.size(); i++)
        name_index[names[i]] = i;

    vp X(n);
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s;
        for (int j = 0; j < 5; j++)
            cin >> t;
        X[i].first = name_index[s];
        X[i].second = name_index[t];
    }
    
    vi Z(8);
    for (int i = 0; i < 8; i++) Z[i] = i;
    
    vector<string> res(1, "zzzzz");
    do
    {
        bool isit = 1;
        vector<string> tmp(8);
        for (int i = 0; i < 8; i++)
            tmp[i] = names[Z[i]];
        
        for (int i = 0; i < n; i++)
        {
            ll l = X[i].first;
            ll r = X[i].second;
            ll a, b;
            for (int j = 0; j < 8; j++)
            {
                if (Z[j] == l) a = j;
                if (Z[j] == r) b = j;
            }
            
            if (abs(a - b) > 1) isit = 0;
        }
        
        if (isit) res = min(res, tmp);
    } while (next_permutation(all(Z)));

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
