#include <iostream>
#include <vector>

using namespace std;

int n;

struct node {

	int sum, greater, begin, end, lazy, mid, qtd, on;

	vector<node> sons;

	node(int begin_ = 1, int end_ = n, int lazy_ = 0, int on_ = 0, int sum_ = 0, int greater_ = 0) {

		sum = sum_, greater = greater_, begin = begin_, end = end_, lazy = lazy_, on = on_;

		mid = (begin + end) / 2, qtd = end - begin + 1;
	}

	void flush() {

		if (sons.empty() && end > begin) {

			sons.push_back(node(begin, mid));
			sons.push_back(node(mid + 1, end));
		}

		if (on) {

			if (end > begin) {

				sons[0].lazy = sons[1].lazy = lazy;
				sons[0].on = sons[1].on = on;
			}

			sum = greater = qtd * lazy;
		}

		lazy = on = 0;
	}

	int query(int h) {

		flush();

		if (begin == end) {

			if (greater > h) return begin - 1;
			return begin;
		}

		sons[0].flush();

		if (sons[0].greater > h) return sons[0].query(h);
		return sons[1].query(h - sons[0].sum);
	}

	void update(int a, int b, int d) {

		flush();

		if (a > end || b < begin) return;

		if (a <= begin && b >= end) {

			lazy = d;
			on = 1;
			flush();
			return;
		}

		sons[0].update(a, b, d);
		sons[1].update(a, b, d);

		sum = sons[0].sum + sons[1].sum;
		greater = max(sons[0].greater, sons[0].sum + sons[1].greater);
	}
};

int main() {

	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;

	node segtree;

	char op;

	while (cin >> op && op != 'E') {

		if (op == 'Q') {

			int h;
			cin >> h;

			cout << segtree.query(h) << '\n';
		}

		if (op == 'I') {

			int a, b, d;
			cin >> a >> b >> d;

			segtree.update(a, b, d);
		}
	}

	return 0;
}