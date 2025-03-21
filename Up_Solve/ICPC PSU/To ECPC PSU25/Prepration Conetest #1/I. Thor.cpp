#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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

ll MXN = 1e6+1;

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vector<queue<ll>> X(n + 1);
    queue<pl> que;

    ll re = 0;
    ll cnt = 0;
    while (q--)
    {
        ll ty, k; cin >> ty >> k;
        if (ty == 1) {
            X[k].push(re);
            que.push({re, k});
            re++;
            cnt++;
        } else if (ty == 2) {
            cnt-=X[k].size();
            while(!X[k].empty())X[k].pop();
        } else {
            while (!que.empty() && que.front().first < k) {
                ll tp = que.front().second;
                que.pop();
                if (!X[tp].empty() && X[tp].front() < k) cnt--, X[tp].pop();
            }
        }
        
        cout << cnt << '\n';
    }
}   
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
