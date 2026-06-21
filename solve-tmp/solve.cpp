// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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

const int SIZE = 1e6 + 1;
const int MODE = 998244353;
const ll INF = 2e16;
using namespace std;


void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vii IT;

    for (int i = 0; i < n; i++)
    {
        ll a, b, c; cin >> a >> b >> c;
        IT.push_back({a, b, c});
    }

    sort(all(IT), [&](vi &a, vi &b) {
        ll v1 = a[1]*b[0];
        ll v2 = b[1]*a[0];
        return v1 > v2;
    });

    ll brut = min(300ll, k);
    ll c = k-brut;

    ll summ = 0;
    for (auto &Y:IT) {
        ll tk = min(c/Y[0], Y[2]);
        summ += tk * Y[1];
        c -= tk;
        Y[2]-=tk;
    }
    
    
    vector<vp> X(3);
    for (auto &Y:IT) {
        ll a = Y[0], b = Y[1], c = Y[2];
        if (!c) continue;
        X[a-1].push_back({b, c});
    }
    for (int i = 0; i < 3; i++) sort(allr(X[i]));
    brut += c;
    ll sol = summ;

    for (int i = 0; i <= brut; i++)
    {
        for (int j = 0; j <= brut; j++)
        {
            for (int h = 0; h <= brut; h++)
            {
                if (i+2*j+3*h>brut) break;

                
                ll re = 0;
                ll at = 0;
                ll hv = i;
                while (at < X[0].size() && hv) {
                    pl p = X[0][at];
                    ll tk = min(hv, p.second);
                    re += tk * p.first;
                    if (tk == p.second) at++;
                    hv -= tk;
                }

                at = 0;
                hv = j;
                while (at < X[1].size() && hv) {
                    pl p = X[1][at];
                    ll tk = min(hv, p.second);
                    re += tk * p.first;
                    if (tk == p.second) at++;
                    hv -= tk;
                }

                at = 0;
                hv = h;
                while (at < X[2].size() && hv) {
                    pl p = X[2][at];
                    ll tk = min(hv, p.second);
                    re += tk * p.first;
                    if (tk == p.second) at++;
                    hv -= tk;
                }

                sol = max(sol, summ + re);
            }
        }
    }

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}