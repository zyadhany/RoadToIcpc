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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}


const int MODE = 998244353;

using namespace std;    

typedef long long item;
/*
struct item
{
	int val;

	item(){
		val = 0;
	}
};
*/

class DSU
{
public:

	item val(int n) {
		return(op[get(n)]);
	}

	int get(int n) {
		if (P[n] == n) return (n);
		return (P[n] = get(P[n]));
	}

	void add(int l, int r) {
		int a, b;
		a = get(l), b = get(r);

		if (a == b) return;

		if (R[a] == R[b])
			R[a]++;
		else if (R[a] < R[b])
			swap(a, b);

		P[b] = a;
		marge(op[a], op[b]);
	}

	void build(int n) {
		P.assign(n + 1, 0);
		R.assign(n + 1, 0);
		op.assign(n + 1, item());

		for (int i = 0; i <= n; i++)
			P[i] = i;
	}
private:
	vector<int> P, R;
	vector<item> op;

	void marge(item &a, item &b) {
		/*any oppration you want*/
	}
};

struct worm
{
    int st;
    int en;
    int wid;
};

bool comp(worm a, worm b) {
    return a.wid < b.wid;
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vi X(n);
    vector<worm> Y(m);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    for (int i = 0; i < m; i++)
        cin >> Y[i].st >> Y[i].en >> Y[i].wid;

    sort(Y.begin(), Y.end(), comp);

    ll l = 0, r = m + 1;
    while (l < r)
    {
        ll at = (l + r + 1) / 2;
        DSU ds;
        ds.build(n);
        bool isit = 1;

        for (int i = at; i < m; i++)
            ds.add(Y[i].st, Y[i].en);    

        for (int i = 0; i < n; i++)
        {
            ll a = ds.get(i + 1);
            ll b = ds.get(X[i]);
            if (a != b) isit = 0;
        }
        
        if (isit) l = at;
        else r = at - 1;
    }
    
    if (l == m + 1) cout << "-1\n";
    else cout << Y[l].wid << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
