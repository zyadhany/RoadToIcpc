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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

vi Z(2e5 + 10);

void solve(int tc) {
    ll l, r;

    cin >> l >> r;

    cout << Z[r] + Z[l] - 2 * Z[l - 1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    for (int i = 1; i < Z.size(); i++)
    {
        ll re = i;
        while (re)
        {
            re /= 3;
            Z[i]++;
        }
        
        Z[i] += Z[i - 1];
    }
    

    //freopen("buckets.in", "r", stdin);
    //freopen("buckets.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}