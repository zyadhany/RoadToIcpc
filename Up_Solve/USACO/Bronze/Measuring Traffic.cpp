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
    ll n;

    cin >> n;

    vector<pair<ll, pl>> X;
    ll st = n + 10, en = 0;

    for (int i = 0; i < n; i++)
    {
        string s; ll l, r;
        cin >> s >> l >> r;

        if (s == "on") {
            X.push_back({1, {l, r}});
        } else if (s == "off") {
            X.push_back({-1, {l, r}});
        } else {
            X.push_back({0, {l, r}});
            en = i;
            st = min(st, i + 0ll);
        }

    }

    pl re = X[en].second;
    for (int i = en - 1; i >= 0; i--)
    {
        ll opp = X[i].first; pl k = X[i].second;

        if (opp == -1) {
            re.second += k.second;
            re.first += k.first;
        } else if (opp == 1) {
            re.second -= k.first;
            re.first -= k.second;
            re.second = max(re.second, 0ll);
            re.first = max(re.first, 0ll);
        } else
        {
            re.first = max(re.first, k.first);
            re.second = min(re.second, k.second);
        }
    }
    cout << re.first << ' ' << re.second << '\n';

    re = X[st].second;
    for (int i = st + 1; i < X.size(); i++)
    {
        ll opp = X[i].first; pl k = X[i].second;

        if (opp == 1) {
            re.second += k.second;
            re.first += k.first;
        } else if (opp == -1) {
            re.second -= k.first;
            re.first -= k.second;
            re.first = max(re.first, 0ll);
            re.second = max(re.second, 0ll);
        } else
        {
            re.first = max(re.first, k.first);
            re.second = min(re.second, k.second);
        }
    }

    cout << re.first << ' ' << re.second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
