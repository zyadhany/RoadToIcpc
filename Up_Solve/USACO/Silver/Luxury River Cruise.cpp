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

const int MODE = 1e9;

using namespace std;

void solve(int tc) {
    ll n, m, k;
    cin >> n >> m >> k;

    vp X(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> X[i].first >> X[i].second;

    vc Y(m);
    for (int i = 0; i < m; i++) cin >> Y[i];
    
    ll pw = log2(k) + 1;

    vii SP(n + 1, vi(pw + 1));
    for (int i = 1; i <= n; i++)
    {
        ll at = i;
        for (int j = 0; j < m; j++)
            if (Y[j] == 'L') at = X[at].first;
            else at = X[at].second;        
        SP[i][0] = i; SP[i][1] = at;
    }
    
    for (int j = 2; j <= pw; j++)
        for (int i = 1; i <= n; i++)
            SP[i][j] = SP[SP[i][j - 1]][j - 1];

    ll pt = 1;
    ll ind = 1;
    while (k)
    {
        if (k % 2) pt = SP[pt][ind];
        k /= 2;
        ind++;
    }
    
    cout << pt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
