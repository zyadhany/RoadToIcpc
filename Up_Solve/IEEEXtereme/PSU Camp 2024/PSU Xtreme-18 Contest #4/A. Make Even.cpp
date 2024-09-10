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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    string s;

    cin >> s;

    if (s.back() % 2 == 0) {
        cout << "0\n";
        return;
    }

    if (s[0] % 2 == 0) {
        cout << "1\n";
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] % 2 == 0) {
            cout << "2\n";
            return;
        }
    }
    
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("billboard.in", "r", stdin);
    //freopen("billboard.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
