/*
P[i] = longest prefix wich is also suffix at indext i
P[0] = 0
*/
vector<int> BuildLPS(string &s) {
    int n = s.size();
    vector<int> LPS(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = LPS[i - 1];
        while (j && s[i] != s[j])
            j = LPS[j - 1];
        LPS[i] = j + (s[j] == s[i]);
    }
    
    return (LPS);
}

// search for pattern s in string t.
vector<int> KmpSearch(string &t, string s) {
    int n, m;
    n = s.size(), m = t.size();
    vector<int> res, LPS;
    s += "#" ;s += t;
    LPS = BuildLPS(s);
    for (int i = n + 1; i < LPS.size(); i++)
        if (LPS[i] == n) res.push_back(i - 2 * n);
    return (res);
}
