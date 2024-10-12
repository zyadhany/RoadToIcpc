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
#define all(X) X.begin(),X.end()
#define sortx(X) sort(all(X));

using namespace std;

void FP()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

void solve()
{
	ll n, summ = 0, k, w;
	cin >> k >> w >> n;
	summ = k * ((n * (n + 1) / 2)) - w;
	if (summ >=0)
		cout << summ;
	else cout << 0;
}

int main()
{
	FP();
	int size = 1;
	while (size--)
	{
		solve();
	}
}