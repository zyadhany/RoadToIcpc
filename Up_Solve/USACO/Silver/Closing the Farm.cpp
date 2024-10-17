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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

/**
 * usage:-
 * creat dsu element.
 * DSU du;
 *
 * Functions you can use:
 * @val: get value of set.
 * @get: get the parent of element.
 * @add: marge two elements.
 * @build: build graph with given size.
 *
 * make sure to look at item typedef.
 * you can change marge function to change it's oppration.
*/

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


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii Y(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        Y[u].push_back(v);
        Y[v].push_back(u);
    }

    vi Z(n);
    vi ison(n + 1);
    for (int i = 0; i < n; i++)
        cin >> Z[i];

    ison[Z.back()] = 1;    

    vi res;
    DSU ds;
    ds.build(n);
    res.push_back(1);
    ll conc = 1;
    
    for (int i = n - 2; i >= 0; i--)
    {
        conc++;
        set<ll> st;
        ison[Z[i]] = 1;
        for (auto neg : Y[Z[i]]) {
            if (!ison[neg]) continue;
            st.insert(ds.get(neg));
            ds.add(Z[i], neg);
        }
        conc -= st.size();
        conc += st.count(Z[i]);
        res.push_back(conc == 1);
    }
    

    for (int i = n - 1; i >= 0; i--)
        if (res[i]) cout << "YES\n";
        else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
