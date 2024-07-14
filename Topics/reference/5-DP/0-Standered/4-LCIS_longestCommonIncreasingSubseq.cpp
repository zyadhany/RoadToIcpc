#include <bits/stdc++.h>
using namespace std;

#if __cplusplus < 202002L
template <class T> int ssize(const T& a){ return a.size(); }
#endif
template <class T1, class T2> istream& operator>> (istream& in, pair <T1, T2>& a){ in >> a.first >> a.second; return in; }
template <class T> istream& operator>> (istream& in, vector <T>& a){ for (auto &x: a){ in >> x; } return in; }

using ll = long long;
using ld = long double;

template<class B, class T>
struct fenwick_tree_2d_sparse{
	vector<B> X;
	vector<vector<array<B, 2>>> Y;
	vector<vector<T>> data;
	// O(n * log^2(n))
	fenwick_tree_2d_sparse(vector<pair<array<B, 2>, T>> init): X(init.size()){
		sort(init.begin(), init.end());
		for(auto i = 0; i < (int)init.size(); ++ i) X[i] = init[i].first[0];
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());
		int n = (int)X.size();
		Y.resize(n);
		data.resize(n);
		vector<vector<pair<array<B, 2>, T>>> hold(n);
		for(auto i = 0, x = 0; i < (int)init.size(); ++ i){
			auto [pos, val] = init[i];
			while(X[x] < pos[0]) ++ x;
			hold[x].push_back({{pos[1], pos[0]}, val});
		}
		for(auto x = 1; x <= n; ++ x) if(x + (x & -x) <= n){
			auto &hold0 = hold[x + (x & -x) - 1];
			auto &hold1 = hold[x - 1];
			int size = (int)hold0.size();
			hold0.insert(hold0.end(), hold1.begin(), hold1.end());
		}
		for(auto x = 0; x < n; ++ x){
			auto &Y0 = Y[x];
			auto &hold0 = hold[x];
			auto &data0 = data[x];
			sort(hold0.begin(), hold0.end());
			Y0.resize(hold0.size());
			for(auto j = 0; j < (int)hold0.size(); ++ j) Y0[j] = hold0[j].first;
			Y0.erase(unique(Y0.begin(), Y0.end()), Y0.end());
			data0.resize(Y0.size());
		}
	}
	// O(log^2(n))
	void update(B _p, B _q, T x){
		int p = lower_bound(X.begin(), X.end(), _p) - X.begin();
		assert(p < (int)X.size() && X[p] == _p);
		for(auto i = p + 1; i <= (int)X.size(); i += i & -i){
			auto &Y0 = Y[i - 1];
			auto &data0 = data[i - 1];
			int q = lower_bound(Y0.begin(), Y0.end(), array{_q, _p}) - Y0.begin();
			assert(q < (int)Y0.size() && Y0[q][0] == _q && Y0[q][1] == _p);
			for(auto j = q + 1; j <= (int)data0.size(); j += j & -j) data0[j - 1] = max(data0[j - 1], x);
		}
	}
	// O(log^2(n))
	T prefix(B _xr, B _yr) const{
		int xr = lower_bound(X.begin(), X.end(), _xr) - X.begin();
		T res = 0;
		for(auto i = xr; i > 0; i -= i & -i){
			auto &Y0 = Y[i - 1];
			auto &data0 = data[i - 1];
			int yr = lower_bound(Y0.begin(), Y0.end(), array{_yr, numeric_limits<B>::min()}) - Y0.begin();
			for(auto j = yr; j > 0; j -= j & -j) res = max(res, data0[j - 1]);
		}
		return res;
	}
};

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (fopen("KEK.inp", "r")){
		freopen("KEK.inp", "r", stdin);
		freopen("KEK.out", "w", stdout);
	}
int tests; cin >> tests; while (tests--){
	int n;
	cin >> n;
	vector <int> a(n), b(n);
	cin >> a >> b;
	for (auto &x: a){
		x--;
	}
	for (auto &x: b){
		x--;
	}

	vector <int> pos_a(n), pos_b(n);
	for (auto i = 0; i < n; i++){
		pos_a[a[i]] = i;
		pos_b[b[i]] = i;
	}

	vector <pair <array <int, 2>, int>> cells;
	for (auto val = 0; val < n; val++){
		cells.emplace_back(array <int, 2>{{pos_a[val], pos_b[val]}}, 0);
	}
	fenwick_tree_2d_sparse fen(cells);

	auto ans = 0;
	for (auto val = 0; val < n; val++){
		auto tans = fen.prefix(pos_a[val], pos_b[val]) + 1;
		fen.update(pos_a[val], pos_b[val], tans);
		ans = max(ans, tans);
	}
	cout << ans << "\n";
}
}
