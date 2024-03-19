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

const int MODE = 998244353;

using namespace std;


void solve(int tc) {
    ll n, re, summ, mx, l, r, a, L, R;

    cin >> n;

    vi X;
    map<ll, vi> Y;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        Y[a].push_back(i);
    }

    mx = 0;

    for (auto m : Y)
    {
        X = m.second;
        X.push_back(INT32_MAX);

        l = r = X[0];
        re = 1;

        for (int i = 1; i < X.size(); i++)
        {
            if (re > mx) {
                mx = re;
                a = m.first;
                L = l;
                R = X[i - 1];
            }
            if (X[i] - X[i - 1] - 1 > re)
            {
                re = 0;
                l = X[i];
            }
            else {
                re -= X[i] - X[i - 1] - 1;
            }
            re++;
        }
        
    }


    cout << a << ' ' << L << ' ' << R << "\n";
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