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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n;
    string s;

    cin >> n >> s;

    for (int k = 1; k <= n; k++)
    {
        set<string> st;
        bool isit = 1;

        for (int i = 0; i <= n - k; i++)
        {
            string t = s.substr(i, k);
            if (st.count(t)) {
                isit = 0;
                break;
            }
            st.insert(t);
        }

        if (isit) {
            cout << k << '\n';
            return;
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
