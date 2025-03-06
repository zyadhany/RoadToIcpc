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
