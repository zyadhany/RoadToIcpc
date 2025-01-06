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


/**
 * It use factorial fourmal of nCr,
 * use mod inv to avoid overflow.
 * Time O(n) - Build.
 * Time O(log(n)) - query.
 * Space O(n).
*/

const int SIZE = 1e6 + 1;
const int MODE = 998244353;
vi fac(SIZE, 1), facinv(SIZE, 1);

ll nCr(ll n, ll r) {
    if (n < r || n < 0) return 0;
    if (n == 0) return 1;
    ll res = fac[n];
    res *= (facinv[r] * facinv[n - r]) % MODE;
    return (res) % MODE;
}

void INIT() {
    facinv[0] = facinv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = (i * fac[i - 1]) % MODE;
        facinv[i] = MODE - MODE / i * facinv[MODE%i] % MODE;
    }
    for (int i = 2; i < SIZE; i++)
        facinv[i] = (facinv[i] * facinv[i-1])%MODE;
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    n--;
    vector<vector<ld>> prob(n+1, vector<ld>(n+1));
    prob[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		prob[i][0] = prob[i - 1][0] / 2;
		for (int j = 1; j <= n; j++)
			prob[i][j] = (prob[i - 1][j] + prob[i - 1][j - 1]) / 2;
	}   
    
    vector<ld> P(n+1), S(n + 1), C(n + 1);
    C[n] = prob[n][n];
    S[n] = C[n] * n;
    P[0] = prob[n][0];
    for (int i = n - 1; i >= 0; i--) {
        P[n-i]=P[n-i-1]+prob[n][n-i];
        C[i] = C[i+1] + prob[n][i];
        S[i] = prob[n][i] * i + S[i+1];    
    }

    ld res = S[0];
    k--;
    while (k)
    {
        ll at = (ll)floor(res);
        ld a = P[at], b = S[at+1];
        
        ll l = 1, r = k;
        while (l < r)
        {
            ll mid = (l + r) / 2;
            
            ld re = res * pow(a, mid) + b * (pow(a, mid)-1) / (a-1);
            ll nw = (ll) floor(re);
            if (nw > at) r = mid;
            else l = mid + 1;
        }
        l = min(l, k);
        res = res * pow(a, l) + b * (pow(a, l)-1) / (a-1);
        k -= l;
    }

    cout << fixed << setprecision(9) << res + 1 << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    INIT();
    // freopen("help.in", "r", stdin);
    // freopen("help.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
