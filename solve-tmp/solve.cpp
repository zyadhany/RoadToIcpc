#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;

const int MAXSZ = 1e7 + 1;
int prime[MAXSZ] = {0};
vi primes;
 
void INIT() {
    for (int i = 0; i < MAXSZ; i++) prime[i] = i;
    for (int i = 2; i * i < MAXSZ; ++i) if (prime[i] == i)
        for (int j = i; j < MAXSZ; j += i) prime[j] = i;
    for (int i = 2; i < MAXSZ; i++) if(prime[i] == i) primes.push_back(i);
}

vp factorizationCnt(int n) {
    if (n == 1) return {};
    vi fac;
    while(n > 1) fac.push_back(prime[n]), n /= prime[n];
    vp faccnt;
    pl re = {fac[0], 1};
    for (int i = 1; i < fac.size(); i++)
    {
        if (fac[i] == re.first) re.second++;
        else faccnt.push_back(re), re = {fac[i], 1};
    }
    faccnt.push_back(re);
    return faccnt;
}

ll req(vp &X, ll k) {
	ll cnt = 0;
	sortx(X);

	ll v = 1;
	for (auto [p, frq] : X) {
		while (frq--)
		{
			if (v * p <= k) {
				v *= p;
			} else v = p, cnt++;
		}
	}
	if (v != 1) cnt++;

	return cnt;
}

void solve(int tc) {
	ll x, y, k;

	cin >> x >> y >> k;

	auto X = factorizationCnt(x);
	auto Y = factorizationCnt(y);
	
	mi mx, my;
	for (auto &p : X) mx[p.first] = p.second;
	for (auto &p : Y) my[p.first] = p.second;

	vp add, rem;

	for (auto p : mx) {
		ll re = my[p.first] - p.second;
		if (re==0) continue;
		if (p.first > k) MUN;
		if (re > 0) add.push_back({p.first, re});
		else rem.push_back({p.first, -re});
	}

	for (auto p : my) {
		if (mx.find(p.first) != mx.end()) continue;
		if (p.first > k) MUN;
		add.push_back({p.first, p.second});
	}

	for (auto p : add) cout << p.first << ' ' << p.second << '\n';
	cout << "||\n";
	for (auto p : rem) cout << p.first << ' ' << p.second << '\n';

	ll cnt = req(add, k) + req(rem, k);
	cout << cnt << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

	INIT();
    // freopen("lightsout.in", "r", stdin);
    // freopen("lightsout.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
