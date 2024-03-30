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
    ll n, k;
    string s;

    cin >> n >> k >> s;

    vi X(26), Y(26);

    for (int i = 0; i < n; i++)
        X[s[i] - 'a']++;

    for (int i = 0; i < 26 && k > 0; i++)
    {
        Y[i] = min(X[i], k);
        k -= X[i];
    }

    for (int i = 0; i < n; i++)
        if (Y[s[i] - 'a']) Y[s[i] - 'a']--;
        else cout << s[i];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}