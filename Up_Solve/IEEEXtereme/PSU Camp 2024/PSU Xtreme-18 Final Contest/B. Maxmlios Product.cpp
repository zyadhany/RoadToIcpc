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

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n;

    cin >> n;

    vi L, R;

    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        if (a > 0) L.push_back(a);
        else if (a < 0) R.push_back(a);
    }
    
    ll sol = (!L.empty() | (R.size() >= 2));
    
    for (auto a : L) sol *= a;
    
    sortx(R);
    ll st = R.size() % 2;
    for (int i = 0; i < R.size() - st; i++)
        sol *= R[i];
    
    cout << sol << '\n';
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