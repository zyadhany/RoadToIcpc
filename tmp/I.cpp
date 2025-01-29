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

using namespace std;

const int MODE = 1e9 + 9;

void solve(int tc) {
    ll n, m;
    string s;

    cin >> n >> m;
    cin >> s;

    vii X(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> X[i][j];

    vi R(n), C(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            R[i] += X[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i] += X[j][i];
    
    pl at = {0, 0};

    for (auto c : s) {

        if (c == 'D') {
            X[at.first][at.second] = -R[at.first];
            C[at.second] += X[at.first][at.second];
            at.first++;
        }
        else {
            X[at.first][at.second] = -C[at.second];
            R[at.first] += X[at.first][at.second];
            at.second++;
        }
    }    
    X[n-1][m-1] = -R[n-1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << X[i][j] << ' ';
        cout << '\n';        
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("square.in", "r", stdin);
    // freopen("square.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

1
2

1-2
2-3
3-4
4-5
5-2
