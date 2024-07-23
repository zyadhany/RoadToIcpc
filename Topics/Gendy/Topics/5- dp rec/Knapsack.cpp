// max weight

int knapsack(int W, const vector<int>& weights) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + weights[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}


int maxWeight = knapsack(W, weights);

--------------------------------------------------

//max profit

int knapSack(int W, vi wt, vi val, int n)
{
    // Making and initializing dp array
    ll dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {

            if (wt[i - 1] <= w)

                // Finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    // Returning the maximum value of knapsack
    return dp[W];
}


void solve(ll test) {

    vi profit = { 200, 100, 120 };
    vi weight = { 10, 20, 30 };
    int W = 50;
    int n = profit.size();
    cout << knapSack(W, weight, profit, n);

}