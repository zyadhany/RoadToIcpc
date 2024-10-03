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


const int MODE = 998244353;

using namespace std;    

struct event
{
    ll st, id, on;
};
bool operator<(const event &a, const event &b) {return a.st < b.st;}

void solve(int tc) {
    ll n;

    cin >> n;

    vector<event> X;

    for (int i = 0; i < n; i++)
    {
        ll l, r; cin >> l >> r;
        X.push_back({l, i, 1});
        X.push_back({r, i, 0});
    }
    sortx(X);

    vi Z(n);
    ll summ = 0;
    ll prev = 0;
    set<ll> st;

    for (auto &e : X) {
        ll curr = e.st;

        if (!st.empty()) summ += curr - prev;

        if (st.size() == 1) Z[*st.begin()] += curr - prev;

        if (e.on) st.insert(e.id);
        else st.erase(e.id);

        prev = curr;
    }

    cout << summ - *min_element(all(Z));
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
