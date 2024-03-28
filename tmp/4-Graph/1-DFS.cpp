
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