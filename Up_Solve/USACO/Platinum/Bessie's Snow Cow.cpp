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

const int MXN = 1e5+10;
int trav=1;
int ST[MXN]={0}, EN[MXN]={0};
vi adj[MXN];
deque<pair<ll, vi>> OP[MXN];
vi B1(MXN), B2(MXN);

void add(vector<long long>& b, int idx, long long x) {
    for (; idx <= MXN; idx += idx & -idx)
        b[idx] += x;
}

long long sum(const vector<long long>& b, int idx) {
    long long total = 0;
    for (; idx > 0; idx -= idx & -idx)
        total += b[idx];
    return total;
}

void range_add(int l, int r, long long x) {
    add(B1, l, x);
    add(B1, r + 1, -x);
    add(B2, l, x * (l - 1));
    add(B2, r + 1, -x * r);
}

long long prefix_sum(int idx) {
    return sum(B1, idx) * idx - sum(B2, idx);
}

long long range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
}

void dfs(ll n, ll p) {
	ST[n] = trav++;
	for (auto neg : adj[n]) if (neg != p) dfs(neg, n);
	EN[n] = trav-1;
}

void solve(int tc) {
	ll n, q; cin >> n >> q;

	for (int i = 0; i < n-1; i++)
	{
		ll u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);

	vii Q(q, vi(3));
	for (int i = 0; i < q; i++)
	{
		cin >> Q[i][0] >> Q[i][1];
		if (Q[i][0] == 1) {
			cin >> Q[i][2];
			OP[Q[i][2]].push_back({Q[i][1], vi()});
		}
	}

	for (int c = 0; c < MXN; c++)
	{
		set<pl> st;
		for (int i = OP[c].size() - 1; i >= 0; i--)
		{
			ll v = OP[c][i].first;
			while (true)
			{
				auto it = st.lower_bound(pl(ST[v], 0));
				if (it == st.end() || it->first > EN[v]) break;
				OP[c][it->second].first = -1;
				st.erase(it);
			}
			st.insert({ST[v], i});
		}
		st.clear();
		for (int i = 0; i < OP[c].size(); i++)
		{
			ll v = OP[c][i].first;
			while (true)
			{
				auto it = st.lower_bound(pl(ST[v], 0));
				if (it == st.end() || it->first > EN[v]) break;
				OP[c][i].second.push_back(OP[c][it->second].first);
				st.erase(it);
			}
			st.insert({ST[v], i});
		}
	}
	
	
	for (auto pq : Q) {
		ll ty, x, c;
		ty = pq[0], x = pq[1], c = pq[2];

		if (ty == 1) {
			auto [v, Y] = OP[c].front();
			OP[c].pop_front();
			if (v == -1) continue;
			range_add(ST[v], EN[v], 1);
			for (auto a : Y) {
				range_add(ST[a], EN[a], -1);
			}
		} else {
			ll res = range_sum(ST[x], EN[x]);
			cout << res << '\n';
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
