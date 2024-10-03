#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Cow {
	int weight;
	int pos;
	int speed;
};

int main() {

	int cow_num;
	int barn_pos;
	std::cin >> cow_num >> barn_pos;

	vector<Cow> cows(cow_num);
	int total_weight = 0;
	for (Cow &c : cows) {
		std::cin >> c.weight >> c.pos >> c.speed;
		total_weight += c.weight;
	}

	std::sort(cows.begin(), cows.end(),
	          [](const Cow &c1, const Cow &c2) { return c1.pos < c2.pos; });

	// get the cows that start off going to the left & right
	vector<Cow> left;
	vector<Cow> right;
	for (const Cow &c : cows) {
		if (c.speed == -1) {
			left.push_back(c);
		} else if (c.speed == 1) {
			right.push_back(c);
		}
	}

	/*
	 * calculate each of the times when the cows meet the end
	 * the leftmost cows get all of the -1 cow's positions as their times,
	 * and similarly for the rightmost ones
	 */
	vector<std::pair<int, int>> weight_times;
	for (int c = 0; c < left.size(); c++) {
		// time of arrivial at barn & weight, respectively
		weight_times.push_back({left[c].pos, cows[c].weight});
	}
	for (int c = 0; c < right.size(); c++) {
		weight_times.push_back({barn_pos - right[c].pos, cows[left.size() + c].weight});
	}

	// sort them by their occurrence
	std::sort(weight_times.begin(), weight_times.end(),
	          [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
		          return a.first < b.first;
	          });

	int endTime = -1;
	for (const auto &[time, weight] : weight_times) {
		total_weight -= 2 * weight;
		if (total_weight <= 0) {
			endTime = time;
			break;
		}
	}

	// count how many meetings occur before the end time
	int meeting_num = 0;
	// the cows that a left-going cow can meet before the end time
	std::queue<int> leftSide;
	for (int c = 0; c < cow_num; c++) {
		if (cows[c].speed == 1) {
			leftSide.push(cows[c].pos);
		} else if (cows[c].speed == -1) {
			// remove all the cows that can't meet this left-going cow
			while (!leftSide.empty() && leftSide.front() + 2 * endTime < cows[c].pos) {
				leftSide.pop();
			}
			meeting_num += leftSide.size();
		}
	}

	std::cout << meeting_num << endl;
}