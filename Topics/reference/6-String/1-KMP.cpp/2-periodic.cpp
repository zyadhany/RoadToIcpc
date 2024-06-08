// abcabcabc -> period of 3 (abs)
// len = n - fr.back()
// if (n % len == 0) return (len)
vector<int> PeriodKMP(string &s){
    vector<int> fr = BuildLPS(s);
    vector<int> period(fr.size());
    for (int i = 0; i < fr.size(); i++) {
        int len = (i + 1 - fr[i]);
        if ((i + 1) % len) period[i] = i + 1;
        else period[i] = len;
    }
    return (period);
}
