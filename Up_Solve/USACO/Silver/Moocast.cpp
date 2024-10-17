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
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n;

    cin >> n;

    vii X(n + 1, vi(3));
    for (int i = 1; i <= n; i++)
        cin >> X[i][0] >> X[i][1] >> X[i][2];
    
    vii Y(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll xs = X[i][0];
        ll ys = X[i][1];
        ll pw = X[i][2];
    
        for (int j = 1; j <= n; j++)
        {
            if (j == i) continue;
            ll xe = X[j][0];
            ll ye = X[j][1];
            ll dist = (xe - xs) * (xe - xs) + (ye - ys) * (ye - ys);
            if (dist <= pw * pw) Y[i].push_back(j);
        }
    }

    ll mx = 0;
    for (int i = 1; i <= n; i++)
    {
        vi vis(n + 1);
        stack<ll> st;
        st.push(i);
        vis[i] = 1;
        ll cnt = 1;
        while (!st.empty())
        {
            ll m = st.top();
            st.pop();
            for (auto neg : Y[m]) {
                if (!vis[neg]) {
                    st.push(neg);
                    cnt++;
                    vis[neg] = 1;
                }
            }
        }
        
        mx = max(mx, cnt);
    }
    
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
