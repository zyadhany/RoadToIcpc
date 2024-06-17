/**
 * given n project: start time, end time, score.
 * you can't do 2 projects at same time, find max score.
 */
void solve(ll tc) {
    ll n, mx;

    cin >> n;

    mx = 0;
    vii X(n, vi(3));
    priority_queue<pl, vp, greater<pl>> pq;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> X[i][j];
    sortx(X);    

    for (int i = 0; i < n; i++)
    {
        while (!pq.empty() && pq.top().first < X[i][0])
        {
            mx = max(mx, pq.top().second);
            pq.pop();
        }
        
        pq.push({X[i][1], mx + X[i][2]});
    }
    
    while (!pq.empty())
    {
        mx = max(mx, pq.top().second);
        pq.pop();
    }

    cout << mx << '\n';
}
