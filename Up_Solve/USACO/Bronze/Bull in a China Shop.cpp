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
#define vccc vector<vcc>
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

vcc FAL;

vcc req(vcc X, ll l, ll r) {
    ll n = X.size();

    vcc Z(n, vc(n, '.'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < l || i > l + n - 1 || j < r || j > r + n - 1) {
                if (X[i][j] == '#') return FAL;
            }
        }
    }

    for (int i = l, a = 0; a < n; i++, a++)
        for (int j = r, b = 0; b < n; j++, b++)
            if (i >= 0 && i < n && j >= 0 && j < n)
                Z[a][b] = X[i][j]; 

    return (Z);
}

vcc MIX(vcc &L, vcc &R) {
    ll n = L.size();
    vcc X(n, vc(n, 'X'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char l = L[i][j];
            char r = R[i][j];
            if (l == '#' && r == '#') return FAL;
            else if (l == '#' || r == '#') X[i][j] = '#';
            else X[i][j] = '.';            
        }
    }

    return (X);
}

void Print2dArray(vcc X) {
    for (auto l : X) {
        for (auto c : l) cout << c; 
        cout << '\n';
    }
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vcc X(n, vc(n));
    vccc Y(m, vcc(n, vc(n)));
    FAL.assign(n, vc(n, 'X'));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> X[i][j];
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                cin >> Y[i][j][k];
    

    for (int i = 0; i < m; i++)
        for (int l1 = -n; l1 <= n; l1++)
            for (int r1 = -n; r1 <= n; r1++)
            {
                auto L = req(Y[i], l1, r1);
                if (L == FAL) continue;                

                for (int j = i + 1; j < m; j++)
                    for (int l2 = -n; l2 <= n; l2++)
                        for (int r2 = -n; r2 <= n; r2++)
                        {
                            auto R = req(Y[j], l2, r2);
                            if (R == FAL) continue;
                            
                            auto Z = MIX(L, R);

                            if (Z != X) continue;
                            cout << i + 1 << ' ' << j + 1 << '\n';
                            return;
                        }
            }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
