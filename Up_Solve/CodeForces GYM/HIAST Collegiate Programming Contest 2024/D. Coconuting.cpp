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

ll summtion(ll n) {
    return n * (n - 1) / 2;
}

void solve(int tc) {
    ll n, summ, mx;

    cin >> n;

    summ = mx = 0;
    unordered_map<int, int> X;
    X.reserve(n);

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        X[a]++;
        mx = max(mx, a);
    }
    
    for (auto m : X) {
        ll k = 0;

        for (int i = m.first; ; i+=m.first)
        {
            ll re = i / m.first;
            re *= re * i;
            if (re > mx) break;
            if (X.count(re)) k += X[re];
        }

        for (int i = 0; i < m.second; i++)
        {
            k--;
            summ += k;
        }
    }

    cout << summ << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
