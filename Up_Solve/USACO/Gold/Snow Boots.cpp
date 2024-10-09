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

    cin >> n >> m;

    vp X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first;
        X[i].second = i;
    }
    sortx(X);

    vii Q(m, vi(3));
    for (int i = 0; i < m; i++)
    {
        cin >> Q[i][0] >> Q[i][1];
        Q[i][2] = i;
    }
    sort(Q.rbegin(), Q.rend());

    vi sol(m);
    
    set<pl> rang;
    multiset<ll> len;
    len.insert(0);
    rang.insert({-1, -1});

    for (int i = 0; i < m; i++)
    {
        ll dip = Q[i][0];
        ll dist = Q[i][1];
        ll ind = Q[i][2];

        while (!X.empty() && X.back().first > dip)
        {
            pl re = {X.back().second, X.back().second};
            auto it = rang.upper_bound(re);
            if (it != rang.end() && it->first == re.second + 1) {
                re.second = it->second;
                len.erase(len.find(it->second - it->first + 1));
                rang.erase(it);
                it = rang.upper_bound(re);
            }

            if (it != rang.begin() && prev(it)->second == re.first - 1) {
                it--;
                re.first = it->first;
                len.erase(len.find(it->second - it->first + 1));
                rang.erase(it);
            }

            rang.insert(re);
            len.insert(re.second - re.first + 1);
            X.pop_back();
        }
        
        ll mx = *prev(len.end());
        sol[ind] = (mx < dist);
    }

    for (int i = 0; i < m; i++)
        cout << sol[i] << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
