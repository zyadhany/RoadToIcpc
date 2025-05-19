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

const int MODE = 1e9 + 7;

using namespace std;


typedef pl item;

int sgsz;
const int MXSG = 5e6;
item tree[MXSG];
ll lazy[MXSG];

item merge(item &a, item &b) {
	item res = a;
	if (a.first == b.first) res.second += b.second;
	else if (a.first > b.first) res = b;
	return (res);
}

void checkLazy(int m, int lx, int rx) {
	if (!lazy[m]) return;
	tree[m].first += lazy[m];
	if (lx != rx) {
		lazy[2 * m + 1] += lazy[m];
		lazy[2 * m + 2] += lazy[m];
	}
	lazy[m] = 0;
}

void update(ll l, ll r, ll val, int m=0, int lx=0, int rx=sgsz-1) {
	checkLazy(m, lx, rx);
	if (rx < l || r < lx) return;
	if (l <= lx && rx <= r)
	{
		lazy[m] = val;
		checkLazy(m, lx, rx);
		return;
	}
	int mid = (lx + rx) / 2;
	update(l, r, val, m * 2 + 1, lx, mid);
	update(l, r, val, m * 2 + 2, mid + 1, rx);
	tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
}

item getrange(int l, int r, int m=0, int lx=0, int rx=sgsz-1) {
	checkLazy(m, lx, rx);
	if (rx < l || r < lx) return {INT32_MAX, 0};
	if (l <= lx && rx <= r) return (tree[m]);
	int mid = (lx + rx) / 2;
	item s1, s2;
	s1 = getrange(l, r, m * 2 + 1, lx, mid);
	s2 = getrange(l, r, m * 2 + 2, mid + 1, rx);
	return merge(s1, s2);
}

void build(int m=0, int lx=0, int rx=sgsz-1) {
	if (lx == rx) {
		tree[m] = {0, 1};
		return;
	}
	int mid = (lx + rx) / 2;
	item s1, s2;
	build(m * 2 + 1, lx, mid);
	build(m * 2 + 2, mid + 1, rx);
	s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];
	tree[m] = merge(s1, s2);
}
 
struct query
{
    ll l, r, x, ty;
    query(){}
    query(ll la, ll ra, ll xa, ll tya) {
        l = la;
        r = ra;
        x = xa;
        ty = tya;
    }
    bool operator<(const query& q) {
        if (x != q.x) return x < q.x;
        return ty < q.ty;
    }
};

const int MXV = 2e6+10;
const int SH = MXV / 2;

 
void solve(int tc) {
    ll n;
 
    cin >> n;
 
	vector<vector<query>> Q(MXV);
    for (int i = 0; i < n; i++)
    {
        ll x1, x2, y1, y2;
 
        cin >> x1 >> y1 >> x2 >> y2;
		if (y1 < y2) {
			Q[x1 + SH].push_back(query(y1+1, y2, x1, 0));
			Q[x2 + SH].push_back(query(y1+1, y2, x2, 1));
		}
    }
 
	sgsz = MXV;
	build();
    ll sol = 0;

	for (int i = 0; i < Q.size(); i++)
	{
		for (auto q : Q[i]) {
			if (q.ty == 0) update(q.l+SH, q.r+SH, 1);
			else update(q.l+SH, q.r+SH, -1);
		}
		pl re = getrange(0, MXV-1);
		sol += MXV;
		sol -= re.second;
	}

	cout << sol << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
