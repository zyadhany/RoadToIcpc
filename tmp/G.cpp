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

const int MODE = 998244353;

using namespace std;

ll req (ll at, ll n, ll p, ll k, ll x) {
    if (at == n) return (k == x);
    ll summ = 0;
    for (int i = 0; i < p; i++)
        summ += req(at + 1, n, p, k ^ i, x);
    return (summ);
}

void solve(int tc) {
    ll n, m, k, pw;
    cout << req(0, 3, 4, 0, 2);
    return;

    cin >> n >> k >> m;
    pw = (1 << k);

    vi X(n + 1);


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