/*
if vertix outgoing to losing vertex then it's winning vertex
if vertix outgoing only to winning vertexs then it's losing vertex
if there is some undefined vertex then it's Draw
*/

vector<vector<int>> adj_rev;
vector<bool> winning;
vector<bool> losing;
vector<bool> visited;
vector<int> degree;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj_rev[v]) {
        if (!visited[u]) {
            if (losing[v])
                winning[u] = true;
            else if (--degree[u] == 0)
                losing[u] = true;
            else
                continue;
            dfs(u);
        }
    }
}
