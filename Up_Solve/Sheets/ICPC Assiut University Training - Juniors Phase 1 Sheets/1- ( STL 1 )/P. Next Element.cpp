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

/*
* get ind of first greater element to right for each element
* if you want to make it to left, reverse loop (n - 1 -> 0).
* you can change oppration:
* >, first element less than.
* <=, first element greater than or equal.
*/
vi MonomaticStack(vi X)
{
    ll n = X.size();
    stack<pair<ll, ll>> s;
    vi Z(n, -1);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first < X[i]) {
            Z[s.top().second] = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }

    return (Z);
}

void solve(int tc) {
    ll n, q, a;

    cin >> n;

    vi X(n), Z(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    cin >> q;

    Z = MonomaticStack(X);

    while (q--)
    {
        cin >> a;
        if (Z[a - 1] == -1) cout << "-1\n";
        else cout << Z[a - 1] + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
