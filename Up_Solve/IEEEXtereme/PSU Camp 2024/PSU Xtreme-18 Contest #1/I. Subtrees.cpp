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
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

ll cnt = 0;

pl req(vii &Y, string &s, ll n) {
    pl cl  {0, 0};

    if (s[n - 1] == 'B') cl.first++;
    else cl.second++;

    for (auto neg : Y[n]) {
        pl tmp = req(Y, s, neg);
        cl.first += tmp.first;
        cl.second += tmp.second;
    }

    cnt += (cl.first == cl.second);
    return cl;
}

void solve(int tc) {
    ll n;
    string s;

    cin >> n;

    cnt = 0;
    vii Y(n + 1);
    
    for (int i = 2; i <= n; i++)
    {
        ll a; cin >> a;
        Y[a].push_back(i);
    }
    
    cin >> s;

    req(Y, s, 1);

    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
