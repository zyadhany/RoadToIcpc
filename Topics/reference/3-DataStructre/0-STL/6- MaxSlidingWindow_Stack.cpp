
struct MaxQueue {
	/**
	 * For each pair<int, int> e, e.first is the value of the element and
	 * e.second is the maximum among all elements in that stack under element e.
	 */
	stack<pair<int, int>> s1, s2;

	/**
	 * Get the maximum element in the MaxQueue.
	 * It is the maximum of both stacks which are stored in s.top().second.
	 */
	int query() {
		if (s1.empty() && s2.empty()) { return -1e9; }
		if (s1.empty() || s2.empty()) {
			return s1.empty() ? s2.top().second : s1.top().second;
		}
		return max(s1.top().second, s2.top().second);
	}

	/**
	 * Add a new element into our MaxQueue. We add the value of this
	 * element itself and the maximum element in the stack s1 after adding.
	 */
	void enqueue(int val) {
		s1.push({val, max(val, (s1.empty() ? val : s1.top().second))});
	}

	/**
	 * Remove the first element from our MaxQueue by poping the top
	 * element from s2.
	 */
	void dequeue() {
		if (s2.empty()) {
			// Move all elements from s1 to s2 when s2 is empty
			while (!s1.empty()) {
				int mx = s2.empty() ? s1.top().first : s2.top().second;
				s2.push({s1.top().first, max(mx, s1.top().first)});
				s1.pop();
			}
		}
		s2.pop();
	}
};

class Solution {
  public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		MaxQueue q;
		vector<int> max_vals;

		// Fill the queue with elements from the first window
		for (int i = 0; i < k; i++) { q.enqueue(nums[i]); }
		max_vals.push_back(q.query());

		/*
		 * We slide the window to the right by removing the first element
		 * from the queue and adding the new element at the end of the queue.
		 * For each window, we add the maximum to our result array max_vals.
		 */
		for (int i = k; i < nums.size(); i++) {
			q.dequeue();
			q.enqueue(nums[i]);
			max_vals.push_back(q.query());
		}

		return max_vals;
	}
};