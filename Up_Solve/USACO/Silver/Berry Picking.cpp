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
    ll n, k;

    cin >> n >> k;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    ll sol = 0;
    ll MX = *max_element(all(X));

    for (int b = 1; b <= MX ; b++) {
        ll cnt = 0;
        vi Z;
        for (auto a : X) cnt += a / b, Z.push_back(a % b);

        if (cnt >= k) {
            sol = b * (k / 2);
            continue;
        }

        sort(Z.rbegin(), Z.rend());
        ll summ = b * (cnt - k / 2);
        for (int i = 0; i < n && i < k - cnt; i++)
            summ += Z[i];

        sol = max(sol, summ);
    }
    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
