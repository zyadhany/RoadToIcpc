// Get all median for prefix of array
vector<ll> getMedian(vector<ll> &X)
{
    priority_queue<ll> L;
    priority_queue<ll, vector<ll>, greater<ll>> R;
    vector<ll> res;

    for (int i = 0; i < X.size(); i++)
    {
        if (!L.empty() && X[i] > L.top())
            R.push(X[i]);
        else
            L.push(X[i]);
    
        while (L.size() > R.size() + 1)
        {
            R.push(L.top());
            L.pop();
        }

        while (R.size() > L.size())
        {
            L.push(R.top());
            R.pop();
        }

        res.push_back(L.top());
    }

    return (res);
}

// Min element in window of size k, Time: O(n)
vector<ll> minSlidingWindow(vector<ll> &X, ll k)
{
    deque<ll> Q;
    vector<ll> res;

    for (int i = 0; i < X.size(); i++)
    {
        // remove elements out of window
        while (!Q.empty() && Q.front() < i - k + 1)
            Q.pop_front();
        
        // remove elements that are not useful
        while (!Q.empty() && X[Q.back()] > X[i])
            Q.pop_back();

        Q.push_back(i);
    }

    return (res);
}
