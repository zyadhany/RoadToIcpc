/*
* get ind of first greater element to right for each element
* if you want to make it to left, reverse loop (n - 1 -> 0).
* you can change oppration:
* >, first element less than.
* <=, first element greater than or equal.
*/
vi MonomaticStack(vi& X)
{
    ll n = X.size();
    stack<pair<ll, ll>> s;
    vi Z(n, -1);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first < X[i]) {
            Z[s.top().second] = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }

    return (Z);
}


/**
 * you can use monomatix stack to get largest histo.
 * get first element smaller than you at left and right.
 * in that case we use 2 mono, or we can do that algorithm.
*/
ll LargestHistogram(vi &arr)
{
    ll n = arr.size(), mx = 0, at;
    stack<pl> st;

    for (int i = 0; i < n; i++)
    {
        at = i;
        while (!st.empty() && st.top().first >= arr[i])
        {
            mx = max(mx, st.top().first * (i - st.top().second));
            at = st.top().second;
            st.pop();
        }
        st.push({arr[i], at});
    }
    
    while (!st.empty())
    {
        mx = max(mx, st.top().first * (n - st.top().second));
        st.pop();
    }

    return (mx);
}

