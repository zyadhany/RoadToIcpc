#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

class TreeNode {
public:
    int value;
    vector<TreeNode*> children;

    TreeNode(int val) : value(val) {}
};

void dfs(TreeNode* node, vector<int>& values) {
    if (!node) return;
    values.push_back(node->value);  // Collect the node's value
    for (TreeNode* child : node->children) {
        dfs(child, values);  // Recur for each child
    }
}

int longestIncreasingSubsequence(const vector<int>& values) {
    vector<int> dp;  // This will store the end elements of the current LIS
    for (int value : values) {
        // Use lower_bound to find the first element that is not less than value
        auto it = lower_bound(dp.begin(), dp.end(), value);
        if (it == dp.end()) {
            dp.push_back(value);  // Extend the LIS
        } else {
            *it = value;  // Replace the existing element
        }
    }
    return dp.size();  // Length of LIS
}

int findLISInTree(TreeNode* root) {
    vector<int> values;
    dfs(root, values);  // Collect values using DFS
    return longestIncreasingSubsequence(values);  // Calculate LIS
}

int main() {
    int n;
    cin >> n;  // Read number of nodes

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];  // Read values of nodes
    }

    // Create tree nodes
    vector<TreeNode*> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = new TreeNode(values[i]);
    }

    // Read edges and build the tree
    for (int i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;  // Read edge (u, v)
        nodes[u]->children.push_back(nodes[v]);  // Add edge to the tree
        nodes[v]->children.push_back(nodes[u]);  // Add edge to the tree
    }

    // Find the longest increasing subsequence in the tree
    int lengthLIS = findLISInTree(nodes[0]);  // Assuming root is the first node
    cout << lengthLIS << endl;  // Output the length of LIS

    // Clean up memory (not shown for brevity)

    return 0;
}
