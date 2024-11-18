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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n;

    cin >> n;

    vi pw3(3e5 + 1, 1);
    vi pw20(3e5 + 1, 1);
    vi pw7(3e5 + 1, 1);
    for (int i = 1; i < pw3.size(); i++) {
        pw3[i] = (pw3[i - 1] * 3) % MODE;
        pw20[i] = (pw20[i - 1] * 20) % MODE;
        pw7[i] = (pw7[i - 1] * 7) % MODE;
    }
    
    ll sol = 0;
    for (int i = 0; i < n; i++)
    {
        ll re = ((pw7[i] * 20) % MODE * pw3[n * 3 - (i + 1) * 3]) % MODE;
        sol = (sol + re) % MODE;
    }

    cout << sol << '\n';
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
