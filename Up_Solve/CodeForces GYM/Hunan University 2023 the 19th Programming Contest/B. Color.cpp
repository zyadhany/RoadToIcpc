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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 998244353;

using namespace std;

// get longest increasing subsequince if segment(l, r).
// each value start at postion and end else where.
ll LISQSegment(vi &X) {
    ll n, res;

    n = X.size();
    unordered_map<int, int> ST, EN;
    ST.reserve(n); EN.reserve(n);
    set<ll> st;
    vi dp(n + 10, INT32_MAX);

    for (int i = 0; i < n; i++)
    {
        if (!ST.count(X[i])) ST[X[i]] = i;
        EN[X[i]] = i;
        st.insert(X[i]);
    }
    
    dp[0] = -1, res = 0;
    for (auto a : st) {
        ll st = ST[a], en = EN[a];
        ll l, r, at;
        
        l = 0, r = res + 1;
        while (l < r)
        {
            at = (l + r) / 2;
            if (dp[at] < en) l = at + 1;
            else r = at;
        }
        
        if (dp[l - 1] <= st) {
            dp[l] = en;
            res = max(res, l);
        }
    }

    return (st.size() - res);
}

void solve(int tc) {
    ll n;
    cin >> n;
    vi X(n);
    
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    cout << LISQSegment(X) << '\n';    
}

int main()
{
		ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int size = 1;

		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);

		//cin >> size;
		for (int i = 1; i <= size; i++)
				solve(i);
}
