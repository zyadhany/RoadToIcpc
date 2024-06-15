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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

const int MODE = 1e9 + 7;



void solve(ll tc) {
    ll n, k, l, r, at;

    cin >> n >> k;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    l = *max_element(all(X)), r = 1e15;

    while (l < r)
    {
        at = (l + r) / 2;

        ll re, summ;
        re = summ = 0;

        for (int i = 0; i < n; i++)
        {
            if (summ + X[i] > at) summ = 0, re++;
            summ += X[i];
        }
        re += (summ > 0);

        if (re <= k) r = at;
        else l = at + 1;
    }
    
    cout << l << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
