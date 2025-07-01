#include "bits/stdc++.h"
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define all(X) X.begin(), X.end()

using namespace std;

void solve(vi &X) {
    ll n;

    n = X.size()-1;
    // cin >> n;

    // vi X(n + 1), P(n+1);
    vi P(n+1);
    for (int i = 1; i <= n; i++)
    {
        // cin >> X[i];
        P[i] = X[i] + P[i-1];
    }

    vi dp2(n+1);    
    for (int i = 1; i <= n; i++)
    {
        ll mx = 0;
        for (int l = 1; l <= i; l++)
        {
            for (int r = l; r <= i; r++)
            {
                ll summ = 0;
                for (int h = l; h <= r; h++) summ += X[h];
                mx = max(mx, summ);
                for (int h = l; h <= r; h++) {
                    for (int h2 = 1; h2 < l; h2++)
                    {
                        mx = max(mx, summ-X[h]+X[h2]);                        
                    }
                    for (int h2 = r+1; h2 <= i; h2++)
                    {
                        mx = max(mx, summ-X[h]+X[h2]);                        
                    }
                }
            }
        }
        dp2[i] = mx;
    }
    vi dp(n+1);

    ll summ = 0;
    for (int i = 1; i <= n; i++)
    {
        summ += X[i];
        summ = max(summ, 0ll);
        dp[i] = summ;
    }
    
    vi C(n+1), MNP(n+1, INT32_MAX), MXP(n+1, INT32_MIN);
    ll mx = X[1];
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, X[i]);
        C[i] = mx-P[i];
        MNP[i] = min(MNP[i-1], X[i]);
        MXP[i] = max(MXP[i-1], X[i]);
    }

    stack<pl> stnx;
    set<pl> stprev;
    ll mxprev = 0;
    pl mxnx = {INT32_MIN, 0};
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i-1]);

        // X[i] is max for previos
        ll at = P[i-1] - MNP[i-1];
        while (!stprev.empty() && stprev.begin()->first < X[i])
        {
            at = max(stprev.begin()->second, at);
            stprev.erase(stprev.begin());
        }
        stprev.insert({X[i], at});
        mxprev = max(mxprev, at+X[i]);
        dp[i] = max(dp[i], mxprev);

        // Segment from i to j(>1)
        
        at = i-1;
        while (!stnx.empty() && stnx.top().second > X[i])
        {
            if (C[stnx.top().first] > C[at]) at = stnx.top().first;
            stnx.pop();
        }
        stnx.push({at, X[i]});
        pl v = {P[i]+C[at]-X[i], at};
        mxnx = max(mxnx, v);
        dp[i] = max(dp[i], v.first);

        swap(v.first, v.second);
        v.first = MXP[v.first];
        v.second -= v.first;        
        stprev.insert(v);
    }
    
    if (dp != dp2) {
        for (int i = 1; i <= n; i++) cout << X[i] << ' ';
    cout << '\n';

    for (int i = 1; i <= n; i++) cout << dp2[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << '\n' << endl;
    }
    assert(dp == dp2);
    // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    // cout << '\n';
}

void solve(vi &X, ll at) {
    if (at == 5) {
        // for (auto a : X) cout << a << ' ';
        // cout << "|\n";
        solve(X);
        return;
    }
    for (int i = -3; i <= 3; i++)
    {
        X.push_back(i);
        solve(X, at+1);
        X.pop_back();
    }
        
}

int main() {
    int t = 1;
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

    // cin >> t;
    while (t--)
    {
        vi X(1,0);
        solve(X, 0);
    }
}
