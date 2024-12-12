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

    vi X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];

    ll sol = 0;
    vi Z(k + 10);
    for (auto a : X) {
        sol += a / k;
        Z[a % k]++;
    }


    ll l = 1, r = k - 1;
    while (l < r)
    {
        if (!Z[l]) {l++; continue;}
        if (!Z[r]) {r--; continue;}
        if (l + r < k) {l++; continue;}
        sol++;
        Z[l]--, Z[r]--;
    }
    if (l * 2 >= k) sol += Z[l] / 2;

    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("sabotage.in", "r", stdin);
    // freopen("sabotage.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
