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
