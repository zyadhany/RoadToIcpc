// it used frequency of element to sort.
// O(n + k), k the max element to stode.
vi CountSort(vi &X)
{
    ll n, m;
    n = X.size(), m = *max_element(all(X));
    vi Y(m + 1);
    vi Z(n);

    for (int i = 0; i < n; i++) Y[X[i]]++;
    
    int at = 0;
    for (int i = 0; i <= m; i++)
        if (Y[i]) X[at++] = i;

    return (Z);
}
