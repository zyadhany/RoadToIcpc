#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
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

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    string s;
    cin >> s;

    ll res = 0;


    unordered_map<int, vi> M;
    M.reserve(s.size() + 1);
    M[0].push_back(0);

    ll pref = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0') pref--;
        else pref++;
        M[pref].push_back(i + 1);
    }
    
    for (auto &m : M) {
        vi X = m.second;
        ll n = X.size();
        vi suff(n);
        suff[n - 1] = (s.size() + 1 - X.back());
        for (int i = n - 2; i >= 0; i--)
            suff[i] = (suff[i + 1] + (s.size() + 1 - X[i])) % MODE;
        
        for (int i = 0; i < n - 1; i++)
        {
            ll re = ((X[i] + 1) * (suff[i + 1])) % MODE;
            res = (res + re) % MODE;
        }
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
