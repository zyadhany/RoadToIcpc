
// get longest common increasing subsequence of multiple arrays
// very hight time complexirt // template from gemmnie (not trusted )
vector<int> lcis(const vector<vector<int>>& vec) {
    int n = vec.size();
    if (n == 0) return {};
    for (int i = 0; i < n; i++) {
        if (vec[i].empty()) return {};
    }

    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        unordered_set<int> unique_vals(vec[i].begin(), vec[i].end());
        for (int x : unique_vals) count[x]++;
    }

    unordered_set<int> common;
    for (auto& [val, freq] : count) {
        if (freq == n) common.insert(val);
    }

    if (common.empty()) return {};

    vector<unordered_map<int, vector<int>>> pos(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)vec[i].size(); j++) {
            if (common.count(vec[i][j])) {
                pos[i][vec[i][j]].push_back(j);
            }
        }
    }

    map<vector<int>, pair<int, vector<int>>> memo;

    auto solve = [&](auto& self, vector<int> p) -> pair<int, vector<int>> {
        if (memo.count(p)) return memo[p];

        int max_len = 0;
        vector<int> best_next;
        unordered_set<int> seen;
        int sz0 = vec[0].size();

        for (int i = p[0] + 1; i < sz0; i++) {
            int x = vec[0][i];
            if (p[0] != -1 && x <= vec[0][p[0]]) continue;
            if (!common.count(x) || seen.count(x)) continue;
            seen.insert(x);

            bool ok = true;
            vector<int> next_p(n);
            next_p[0] = i;

            for (int r = 1; r < n; r++) {
                auto it = pos[r].find(x);
                if (it == pos[r].end()) {
                    ok = false;
                    break;
                }
                const auto& v_pos = it->second;
                auto ub = upper_bound(v_pos.begin(), v_pos.end(), p[r]);
                if (ub == v_pos.end()) {
                    ok = false;
                    break;
                }
                next_p[r] = *ub;
            }

            if (ok) {
                auto res = self(self, next_p);
                if (1 + res.first > max_len) {
                    max_len = 1 + res.first;
                    best_next = next_p;
                }
            }
        }

        return memo[p] = {max_len, best_next};
    };

    vector<int> init_p(n, -1);
    solve(solve, init_p);

    vector<int> ans;
    vector<int> curr_p = init_p;
    while (memo.count(curr_p) && memo[curr_p].first > 0) {
        curr_p = memo[curr_p].second;
        ans.push_back(vec[0][curr_p[0]]);
    }

    return ans;
}