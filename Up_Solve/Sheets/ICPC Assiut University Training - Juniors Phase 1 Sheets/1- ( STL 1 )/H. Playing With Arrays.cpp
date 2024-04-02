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

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, at;

    cin >> n;

    at = 0;
    deque<ll> X(n), Z(n);

    for (int i = 0; i < n; i++)
    {
        X[i] = i;
    }
    
    for (int i = 0; i < n; i++)
    {
        Z[X.front()] = i + 1;
        X.pop_front();
        X.push_back(X.front());
        X.pop_front();
    }

    for (int i = 0; i < n; i++)
    {
        cout << Z[i];
        if (i != n - 1) cout << ' ';
    }
    cout << '\n';
}   

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
