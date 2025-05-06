// count prefix occurences of leangth i in string s.
vi countPrefixOccur(string &s) {
    ll n = s.size();
    auto pi = kmp(s);
    vi ans(n + 1);
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;
    for (int i = n-1; i > 0; i--)
        ans[pi[i-1]] += ans[i];
    for (int i = 0; i <= n; i++)
        ans[i]++;
    return ans;
}
