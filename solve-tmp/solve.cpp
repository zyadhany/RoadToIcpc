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
    ll n, m;

    cin >> n >> m;

    vii X(n, vi(3));
    vi L, R;

    for (int i = 0; i < n; i++)
        cin >> X[i][1] >> X[i][0] >> X[i][2];
    sortx(X);

    for (int i = 0; i < n; i++)
    {
        if (X[i][2] == -1) L.push_back(X[i][0]);
        else R.push_back(m - X[i][0]);
    }
    
    vp time;
    ll total_wid = 0;
    for (int i = 0; i < n; i++)
    {
        total_wid += X[i][1];
        if (i < L.size()) time.push_back({L[i], X[i][1]});
        else time.push_back({R[i - L.size()], X[i][1]});
    }
    sortx(time);
    ll t, summ = 0;

    for (int i = 0; i < n; i++)
    {
        summ += time[i].second;
        if (i < n - 1 && time[i].first == time[i + 1].first) continue;
        if (summ >= (total_wid + 1ll) / 2) {
            t = time[i].first;
            break;
        }
    }
    
    L.clear(), R.clear();
    for (int i = 0; i < n; i++)
        if (X[i][2] == 1) L.push_back(X[i][0]);
        else R.push_back(X[i][0]);
    
    ll sol = 0;
    for (int i = 0; i < L.size(); i++)
    {
        ll l, r;
        r = upper_bound(all(R), L[i] + 2 * t) - R.begin();
        l = lower_bound(all(R), L[i]) - R.begin();
        sol += r - l;
    }

    for (int i = 0; i < R.size(); i++)
    {
        ll l, r;
        l = lower_bound(all(L), R[i] - 2 * t) - L.begin();
        r = upper_bound(all(L), R[i]) - L.begin();
        sol += r - l;
    }
    
    cout << sol / 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
