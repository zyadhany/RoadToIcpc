int basis[d]; // basis[i] keeps the mask of the vector whose f value is i

int sz; // Current size of the basis

void insertVector(int mask) {
	for (int i = 0; i < d; i++) {
		if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;
			
			return;
		}

		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}


// simple way to do that
vector<ll> basis;
void add(ll x) {
	for (int i = 0; i < (int)basis.size();
	     i++) {  // reduce x using the current basis vectors
		x = min(x, x ^ basis[i]);
	}

	if (x != 0) { basis.push_back(x); }
}

// to get max value optined I can itrate through the basis and sol = max(sol, sol ^ basis[i]);
// if I have intial value I can do the same for min value.