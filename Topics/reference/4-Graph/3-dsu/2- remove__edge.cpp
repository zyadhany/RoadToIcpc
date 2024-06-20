/*
1 p q Union the sets containing p and q. If p and q are already in the same set,
ignore this command.
2 p q Move p to the set containing q. If p and q are already in the same set,
ignore this command.
3 p Return the number of elements and the sum of elements in the set containing p
*/
typedef pl item;
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

    void move(ll l, ll r) {
        int a, b;
		a = get(l), b = get(r);

		if (a == b) return;
		P[l] = l;
        add(l, r);
        op[a].first--;
        op[a].second-=l;
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
		P.assign(n * 2 + 1, 0);
		R.assign(n * 2 + 1, 1);
		op.assign(n * 2 + 1, item());

		for (int i = 1; i <= n; i++) {
			P[i] = P[i + n] = i + n;
            op[i] = op[i + n] = {1, i};
            R[i] = 0;
        }
    }
private:
	vector<int> P, R;
	vector<item> op;

	void marge(item &a, item &b) {
		a.first += b.first;
		a.second += b.second;
	}
    void demarge(item &a, item &b) {
		a.first -= b.first;
		a.second -= b.second;
	}
};
