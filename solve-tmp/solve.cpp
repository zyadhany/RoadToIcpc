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

vp MonomaticStack(vi& X)
{
    ll n = X.size();
    stack<pair<ll, ll>> s;
    vp Z(n, {0, n});

    for (int i = 1; i < n; i++) {
        while (!s.empty() && s.top().first > X[i]) {
            Z[s.top().second].second = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }
    while (!s.empty()) s.pop();
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && s.top().first >= X[i]) {
            Z[s.top().second].first = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }

    return (Z);
}

ll summtion(ll n) {
    return (n * (n + 1) / 2) % MODE;
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii XG(n, vi(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> XG[i][j];
        }
    }
    
    vii YG(n, vi(m, 1));
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (XG[i][j] == XG[i-1][j]) YG[i][j] += YG[i-1][j];
    
    ll sol = 0;

    for (int row = 0; row < n; row++)
    {
        vi dp(m);
        vi &X = XG[row];
        vi &Y = YG[row];
        
        if (row == 2) {
            for (auto a : Y) cout << a << ' ';
            cout << '\n';
        }

        ll chn = -1;
        stack<ll> st;
        for (int i = 0; i < m; i++)
        {
            if (i && X[i] != X[i-1]) {
                chn = i - 1;
                while (!st.empty()) st.pop();
            }
        
            ll &re = dp[i];
            re = 0;

            while (!st.empty() && Y[st.top()] > Y[i]) {
                st.pop();
            }   
            
            ll ls = chn;
            if (!st.empty()) sol += dp[st.top()], ls = st.top();
            re += (i - ls) * Y[i];
            st.push(i);

            cout << row << ' ' << i << ' ' << st.empty() << endl;
            sol += re;
        }
    }

    cout << sol << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("dishes.in", "r", stdin);
    // freopen("dishes.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
