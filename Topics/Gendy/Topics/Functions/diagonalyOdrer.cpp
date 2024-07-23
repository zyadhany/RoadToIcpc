/* print 2d vector in diagonaly
1 3 6
2 5 8
4 7 9
*/

vector<ll> findDiagonalOrder(vector<vector<ll>>& nums) {
    vector<ll> res;
    unordered_map<ll, vector<ll>> diagonals;

    int max_diag = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[i].size(); ++j) {
            diagonals[i + j].push_back(nums[i][j]);
            max_diag = max(max_diag, i + j);
        }
    }

    for (int d = 0; d <= max_diag; ++d) {
        auto& diag = diagonals[d];
        res.insert(res.end(), diag.rbegin(), diag.rend()); // Reverse the diagonal to get the correct order
    }

    return res;
}