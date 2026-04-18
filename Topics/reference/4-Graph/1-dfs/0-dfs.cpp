void DFS(int s)
{
    stack<int> stack;

    stack.push(s);

    while (!stack.empty())
    {
        int m = stack.top();
        stack.pop();

        vis[m] = 1;
        
        for (auto a : adj[m]) {
            if (!vis[a]) {
                stack.push(a);
            }
        }
    }
}


// forward star
/*
int nd = 0;
int head[MAXN], to[MAXE], next[MAXE];
void add(int u, int v) {
    to[nd] = v;
    next[nd] = head[u];
    head[u] = nd++;
}

for (int i = head[u]; i != -1; i = next[i]) {
    int v = to[i];
    // do something with v
}
*/