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
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

ll tkzero(ll n, ll d) {
    string s = to_string(n);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0' + d) {
            s[i]++;
            for (int j = i + 1; j < s.size(); j++)
                s[j] = '0' + (d == 0);
            break;
        }
    }

    return (stoll(s) - n);
}

ll solve(int tc) {
    ll n, d;

    cin >> n >> d;

    if (d != 9) return tkzero(n, d);
    
    string s = to_string(n);
    ll at = s.size() - 1;
    while (s.find('9') != string::npos)
    {
        ll re = s.find('9');
        while (at >= re)
        {
            s[at] = '0';
            at--;
        }
        
        if (re) s[re - 1]++;
        else
        {
            s = "1" + s;
            break;
        }
    }
    
    return (stoll(s) - n);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) cout << solve(i) << '\n';
}
