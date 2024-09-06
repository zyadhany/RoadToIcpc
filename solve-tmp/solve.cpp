#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

ll req(string s) {
    ll n = s.size();
    ll ans = 0;
    for (int i = 1; i < n; i++) ans += (s[i] == s[i - 1]);
    return ans;
}

void solve(int tc) {
    ll n;
    string s;

    cin >> n >> s;

    ll cnt = count(all(s), 'F');

    if (cnt == n) {
        cout << n << "\n";
        for (int i = 0; i <= n - 1; i++)
            cout << i << "\n";
        return;
    }

    ll re = 0;
    while (s[re] == 'F') re++;
    s = s.substr(re, - 1);

    string t = s;
    for (int i = 1; i < t.size(); i++)
        if (t[i] == 'F') {
            if (t[i - 1] == 'B') t[i] = 'E';
            else t[i] = 'B';
        }
    
    ll mn = req(t);

    t = s;
    for (int i = 1; i < t.size(); i++)
        if (t[i] == 'F') t[i] = t[i - 1];
    ll mx = req(t) + re;

    bool isit = 1;
    if (re || s.back() == 'F') isit = 0;

    set<ll> ans;
    for (int i = mn; i <= mx; i+= 1 + isit)
        ans.insert(i);
    
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("hoofball.in", "r", stdin);
    //freopen("hoofball.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
