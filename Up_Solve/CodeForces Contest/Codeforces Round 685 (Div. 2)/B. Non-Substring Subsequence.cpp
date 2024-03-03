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

const int MODE = 1e9 + 7;

using namespace std;



void solve(int tc) {
    ll n, q, l, r, at;
    string s;
    bool good;

    cin >> n >> q >> s;
    
    while (q--)
    {
        cin >> l >> r;

        good = 0;
        l--, r--;
        
        for (int i = 0; i < l; i++)
            if (s[i] == s[l]) good = 1;
        
        for (int i = r + 1; i < n; i++)
            if (s[i] == s[r]) good = 1;

        cout << (good? "YES" : "NO") << '\n';
    }

}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}