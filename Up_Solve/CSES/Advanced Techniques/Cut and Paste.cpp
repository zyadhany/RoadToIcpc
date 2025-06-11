#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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
const int MODE = 1e9 + 7;

mt19937 rnd((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
typedef struct item * pitem;
struct item {
    int prior, cnt;
	char value;
    bool rev;
    pitem l, r;
	item(char value) : prior(rnd()), value(value), cnt(1), rev(false), l(NULL), r(NULL) {}
};

int count (pitem it) {
    return it ? it->cnt : 0;
}

void recalc (pitem it) {
    if (it)
        it->cnt = count(it->l) + count(it->r) + 1;
}

void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    recalc (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + count(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + count(t->l)),  l = t;
    recalc (t);
}


void insert (pitem & t, char value) {
	pitem it = new item(value);
	merge(t, t, it);
}

void trav(pitem it) {
	if (!it) return;
	trav(it->l);
	cout << it->value;
	trav(it->r);
}

void solve(int tc) {
	ll n, q; cin >> n >> q;

	string s; cin >> s;

	pitem t = NULL;
	for (auto a : s) insert(t, a);

	while (q--)
	{
		ll l, r; cin >> l >> r;
		l--, r--;
		pitem t1, t2;
		split(t, t, t1, l);	
		split(t1, t1, t2, r-l+1);
		merge(t, t, t2);
		merge(t, t, t1);	
	}
	trav(t);
	cout << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	// freopen("cbarn.in", "r", stdin);
    // freopen("cbarn.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}