/**
 * Combining algorithms:
 * 
 * For problem we Have 2 solutions, both run in O(n^2) time.
 * but one is faster for low values of n and the other is faster for high values of n.
 * we can combine them to run first if k < sqrt(n) and the other if k >= sqrt(n).
 * At end we get solution with O(nsqrt(n)) time.
 */


 /**
  * Batch updates:
  * 
  * if solutin is O(n^2) and we can sprate it into sqrt(n) batches.
  * at the begining if each patch we make preprocessing then add query to buffer so we can answer each query in O(1) + size of buffer.
  * total time will be O(nsqrt(n)).
  */

// Example patching for range sum updates:
int n, q;
vector<int> arr;
vector<long long> prefix;

void build() {
	prefix[0] = 0;
	for (int i = 1; i <= n; i++) { prefix[i] = prefix[i - 1] + arr[i - 1]; }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> q;
	arr.resize(n);
	for (int i = 0; i < n; i++) { cin >> arr[i]; }
	prefix.assign(n + 1, 0);
	build();

	vector<pair<int, int>> updates;
	for (int i = 0; i < q; i++) {
		int type, a, b;
		cin >> type >> a >> b;
		if (type == 1) {
			a--;
			updates.push_back({a, b - arr[a]});
			arr[a] = b;
		} else {
			long long ans = prefix[b] - prefix[a - 1];
			a--, b--;
			for (const auto &[idx, val] : updates) {
				if (a <= idx && idx <= b) { ans += val; }
			}
			cout << ans << "\n";
		}

		// rebuild the prefix array once the buffer gets to sqrt(n)
		if (updates.size() * updates.size() >= n) {
			updates.clear();
			build();
		}
	}
}
