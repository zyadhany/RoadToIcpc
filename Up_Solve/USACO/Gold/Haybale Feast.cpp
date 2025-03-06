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
    ll n, k;

    cin >> n >> k;

    vp X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first >> X[i].second;
    }
    
    ll at = 0;
    multiset<ll> st;
    ll sol = INT32_MAX;
    ll summ = 0;
    for (int i = 0; i < n; i++)
    {
        summ += X[i].first;
        st.insert(X[i].second);
        while (summ - X[at].first >= k) {
            st.erase(st.find(X[at].second));
            summ -= X[at].first;
            at++;
        }
        if (summ >= k) sol = min(sol, *prev(st.end()));
    }

    cout << sol << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
