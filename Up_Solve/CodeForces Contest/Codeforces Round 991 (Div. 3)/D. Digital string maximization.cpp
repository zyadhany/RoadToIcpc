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

const int MX = 1e5 + 1;

void solve(int tc) {
    ll n;
    string s;

    cin >> s;
    n = s.size();

    for (int i = 0; i < s.size(); i++) {
        ll at, mx;
        at = i;
        mx = s[i] - '0';

        for (int j = i + 1; j < i + 9 && j < n; j++)
        {
            if (s[j] - '0' - j + i > mx) {
                mx = s[j] - '0' - j + i;
                at = j;
            }
        }
        
        for (int j = at - 1; j >= i; j--) {
            swap(s[j], s[j + 1]);        
            s[j]--;
        }
    }

    cout << s << '\n';
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
