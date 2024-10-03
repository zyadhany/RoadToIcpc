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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;    

void solve(int tc) {
    ll n;

    cin >> n;

    map<ll, vi> X, Y;
    mi SL, SR;
    map<pl, ll> M;

    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        X[l].push_back(r);
        SL[l] += r;
        Y[r].push_back(l);
        SR[r] += l;
    }

    for (auto &m : X) {
        ll r = SL[m.first];
        ll l = 0;
        ll sz = m.second.size();

        for (int i = 0; i < sz; i++)
        {
            ll y = m.second[i];
            r -= y;

            ll re = 0;
            re += r - y * (sz - i - 1);
            re += y * i - l;
            M[{m.first, y}] += re % MODE;
            l += y;
        }
    }

    ll sol = 0;

    for (auto &m : Y) {
        ll r = SR[m.first];
        ll l = 0;
        ll sz = m.second.size();

        for (int i = 0; i < sz; i++)
        {
            ll y = m.second[i];
            r -= y;

            ll re = 0;
            re += r - y * (sz - i - 1);
            re += y * i - l;

            re %= MODE;
            re *= M[{y, m.first}];
            re %= MODE; 
            sol = (sol + re) % MODE;
            
            l += y;
        }
    }

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
