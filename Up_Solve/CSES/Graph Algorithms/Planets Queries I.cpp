#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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
 
const int MODE = 998244353;
 
const int MAX = 2e5 + 5, log2dist = 30;
ll pow2ends[MAX][log2dist+1];
 
class Tree { 
  public:
	Tree(const vi &par) {
		// pow2ends[n][k] contains the 2^kth parent of node n
		// if there is no 2^kth parent, the value is -1
		for (int n = 0; n < par.size(); n++) { pow2ends[n][0] = par[n];}
		for (int p = 1; p <= log2dist; p++) {
			for (int n = 0; n < par.size(); n++) {
					pow2ends[n][p] = pow2ends[pow2ends[n][p - 1]][p - 1];
			}
		}
	}
 
	/** @return the kth parent of node n */
	ll kth_parent(ll n, ll k) {
		ll at = n;
		// break down k llo powers of 2 by looping through its bits
		for (ll pow = 0; pow <= log2dist; pow++) {
			if ((k & (1ll << pow)) != 0) {
				at = pow2ends[at][pow];
				if (at == -1) {
					break;  // stop when we're past the root
				}
			}
		}
		return at;
	}
};
 
 
void solve(ll tc) {
    ll n, q;
 
    cin >> n >> q;
 
    vi X(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> X[i];
 
    Tree gr(X);
 
    while (q--)
    {
        ll u, k; cin >> u >> k;
        cout << gr.kth_parent(u, k) << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}