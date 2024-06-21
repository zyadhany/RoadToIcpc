#define _CRT_SECURE_NO_WARNINGS
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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
const int MODE = 1e9 + 7;
 
using namespace std;
 
 
typedef long long item;
 
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
 
    vp res;
    DSU ds;
    ds.build(n);
 
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        ds.add(a, b);
    }
    
    for (int i = 1; i <= n; i++)
    {
        ll a, b;
        a = ds.get(1), b = ds.get(i);
        if (a != b) {
            res.push_back({1, i});
            ds.add(1, i);
        }
    }
 
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i].first << ' ' << res[i].second << '\n';    
}
 
int main()
{
		ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int size = 1;
 
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
 
		//cin >> size;
		for (int i = 1; i <= size; i++)
				solve(i);
}
