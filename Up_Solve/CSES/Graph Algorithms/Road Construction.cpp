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

const int MODE = 998244353;

using namespace std;

ll MXN = 2e5 + 1;
vi PAR(MXN);
vi SZ(MXN, 1);

ll get(ll n) {
    if (n == PAR[n]) return n;
    return PAR[n] = get(PAR[n]);
}

void add(ll u, ll v) {
    ll a = get(u), b = get(v);
    PAR[b] = a;
    SZ[a] += SZ[b];
}

void INIT() {
    for (int i = 0; i < MXN; i++)
        PAR[i] = i;    
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    ll cnt = n, mx = 1;

    while (m--)
    {
        ll u, v; cin >> u >> v;

        ll a = get(u), b = get(v);
        if (a != b) {
            cnt--;
            add(u, v);
            mx = max(mx, SZ[get(u)]);
        }

        cout << cnt << ' ' << mx << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("movie.in", "r", stdin);
    // freopen("movie.out", "w", stdout);
    INIT();

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
