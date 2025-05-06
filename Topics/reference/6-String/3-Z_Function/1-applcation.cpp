// itrate over string by adding one char at a time and count the number of new substring.
ll countalloccur(string &s) {
    ll sol = 0;

    for (int i = 0; i < s.size(); i++)
    {
        string t = s.substr(0,i+1);
        reverse(all(t));
        auto Z = Z_function(t);
        sol += i + 1 - *max_element(all(Z));
    }
    
    return sol;
}

// Period, compressed string.
ll shortestperiod(string &s) {
    auto Z = Z_function(s);
    for (int i = 1; i < s.size(); i++)
    {
        if (s.size() % i == 0 && Z[i] + i == s.size()) {
            return i;
        }
    }
    return s.size();
}
    
