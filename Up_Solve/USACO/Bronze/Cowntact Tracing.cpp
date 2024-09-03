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
    ll n, m;
    string s;

    cin >> n >> m;
    cin >> s;

    vii X(m, vi(3));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> X[i][j];
            X[i][j]--;
        }
    }
    sortx(X);

    ll cnt = 0, mx = 0, mn = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0') continue;
        bool canbezero = 0;

        for (ll k = 0; k <= m + 10; k++)
        {
            string t;
            for (int j = 0; j < n; j++)
                t += "0";
            vi Z(n, -1);
            
            t[i] = '1';
            Z[i] = 0;

            for (int j = 0; j < m; j++)
            {
                ll l = X[j][1];
                ll r = X[j][2];
            
                if (t[l] == '1' && t[r] == '0' && Z[l] < k) Z[l]++, Z[r] = 0, t[r] = '1';
                else if (t[r] == '1' && t[l] == '0' && Z[r] < k) Z[r]++, Z[l] = 0, t[l] = '1';
                else if (t[r] == '1' && t[l] == '1') Z[r]++, Z[l]++;
            }

            if (t == s) {
                canbezero = 1;
                mn = min(mn, k);
                mx = max(mx, k);
            }
        }
        EE:;
        cnt += canbezero;
    }
    
    cout << cnt << ' ' << mn << ' ';
    if (mx == m + 10) cout << "Infinity\n";
    else cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
