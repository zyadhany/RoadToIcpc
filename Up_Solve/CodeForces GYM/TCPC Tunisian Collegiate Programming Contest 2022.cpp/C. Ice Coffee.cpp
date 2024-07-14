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

vi divs(1e7 + 1);


void solve(int tc) {
	ll n;

	cin >> n;

	vi X(n), Y(n);

	for (int i = 0; i < n; i++)
		cin >> X[i];
	for (int i = 0; i < n; i++)
		cin >> Y[i];

	ll summ = 0;

	for (int i = 0; i < n; i++)
	{
		while (X[i] != Y[i])
		{
			summ++;
			if (X[i] > Y[i]) X[i] = divs[X[i]];
			else Y[i] = divs[Y[i]];
		}
	}

	cout << summ << '\n';		
}

vi prime(1e7 + 10, 0);
vi primes;

void INIT() {

    for (int i = 0; i < prime.size(); i++) prime[i] = i;
    for (int i = 2; i * i <= 1e7; ++i) if (prime[i] == i)
        for (int j = i; j <= 1e7; j += i) 
			if (prime[j] == j) prime[j] = i;
    for (int i = 2; i <= 1e7; i++) if(prime[i] == i) primes.push_back(i);
	for (int i = 2; i < divs.size(); i++)
		divs[i] = i / prime[i];
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
