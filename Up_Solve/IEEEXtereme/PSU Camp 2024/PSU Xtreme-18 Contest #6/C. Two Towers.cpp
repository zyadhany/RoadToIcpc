#include<bits/stdc++.h>

//My codes-------------->>>>
#define vi vector<int>
#define vc vector<char>
#define vii vector<vi>
#define vcc vector<vc>
#define ll long long
#define ld long double
#define sortx(X) sort(X.begin(),X.end());

using namespace std;

void FP()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

ll samm(ll n) {
	return (n * (n + 1)) / 2;
}

void solve() {
	string a, s;
	int n, r;
	cin >> n >> r >>s >> a;
	reverse(a.begin(), a.end());
	s += a;
	n = 0;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == s[i-1])
		{
			n++;
		}
	}
	if (n > 1)
	{
		cout << "NO\n";
	}
	else cout << "YES\n";

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
