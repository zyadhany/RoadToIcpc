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
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;\

using namespace std;

void solve(int tc) {
    ll n, re, a;

    cin >> n;

    queue<ll> X;

    while (n--)
    {
        cin >> re >> a;

        if (re % 2) X.push(a);
        else
        {
            if (X.empty() || X.front() != a) cout << "No\n";
            else cout << "Yes\n";
            if (!X.empty()) X.pop();
        }
     }
    
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
