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
ll samm(ll n) {
	return(n * (n - 1)) / 2;
}
int gcd(int a, int b)
{
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}





void solve()
{
	ll n, m , a , at;
	cin >> n >> m;
	at = n;
	mi X;
	vi Z(n + 1, -1);
	for (int i = 1; i <= m; i++)
	{
		cin >> a;
		if (X[a] == 0 && at >= 0)
		{
			Z[at] = i;
			at--;
			X[a] = 1;
		}
	}
	//out << '|';
	for (int i = 1; i <= n; i++)
	{
		cout << Z[i] << ' ';
	}
	cout << '\n';
}

int main()
{
	FP();
	int size = 1;
	cin >> size;
	while (size--)
	{
		solve();
	}
}
