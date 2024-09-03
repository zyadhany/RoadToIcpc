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

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n;

    cin >> n;

    ll summ = 0;
    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        summ += X[i];
    }
    
    vi divs;

    for (int i = 1; i * i <= summ; i++)
    {
        if (summ % i) continue;
        divs.push_back(i);
        divs.push_back(summ / i);
    }
    
    ll mn = n - 1;
    for (auto k : divs) {
        ll at = 0;
        ll re = 0, cnt = 0;

        for (int i = 0; i < n; i++)
        {
            re += X[i];
            if (re == k) {
                re = 0;
                cnt+= i - at;
                at = i + 1;
            }
        }        

        if (!re) mn = min(mn, cnt);
    }

    if (!summ) mn = 0;

    cout << mn << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("balancing.in", "r", stdin);
    //freopen("balancing.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
