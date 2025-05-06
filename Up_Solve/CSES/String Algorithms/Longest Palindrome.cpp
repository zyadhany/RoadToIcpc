#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;

const int MODE = 998244353;

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

void solve(int tc)  {
    string s; 
    cin >> s;
    cout << longetPLandrom(s) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("dec.in", "r", stdin);
    // freopen("dec.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
