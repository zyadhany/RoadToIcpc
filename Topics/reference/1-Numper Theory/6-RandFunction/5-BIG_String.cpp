ll BigMODE(string &s, ll k) {
    ll summ = 0;
    for (int i = 0; i < s.size(); i++)
        summ = ((summ * 10) + s[i] - '0') % k;    
    return (summ);
}
