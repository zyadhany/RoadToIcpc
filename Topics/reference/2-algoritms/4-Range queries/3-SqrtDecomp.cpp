
/**
 * Sqrt Decomposition: O(sqrt(n)) query for sum of [l, r)
 * sprate array into blocks of size sqrt(n) and store sum of each block.
 * Update: O(1) set nums[x] to v, just update block of x.
 * Query: O(sqrt(n)) sum of [l, r) by iterating over blocks and elements.
 */
struct Sqrt {
	int block_size;
	vi nums;
	vi blocks;
	Sqrt(vi &arr) : block_size((int)ceil(sqrt(arr.size()))), blocks(arr.size(), 0) {
		nums = arr;
		for (int i = 0; i < nums.size(); i++) { blocks[i / block_size] += nums[i]; }
	}

	/** O(1) update to set nums[x] to v */
	void update(int x, ll v) {
		blocks[x / block_size] -= nums[x];
		nums[x] = v;
		blocks[x / block_size] += nums[x];
	}

	/** O(sqrt(n)) query for sum of [0, r) */
	ll query(int r) {
		ll res = 0;
		for (int i = 0; i < r / block_size; i++) { res += blocks[i]; }
		for (int i = (r / block_size) * block_size; i <= r; i++) { res += nums[i]; }
		return res;
	}

	/** O(sqrt(n)) query for sum of [l, r) */
	ll query(int l, int r) { return query(r) - query(l - 1); }
};
