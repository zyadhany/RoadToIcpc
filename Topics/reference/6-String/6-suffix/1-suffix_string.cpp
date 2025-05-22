void radix_Sort(vector<int>& X,vector<int> &Z) {
    int n = X.size(), re = 0;
    vector<int> Y(max(n, 255)), K(n);

    for (int i = 0; i < n; i++)
        Y[Z[X[i]]]++;

    for (int i = 0; i < Y.size(); i++)
        re += Y[i],Y[i] = re - Y[i];

    for (int i = 0; i < n; i++)
        K[Y[Z[X[i]]]] = X[i],Y[Z[X[i]]]++;

    X = K;
}

void suff(vector<int>& X, vector<int>& Z, ll k) {
    int n = X.size();

    for (int i = 0; i < n; i++) X[i] = (X[i] - k + n) % n;

    radix_Sort(X, Z);
    vector<int> K(n);
    K[X[0]] = 0;

    for (int i = 1; i < n; i++)
        if (Z[X[i]] != Z[X[i - 1]] || Z[(X[i] + k) % n] != Z[(X[i - 1] + k) % n])
            K[X[i]] = K[X[i - 1]] + 1;
        else K[X[i]] = K[X[i - 1]];

    if (k * 2 < Z.size()) suff(X, K, k * 2);
}

vector<int> suffix(string &s) {
    s += '$';
    int n = s.size();
    vector<int> Z(n), X(n);

    for (int i = 0; i < n; i++)
        Z[i] = s[i], X[i] = i;

    radix_Sort(X, Z);

    Z[X[0]] = 0;
    for (int i = 1; i < n; i++)
        if (s[X[i]] == s[X[i-1]])Z[X[i]] = Z[X[i-1]];
        else Z[X[i]] = Z[X[i - 1]] + 1;

    suff(X, Z, 1);

    return X;
}
