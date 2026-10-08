// count occurrences of pattern 't' in 's' using suffix array
ll countocc(vector<int> &suff, string &s, string &t) {
    ll L =-1, R=-2;

    auto cmp = [&](ll j) -> int {
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] != s[i+j]) {
                return -1 + 2 * (s[i+j] > t[i]);
            }
        }
        return 0;
    };
    ll l, r;
    
    l = 0, r = suff.size()-1;
    while (l<=r)
    {
        ll mid = (l+r)/2;
        ll c = cmp(suff[mid]);
        if (c == 1) r = mid-1;
        else if (c == -1) l=mid+1;
        else {
            L = mid;
            r = mid-1;
        }
    }

    l = 0, r = suff.size()-1;
    while (l<=r)
    {
        ll mid = (l+r)/2;
        ll c = cmp(suff[mid]);
        if (c == 1) r = mid-1;
        else if (c == -1) l=mid+1;
        else {
            R = mid;
            l = mid+1;
        }
    }

    return R - L + 1;
}


// Longest common substring of two strings using suffix array
ll longestCommonSubstring(const string &s, const string &t) {
    ll n = s.size(), m = t.size();
    if (n == 0 || m == 0) return 0;

    // Concatenate s and t with '%' (suffixarray appends '$' internally)
    string k;
    k.reserve(n + m + 2);
    k += s;
    k += '%';
    k += t;

    auto suff = suffixarray(k);
    auto [lcp, ind] = LCP(suff, k);

    ll mx = 0;
    ll pos_s = -1, pos_t = -1;

    int total_len = suff.size();
    for (int i = 0; i < total_len - 1; i++) {
        if (lcp[i] <= mx) continue;

        bool in_s1 = (suff[i] < n);
        bool in_s2 = (suff[i + 1] < n);

        if (in_s1 == in_s2) continue;
        if (suff[i] == n || suff[i + 1] == n) continue;

        mx = lcp[i];
        if (in_s1) {
            pos_s = suff[i];
            pos_t = suff[i + 1] - n - 1;
        } else {
            pos_s = suff[i + 1];
            pos_t = suff[i] - n - 1;
        }
    }

    // pos_s and pos_t give the starting indices; string is s.substr(pos_s, mx)
    return mx;
}
