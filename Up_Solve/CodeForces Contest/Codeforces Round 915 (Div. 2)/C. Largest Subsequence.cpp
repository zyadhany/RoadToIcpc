#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


const int MODE = 998244353;

using namespace std;

// get lexicographically Largest subseq
vp lexicographicallyLargestSubSeq(string &s) {
    vp res;
    for (int i = 0; i < s.size(); i++)
    {
        while (!res.empty() && res.back().first < s[i])
            res.pop_back();
        res.push_back({s[i], i});
    }
    return (res);
}

void solve(int tc) {
    ll n, res;
    string s;

    cin >> n >> s;

    auto Z = lexicographicallyLargestSubSeq(s);    
    res = Z.size();

    for (int i = Z.size() - 1; i >= 0; i--)
    {
        res -= (Z[i].first == Z[0].first);
        s[Z[Z.size() - 1 - i].second] = Z[i].first;
    }
    
    for (int i = 1; i < n; i++)
        if (s[i] < s[i - 1]) {
            cout << "-1\n";
            return;
        }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
