#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll int
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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


const int MODE = 1e9 + 7;

using namespace std;

 

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vi Z(n + 10);

    for (int i = 0; i < k; i++)
    {
        ll l, r;
        cin >> l >> r;
        Z[l]++;
        Z[r + 1]--;
    }
    
    ll mx = 0;
    ll at = 0;
    ll re = 0;
    for (int i = 1; i <= n; i++)
    {
        re += Z[i];
        Z[i] += Z[i - 1];
        if (re) at = i;
        else mx = max(mx, i - at);
    }

    ll s = INT32_MAX, e = 0;
    for (int i = 1; i <= n; i++)
        if (Z[i]) s = min(s, i), e = max(e, i);
    
    mx = max(mx,n - e + s - 1);
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
