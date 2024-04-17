void BFS(int s)
{
    queue<int> que;
    que.push(s);

    while (!que.empty())
    {
        int m = que.front();
        que.pop();
        if (vis[m]) continue;
        vis[m] = 1;
        
        for (auto a : adj[m]) {
            if (!vis[a]) {
                que.push(a);
            }
        }
    }
}
