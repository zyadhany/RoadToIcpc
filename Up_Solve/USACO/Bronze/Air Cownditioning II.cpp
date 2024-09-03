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
    ll n, m;

    cin >> n >> m;
    vi X(101);

    for (int i = 0; i < n; i++)
    {
        ll s, t, c;
        cin >> s >> t >> c;

        for (int i = s; i <= t; i++)
            X[i] = max(X[i], c);
    }
    
    vii Z(m, vi(4));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 4; j++)
            cin >> Z[i][j];

    ll mn = INT32_MAX;

    for (int i = 0; i < (1 << m); i++)
    {
        ll cost = 0;
        vi Y(101);

        for (int j = 0; j < m; j++)
        {
            if (i & (1 << j)) {
                cost += Z[j][3];
                for (int h = Z[j][0]; h <= Z[j][1]; h++)
                    Y[h] += Z[j][2];
            }
        }
        
        bool isgood = 1;
        for (int i = 0; i < Y.size(); i++)
            if (X[i] > Y[i]) isgood = 0;
        if (isgood) mn = min(mn, cost);        
    }
    
    cout << mn << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
