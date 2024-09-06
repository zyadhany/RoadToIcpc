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
    vector<string> cow = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    
    map<string, ll> X;
    for (auto c : cow) X[c] = 0;

    ll n; cin >> n;

    while (n--)
    {
        string s; ll k;
        cin >> s >> k;
        X[s] += k;
    }
    
    vector<pair<ll, string>> Z;
    for (auto m : X) Z.push_back({m.second, m.first});
    sortx(Z);

    pair<ll, string> re = {Z[0].first, "zzz"};
    ll l = upper_bound(all(Z), re) - Z.begin();

    if (l == Z.size()) {
        cout << "Tie\n"; return;
    }

    re.first = Z[l].first;
    ll r = upper_bound(all(Z), re) - Z.begin();

    if (r != l + 1) cout << "Tie\n";
    else cout << Z[l].second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
