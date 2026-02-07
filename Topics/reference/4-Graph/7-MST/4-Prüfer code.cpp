/*
    purfer code: secuence of operations to construct a tree
    - for a tree with n nodes, the code has n-2 numbers
    - it's Bijection: each tree hax unique code and vice versa
*/

/*
    Cayley's formula: number of labeled trees with n nodes is n^(n-2)
    number of way to connect graph with n nodes and k components is n^(k-2) * s_1 * s_2 * ... * s_k
    where s_i is the size of component i -> that add k-1 edges to connect the components
*/


/*
To generate the Prüfer code from a given tree, we can follow these steps:
- get the leaf with the smallest label
- add its neighbor to the code
- remove the leaf from the tree

it's secuence of n-2 numbers for a tree with n nodes (n must be in the last 2 remaining nodes)
*/

// O(n)
vector<vector<int>> adj;
vector<int> parent;
void dfs(int v) {
    for (int u : adj[v]) {
        if (u != parent[v]) {
            parent[u] = v;
            dfs(u);
        }
    }
}
vector<int> pruefer_code() {
    int n = adj.size();
    parent.resize(n);
    parent[n-1] = -1;
    dfs(n-1);

    int ptr = -1;
    vector<int> degree(n);
    for (int i = 0; i < n; i++) {
        degree[i] = adj[i].size();
        if (degree[i] == 1 && ptr == -1)
            ptr = i;
    }

    vector<int> code(n - 2);
    int leaf = ptr;
    for (int i = 0; i < n - 2; i++) {
        int next = parent[leaf];
        code[i] = next;
        if (--degree[next] == 1 && next < ptr) {
            leaf = next;
        } else {
            ptr++;
            while (degree[ptr] != 1)
                ptr++;
            leaf = ptr;
        }
    }

    return code;
}


/*
restore the tree from the pruefer code
- we can easily know the degree of each node from the code and reverse the process
*/
vector<vector<int>> adj;
vector<int> parent;

void dfs(int v) {
    for (int u : adj[v]) {
        if (u != parent[v]) {
            parent[u] = v;
            dfs(u);
        }
    }
}

vector<int> pruefer_code() {
    int n = adj.size();
    parent.resize(n);
    parent[n-1] = -1;
    dfs(n-1);

    int ptr = -1;
    vector<int> degree(n);
    for (int i = 0; i < n; i++) {
        degree[i] = adj[i].size();
        if (degree[i] == 1 && ptr == -1)
            ptr = i;
    }

    vector<int> code(n - 2);
    int leaf = ptr;
    for (int i = 0; i < n - 2; i++) {
        int next = parent[leaf];
        code[i] = next;
        if (--degree[next] == 1 && next < ptr) {
            leaf = next;
        } else {
            ptr++;
            while (degree[ptr] != 1)
                ptr++;
            leaf = ptr;
        }
    }

    return code;
}