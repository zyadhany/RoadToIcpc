struct MinStack {
	stack<pair<int, int>> st; // {value, current_min}
	void push(int x) {
		if (st.empty()) st.push({x, x});
		else st.push({x, min(x, st.top().second)});
	}
	void pop() {
		st.pop();
	}
	int top() {
		return st.top().first;
	}
	int get_min() {
		return st.top().second;
	}
	bool empty() {
		return st.empty();
	}
	int size() {
		return st.size();
	}
};

struct MinDeque {
	MinStack front, back;

	void push_front(int x) {
		front.push(x);
	}
	void push_back(int x) {
		back.push(x);
	}

	void pop_front() {
		if (front.empty()) {
			// Move from back to front
			while (!back.empty()) {
				int val = back.top();
				back.pop();
				front.push(val);
			}
		}
		front.pop();
	}

	void pop_back() {
		if (back.empty()) {
			// Move from front to back
			while (!front.empty()) {
				int val = front.top();
				front.pop();
				back.push(val);
			}
		}
		back.pop();
	}

	int get_min() {
		if (front.empty()) return back.get_min();
		if (back.empty()) return front.get_min();
		return min(front.get_min(), back.get_min());
	}

	bool empty() {
		return front.empty() && back.empty();
	}
};