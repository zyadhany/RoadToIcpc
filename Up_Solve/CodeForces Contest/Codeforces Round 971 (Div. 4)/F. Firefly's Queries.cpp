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

ll req(vi &Z, ll shiff, ll l, ll r) {
    ll n = Z.size() - 1;
    l = (l + shiff) % n;
    r = (r + shiff) % n;

    if (r >= l) return (Z[r + 1] - Z[l]);
    else return(Z[r + 1] + Z.back() - Z[l]);
}

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vi X(n);
    vi Z(n + 1);
    ll summ = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        Z[i + 1] = Z[i] + X[i];
    }
    
    while (q--)
    {
        ll l, r; cin >> l >> r;
        l--; r--;
        ll st = l / n;
        ll en = r / n;
        ll sol = 0;
        if (st == en) sol = req(Z, st, l % n, r % n);
        else
        {
            sol = (en - st - 1) * Z.back();
            sol += req(Z, st, l % n, n - 1);
            sol += req(Z, en, 0, r % n);
        }
        
        cout << sol << '\n';
    }
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
