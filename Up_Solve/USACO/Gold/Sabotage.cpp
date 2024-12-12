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

void solve(int tc) {
    ll n; cin >> n;

    vi X(n);

    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    ld l = 1, r = 1e5, err = 0.0000001;

    while (r - l > err)
    {
        ld mid = (l + r) / 2;
        bool isit = 0;

        ld mx, summ;
        ll tot = 0;
        for (auto a : X) tot += a;
        
        mx = summ = X[1] - mid;
        for (int i = 2; i < n - 1; i++)
        {
            if (summ < 0) summ = 0;
            summ += X[i] - mid;
            mx = max(mx, summ);
        }
        
        if (mx >= tot - n * mid) r = mid;
        else l = mid + err;
    }


    cout << fixed << setprecision(3) << l << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
