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
        cin >> X[i].second;
    for (int i = 0; i < n; i++)
        cin >> X[i].first;
    sortx(X);

    ll cnt = 0;
    ll summ = 0;
    ll at = 0;
    for (int i = 0; i < n; i++)
    {
        if (at == i) {
            at++;
            summ += k;
        }
        
        for (int j = 0; j < X[i].second && at < n; j++)
        {
            summ += min(X[i].first, k);
            at++;
        }
    }
    
    cout << summ << '\n';        
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
