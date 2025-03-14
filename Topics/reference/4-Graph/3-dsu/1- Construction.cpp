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

/** NO Class **/
const int MXN = 1e6 + 1;
int PAR[MXN];
int RAN[MXN];

ll get(ll k) {
    if (k == PAR[k]) return k;
    return PAR[k] = get(PAR[k]);
}
 
void add(ll u, ll v) {
    u = get(u), v = get(v);
    if (u == v) return;
    if (RAN[u] < RAN[v]) swap(u, v);
    if (RAN[u] == RAN[v]) RAN[u]++;
    PAR[v] = u;    
}
 
void INIT() {
    for (int i = 0; i < MXN; i++) {
        PAR[i] = i;
        RAN[i] = 0;
    } 
}
