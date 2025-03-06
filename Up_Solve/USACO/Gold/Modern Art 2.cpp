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


void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);
    vi freq(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        freq[X[i]]++;
    }
        
    stack<ll> st;

    int mx = 0;
    vi vis(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (!X[i]) {
            if (!st.empty()) MUN;
            continue;
        }

        freq[X[i]]--;
        if (!vis[X[i]]) {
            st.push(X[i]);
            vis[X[i]] = 1;
            mx = max(mx, int(st.size()));
        }

        if (st.top() != X[i]) MUN;
        if (freq[X[i]] == 0) st.pop();
    }
    
    cout << mx << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
