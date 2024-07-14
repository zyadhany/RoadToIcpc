#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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

vii v(10, vi(7));
vii opp(10, vi(10));

void solve(int tc) {
	ll n, x, y;
	string s, t;

	cin >> n >> x >> y;
	cin >> s >> t;

	viii dp(n + 1, vii(x + 1, vi(y + 1, 0)));

	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		ll l = s[i] - '0';
		ll r = t[i] - '0';
		for (int j = 0; j <= x; j++)
		{
			for (int h = 0; h <= y; h++)
			{
				if (!dp[i][j][h]) continue;
				for (int k = 0; k < 10; k++)
				{
					ll a = opp[l][k] + j;
					ll b = opp[r][k] + h;
					if (a > x || b > y) continue;
					dp[i + 1][a][b] = 1;
				}
			}			
		}
	}
	
	for (int i = 0; i <= x; i++)
		for (int j = 0; j <= y; j++)
			if (dp[n][i][j]) YES;
	NO;	
}

void INIT() {
	v[0] = {1, 1, 1, 1, 1, 1, 0};
    v[1] = {0, 1, 1, 0, 0, 0, 0};
    v[2] = {1, 1, 0, 1, 1, 0, 1};
    v[3] = {1, 1, 1, 1, 0, 0, 1};
    v[4] = {0, 1, 1, 0, 0, 1, 1};
    v[5] = {1, 0, 1, 1, 0, 1, 1};
    v[6] = {1, 0, 1, 1, 1, 1, 1};
    v[7] = {1, 1, 1, 0, 0, 0, 0};
    v[8] = {1, 1, 1, 1, 1, 1, 1};
    v[9] = {1, 1, 1, 1, 0, 1, 1};

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int h = 0; h < 7; h++)
				opp[i][j] += v[i][h] != v[j][h];	
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	INIT();
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
