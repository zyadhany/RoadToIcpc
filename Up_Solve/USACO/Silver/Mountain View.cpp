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

void solve(int tc) {
    ll n;

    cin >> n;

    vp X(n);
    set<pl> st;

    for (int i = 0; i < n; i++)
        cin >> X[i].first >> X[i].second;

    sort(X.begin(), X.end(), [](const pl &a, const pl &b) {
        return a.second > b.second;
    });
    
    for (auto p : X) {
        auto it = st.insert(p).first;

        it++;
        if (it != st.end()) {
            pl k = *it;
            if (abs(k.first - p.first) <= k.second - p.second) {
                it--;
                st.erase(it);
                continue;
            }
        }

        it--;
        if (it != st.begin()) {
            it--;
            pl k = *it;
            if (abs(k.first - p.first) <= k.second - p.second) {
                it++;
                st.erase(it);
                continue;
            }
        }
    }

    cout << st.size() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}