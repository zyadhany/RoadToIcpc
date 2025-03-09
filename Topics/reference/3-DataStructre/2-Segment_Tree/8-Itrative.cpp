template <class T> class MinSegmentTree {
  private:
	const T DEFAULT = std::numeric_limits<T>().max();

	vector<T> segtree;
	int len;

  public:
	MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);
		}
	}

	T range_min(int start, int end) {
		T min = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { min = std::min(min, segtree[start++]); }
			if (end % 2 == 1) { min = std::min(min, segtree[--end]); }
		}
		return min;
	}
};
