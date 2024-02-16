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
#define YES {cout << "Yes\n"; return;}
#define NO {cout << "No\n"; return;}

const int MODE = 998244353;

using namespace std;

ll req(string& s, char a) {
    ll l = 1, r = s.size(), at;
    bool isit;

    while (l < r)
    {
        at = (l + r) / 2;
        isit = 1;

        for (int i = 0; i <= s.size() - at; i++)
        {
            for (int j = i; j < at + i && j < s.size(); j++)
            {
                if (s[j] == a) {
                    i = j;
                    goto EE;
                }
            }
            isit = 0;
            break;
        EE:;
        }

        if (isit) r = at;
        else l = at + 1;
    }
    
    return (l);
}

void solve(int tc) {
    ll n, mn = INT32_MAX;
    string s;

    cin >> s;

    for (char i = 'a'; i <= 'z'; i++)
        mn = min(mn, req(s, i));

    cout << mn << '\n';;
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}