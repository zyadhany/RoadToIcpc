#include<bits/stdc++.h>

//My codes-------------->>>>
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define vii vector<vi>
#define vcc vector<vc>
#define mi map<int,int>
#define mc map<char,int>
#define ll long long
#define ld long double
#define sortx(X) sort(X.begin(),X.end());

using namespace std;

void FP()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

map<pair<int, int>, ll> Kift;

ll count(ll n, ll m) {
	if (Kift.count({ m,n })) return Kift[{n, m}];
	if (n == 1 || m == 1) return 1;
	if (n == 0 || m == 0) return 0;

	Kift[{m, n}] = count(n - 1, m) + count(n, m - 1);
	Kift[{n, m}] = Kift[{m, n}];
	return Kift[{m,n}];

}

void solve()
{
	ll n;
	cin >> n;
	cout << n / 5 + (n % 5 > 0);
}

int main()
{
	FP();
	int size = 1;
	//cin >> size;
	while (size--)
	{
		solve();
	}

}