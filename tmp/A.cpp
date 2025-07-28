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

const int MODE = 1e9 + 7;

using namespace std;

ll dp[14][2][2][2][2];

ll req(string &s, ll idx, bool grt, bool zer, bool four, bool sev) {
    ll &ret = dp[idx][grt][zer][four][sev];
    if (ret != -1) return ret;
    if (four && sev) return ret = pow(10, idx);
    if (idx == 0) return ret = 0;
    ret = 0;

    ll st = 0, ed = 10;
    if (!zer) {
        ret += req(s, idx - 1, 1, zer, four, sev);
        st = 1;
    }

    ll nx = s[idx - 1] - '0';
    if (!grt) {
        ret += req(s, idx - 1, 0, 1, four | (nx == 4), sev | (nx == 7));
        ed = nx;
    }
    for (int i = st; i < ed; i++) {
        ret += req(s, idx - 1, 1, 1, four | (i == 4), sev | (i == 7));
    }
    return ret;
}

ll count(ll n) {
    fill(&dp[0][0][0][0][0], &dp[13][1][1][1][1], -1);
    string s = to_string(n);
    reverse(all(s));
    ll ans = req(s, s.size(), 0, 0, 0, 0);
    return ans;
}


void solve(int tc) {
    ll q; cin >> q;

    while (q--)
    {
        ll n; cin >> n;

        ll x = n;
        ll l=1, r=1e13;
        ll i=1;
        while(l<x){
            i++;
            string s;
            s=to_string(i);
            map<char,int>mp;
            for(auto it:s){
                mp[it]++;
            }
            if(mp['7']&&mp['4']){
            } else l++;
        }
        cout << i << '\n';

        while (l < r)
        {
            ll mid = (l + r) / 2;
            ll v = mid - count(mid);
            if (v >= n) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("mars.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}