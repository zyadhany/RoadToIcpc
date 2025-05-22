//faster time;
vi suffixarray(string& s, int lim = 128)
{
    s += '$';
    int n = s.size() + 1, cl = lim;
    vi sa(n), c(n), cn(n), pn(n), cnt(max(n, lim));
    iota(pn.begin(), pn.end(), 0);
    for (int i = 0; i < n - 1; i++) c[i] = s[i];
 
    for (int k = 0; k <= n; k = k ? 2 * k : 1)
    {
        if (k) for (int i = 0; i < n; i++) pn[i] = (sa[i] + n - k) % n;
        for (int i = 0; i < cl; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < cl; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--cnt[c[pn[i]]]] = pn[i];
 
        cn[sa[0]] = 0;
        cl = 1;
        for (int i = 1; i < n; i++)
        {
            if (c[sa[i]] != c[sa[i - 1]] || c[(sa[i] + k) % n] != c[(sa[i - 1] + k) % n])
            cl++;
            cn[sa[i]] = cl - 1;
        }
        if (cl == n) break;
        swap(c, cn);
    }
    sa.erase(sa.begin());;
 
    return sa;
}
