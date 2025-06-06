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

void solve(int tc)  {
    string s;

    cin >> s;

    auto pi = BuildLPS(s);

    vi res;

    ll at = s.size()-1;
    while (pi[at])
    {
        res.push_back(pi[at]);
        at = pi[at]-1;
    }

    reverse(all(res));
    for (auto a : res) cout << a << ' ';
    cout << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
    // freopen("dec.in", "r", stdin);
    // freopen("dec.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}
