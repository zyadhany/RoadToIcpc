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

    vi X(m + 2);
    ll l, r, cnt; l = r = cnt = 0;

    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;

        if (a == -1) l++;
        else if (a == -2) r++;
        else cnt += (X[a] == 0), X[a] = 1;
    }
    
    vp Z(m + 2);
    X[0] = X[m + 1] = 1;
    ll mx = 0;
    
    ll re= 0;
    for (int i = 0; i <= m + 1; i++)
        if (X[i]) Z[i].first = min(re, l);
        else re++;
    re = 0;
    for (int i = m + 1; i >= 0; i--)
        if (X[i]) Z[i].second = min(re, r);
        else re++;

    for (int i = 0; i <= m + 1; i++)
    {
        if (!X[i]) continue;
        ll summ = cnt + Z[i].second + Z[i].first;
        mx = max(mx, summ);
    }
    
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("backforth.in", "r", stdin);
    //freopen("backforth.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
