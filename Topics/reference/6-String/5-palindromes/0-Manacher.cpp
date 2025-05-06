// get all plandromes of odd length
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

/*
By adding a '#' between each character we can find all palindromes of even length and odd length.

d[2*i] = 2*d[i] + 1 (even length)
d[2*i+1] = 2*d[i] (odd length)
*/
vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    for (auto &a : res) a--;
    return vector<int>(begin(res) + 1, end(res));
}

string longetPLandrom(string &s) {
    auto res = manacher(s);
    ll mx = -1, ind = -1;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] > mx) {
            mx = res[i];
            ind = i/2-(mx-1)/2;
        }
    }
    return s.substr(ind, mx);
}
