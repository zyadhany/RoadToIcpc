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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
using namespace std;
 
const int MODE = 1e9 + 7;

ll bit[1001][1001];
int n;

void update(int x, int y, int val) {
	for (; x <= n; x += (x & (-x))) {
		for (int i = y; i <= n; i += (i & (-i))) { bit[x][i] += val; }
	}
}

int query(int x1, int y1, int x2, int y2) {
	int ans = 0;
	for (int i = x2; i; i -= (i & (-i))) {
		for (int j = y2; j; j -= (j & (-j))) { ans += bit[i][j]; }
	}
	for (int i = x2; i; i -= (i & (-i))) {
		for (int j = y1 - 1; j; j -= (j & (-j))) { ans -= bit[i][j]; }
	}
	for (int i = x1 - 1; i; i -= (i & (-i))) {
		for (int j = y2; j; j -= (j & (-j))) { ans -= bit[i][j]; }
	}
	for (int i = x1 - 1; i; i -= (i & (-i))) {
		for (int j = y1 - 1; j; j -= (j & (-j))) { ans += bit[i][j]; }
	}
	return ans;
}


void solve(ll tc) {
    ll q;

    cin >> n >> q;
    vcc X(n + 1, vc(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> X[i][j];
            if (X[i][j] == '*') update(i, j, 1);
        }
        
    }
    
    while (q--)
    {
        ll opp, l, r, xl, xr, yl, yr;

        cin >> opp;

        if (opp == 1) {
            cin >> l >> r;
            if (X[l][r] == '*') {
                X[l][r] = '.';
                update(l, r, -1);
            }else {
                X[l][r] = '*';
                update(l, r, 1);
            }
        } else
        {
            cin >> xl >> yl >> xr >> yr;
            if (xl > xr) swap(xl, xr);
            if (yl > yr) swap(yl, yr);
            cout << query(xl, yl, xr, yr) << '\n';
        }
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
