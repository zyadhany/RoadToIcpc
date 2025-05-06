#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll int
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

const int MODE = 1e9+7;

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

vi sol(string s, string t, bool rev = 0) {
    ll n = s.size(), m = t.size();

    vi res(3);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i] == t[j]) res = {1, i, j};
    
    for (int i = 1; i < n; i++)
    {
        string s1 = s.substr(0, i), s2 = s.substr(i, n - i);
        string t2 =t;

        reverse(all(s1)); reverse(all(t2));
        s1 += "#" + t2;
        s2 += "#" + t;
        auto dp1 = BuildLPS(s1);
        auto dp2 = BuildLPS(s2);
        for (int j = 0; j < m-1; j++)
        {
            ll a = dp2[n-i+1 + j];
            ll b = dp1[i + m-1-j];
            
            vi re = {a+b, i-b, j+1 - a};
            if (rev) re[2] = m-1-j-b;
            res = max(re, res);
        }
    }

    return res;
}

void solve(int tc)  {
    string s, t;
    cin >> s >> t;

    auto re = sol(s, t);
    reverse(all(t));
    re = max(re, sol(s, t, 1));


    cout << re[0] << '\n';
    cout << re[1] << ' ' << re[2] << '\n';
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
