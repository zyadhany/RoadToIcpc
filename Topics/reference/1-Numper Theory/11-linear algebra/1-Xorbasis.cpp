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
// to get number way to get value x from set: first check if it in the basis, if not return 0 otherwise the solution will be (2 ^ (size of set - size of basis))
const int LOG = 62;
struct Basis {
  ll basis[LOG];
  ll cnt;
  Basis() {
    cnt = 0;
    clear();
  };
 
  bool insert(int mask) {
    for (int i = LOG - 1; ~i; --i) {
      if ((mask >> i) & 1) {
        if (!basis[i]) {
          basis[i] = mask;
          cnt++;
          return 1;
        }
        mask ^= basis[i];
      }
    }
    return 0;
  }

  ll orderofkey(ll x) {
        ll k = 1;
        ll c = cnt-1;
        for(int i = LOG - 1; i >= 0; i --) {
            if ((x >> i) & 1) {
                if (!basis[i]) return 0;
                k += (1ll << c);
            }
            c--;
        }
        return k;
    }

  bool get(int mask) {
    for (int i = LOG - 1; ~i; --i) {
      if ((mask >> i) & 1) {
        if (!basis[i]) {
          return 0;
        }
        mask ^= basis[i];
      }
    }
    return 1;
  }
 
  void clear() {
    memset(basis, 0, sizeof basis);
  }
 
  void merge(const Basis &other) {
    for (int i = LOG - 1; ~i; --i) {
      if (other.basis[i]) insert(other.basis[i]);
    }
  }
 
  ll getmax() {
    int ret = 0;
    for (int i = LOG - 1; ~i; --i) {
      if ((ret >> i) & 1) continue;
      ret ^= basis[i];
    }
    return ret;
  }
 
 
    ll kth(ll k) {
        if (k > (1ll << cnt)) return -1;
        ll c = cnt-1;
        ll ret = 0;
        for(int i = LOG - 1; i >= 0; i --) {
            if(!basis[i]) continue;
            if(k > (1ll << c)) {
                k -= (1ll << c);
                ret = max(ret, ret ^ basis[i]);
            }else ret = min(ret, ret ^ basis[i]);
            c--;
        }
        return ret;
    }
};



// find the indies that make Xor = x
ll basis[LOG];
vi P[LOG];
ll cnt;
bool insert(int mask, ll ind) {
	vi res(1, ind);
	for (int i = LOG - 1; ~i; --i) {
		if ((mask >> i) & 1) {
		if (!basis[i]) {
			basis[i] = mask;
			sort(all(res));
			for (auto a : res) {
			if (P[i].empty() || P[i].back() != a) P[i].push_back(a);
			else P[i].pop_back();
			}
			cnt++;
			return 1;
		}
		mask ^= basis[i];
		res.insert(res.begin(), all(P[i]));
		}
	}
	return 0;
}

vi get(int mask) {
	vi res;

	for (int i = LOG - 1; ~i; --i) {
		if ((mask >> i) & 1) {
		if (!basis[i]) {
			return {};
		}
		mask ^= basis[i];
		res.insert(res.begin(), all(P[i]));
		}
	}

	vi R;
	sort(all(res));
	for (auto a : res) {
		if (R.empty() || R.back() != a) R.push_back(a);
		else R.pop_back();
	}
	return R;
}
