void SLIDING(multiset<ll> &L, multiset<ll> &R, ll &l, ll &r){
    ll n = R.size() + L.size();

    while (R.size() < n / 2)
    {
        auto it = L.end();
        it--;
        l -= *it;
        r += *it;
        R.insert(*it);
        L.erase(it);
    }
    
    while (L.size() < (n + 1) / 2)
    {
        L.insert(*R.begin());
        l += *R.begin();
        r -= *R.begin();
        R.erase(R.begin());
    }
    if (R.empty() || L.empty()) return;
    
    ll a, b;
    auto tt = L.end();
    tt--;
    a = *tt;
    b = *R.begin();

    while (a > b)
    {
        l -= a;
        l += b;
        r += a;
        r -= b;

        R.erase(R.begin());
        R.insert(a);

        L.erase(tt);
        L.insert(b);

        tt = L.end();
        tt--;
        a = *tt;
        b = *R.begin();
    }
    
}

void solve(ll tc) {
    ll n, k, l, r, summ;

    cin >> n >> k;

    l = r = 0;
    vi X(n);
    multiset<ll> L, R;

    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    for (int i = 0; i < n; i++)
    {
        L.insert(X[i]);
        l += X[i];
        SLIDING(L, R, l, r);
        if (i < k - 1) continue;
        auto it = L.end();
        it--;
        ll re = *it;

        summ = re * L.size() - l;
        summ += r - re * R.size();

        cout << summ << ' ';

        re = X[i - k + 1];
        if (L.find(re) != L.end()) {
            l -= re;
            L.erase(L.find(re));
        }
        else if (R.find(re) != R.end()) {
            r -= re;
            R.erase(R.find(re));
        }
    }
}
