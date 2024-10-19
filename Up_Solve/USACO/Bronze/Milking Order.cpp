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
    ll n, m, k;

    cin >> n >> m >> k;

    vi X(m), Z(n + 1);

    bool isin = 0;
    for (int i = 0; i < m; i++) {
        cin >> X[i];
        if (X[i] == 1) isin = 1;
    }

    mi Y;
    for (int i = 0; i < k; i++)
    {
        ll a, b; cin >> a >> b;
        Z[b] = a;
        Y[a] = b;
    }

    if (Y.count(1)) {
        cout << Y[1] << '\n';
        return;
    }

    if (isin) {
        ll at = 1;
        for (int i = 0; i < m; i++)
        {
            while (at <= n && Z[at]) at++;
            if (Y.count(X[i])) {
                at = Y[X[i]] + 1;
            }else Z[at] = X[i];
        }
    } else {
        Y.clear();
        for (int i = 0; i < m; i++)
            Y[X[i]] = i;

        for (int i = 1; i <= n; i++)
        {
            if (!Z[i]) continue;
            if (Y.count(Z[i])) {
                ll at = Y[Z[i]] - 1;
                X[at + 1] = 0;
                for (int j = i - 1; j >= 0 && at >= 0 && X[at]; j--)
                {
                    if (!Z[j]) {
                        Z[j] = X[at];
                        X[at] = 0;
                        at--;
                    }
                }
            } 
        }
                
        for (int i = 1; i <= n; i++)
        {
            if (!Z[i]) {
                Z[i] = 1;
                break;
            }
        }
    }


    for (int i = 1; i <= n; i++)
        if (Z[i] == 1) {
            cout << i << '\n';
            return;
        } 
    while (1)
    {
        cout << "||" << endl;
    }
     
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
