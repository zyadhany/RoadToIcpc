#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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
using namespace std;
 
const int MODE = 1e9+7;

ll summ(ll l, ll r) {
    return (r * (r + 1) / 2) - (l * (l - 1) / 2);
}

void solve(int tc) {
    ll n, k;
    cin >> n >> k;

    ll res = 0;
    vi X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        res += summ(1, X[i]);
    }
    
    deque<pl> dq;
    sortx(X);
    dq.push_front({X[0], 1});
    for (int i = 1; i < n; i++)
    {
        if (X[i] == dq.back().first) {
            dq.back().second++;
        } else {
            dq.push_back({X[i], 1});
        }
    }

    ll rem = 0;
    while (dq.size() > 1)
    {
        ll mxl = (dq[1].first - dq[0].first) * dq[0].second;
        ll mxr = (dq.back().first - dq[dq.size() - 2].first) * dq.back().second;
        ll mxtk = min(mxl, mxr);

        auto f = [&](ll mid) -> ll {
            ll res = -mid * k;

            auto  [vr, cr] = dq.back();
            ll mvr = mid / cr;
            res += summ(vr - mvr + 1, vr) * cr;
            if (mid % cr) {
                res += (vr - mvr) * (mid % cr);
            }
            auto [vl, cl] = dq[0];
            ll mvl = mid / cl;
            res -= summ(vl+1, vl + mvl) * cl;
            if (mid % cl) {
                res -= (vl + mvl + 1) * (mid % cl);
            }
            return res;
        };

        ll l = 0, r = mxtk;
        while (l < r)
        {
            ll mid = (l + r + 1) / 2;
            if (f(mid) >= f(mid-1)) l = mid;
            else r = mid - 1;
        }

        // for (int i = 0; i < 10; i++)
        // {
        //     cout << i << ' ' << f(i) << '\n';
        // }
        
        // cout << l << '\n';
        // cout << l << "|\n";
        // cout << f(l) << "||\n";
        // for (auto [v, c] : dq) {
        //     cout << v << " " << c << " |\n";
        // }
        
        rem += f(l);
        if (l != mxtk) break;

        if (l == mxl) {
            dq[1].second += dq[0].second;
            dq.pop_front();
        
            auto [v,c] = dq.back();
            dq.pop_back();
            v-= l/c;
            if (l%c) {
                if (!dq.empty() && dq.back().first == v-1) {
                    dq.back().second += l%c;
                } else dq.push_back({v-1, l%c});
            }
            if (!dq.empty() && dq.back().first == v) {
                dq.back().second += c - l%c;
            } else dq.push_back({v, c- l%c});
        } else {
            dq[dq.size() - 2].second += dq.back().second;
            dq.pop_back();
        
            auto [v,c] = dq[0];
            dq.pop_front();
            v+= l/c;
            if (l%c) {
                if (!dq.empty() && dq[0].first == v+1) {
                    dq[0].second += l%c;
                } else dq.push_front({v+1, l%c});
            }
            if (!dq.empty() && dq[0].first == v) {
                dq[0].second += c - l%c;
            } else dq.push_front({v, c- l%c});
        }
    }
    
    res -= rem;
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	// freopen("runaway.in", "r", stdin);
    // freopen("runaway.out", "w", stdout);
 
    cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
