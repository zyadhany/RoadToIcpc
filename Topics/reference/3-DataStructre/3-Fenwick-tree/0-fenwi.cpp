// It work in 1-index

ll rangequery(const vi& BIT, ll l, ll r) {
	ll summ = 0;

	for (int i = r; i > 0; i -= i & -i)
		summ += BIT[i];

	for (int i = l - 1; i > 0; i -= i & -i)
		summ -= BIT[i];

	return summ;
}

void updatepoint(vi& BIT, ll idx, ll val) {
	ll summ = 0;
	//sum = rangequery(BIT, at, at)
	for (int i = idx; i < BIT.size(); i += i & -i)
		BIT[i] += val - summ;
}

// Construct fenwick tree from array in O(n)
FenwickTree(vector<int> const &a) : FenwickTree(a.size()){
    for (int i = 0; i < n; i++) {
        bit[i] += a[i];
        int r = i | (i + 1);
        if (r < n) bit[r] += bit[i];
    }
}

// To fenwik of 2d array we nested loop it to get summ of squir
for (int x; x > 0; x -= x & -x)
		for (int yy = y; yy > 0; yy -= yy & -yy)
			sum += BIT[x][yy];


// I can use it to make sorted dynamic array 
// to insert update(x,+1) delete update(x,-1)
for ( ; i < BIT.size(); i+= i & -i)
		BIT[i]++;


// To get the value of index O(log(n)^2) we use lower pound
while (l < r) {
    at = (l + r) / 2;
    if (k <= sum(at, BIT)) r = at;
    else l = at + 1;
}

// to get all element greater than k in range l , r -> take quary in array and sort in
// I can make fenwick of XoR
// I can binary search for prefix value on it
