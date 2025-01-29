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

using namespace std;

const int MODE = 1e9 + 7;

void solve(int tc) {
    ll n, k;

    cin >> n >> k;
    
    ll summ = 0;
    vi X(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> X[i];
        summ += X[i];
    }
    sortx(X);

    k += summ;

    vii dp(n + 1, vi(k + 1, 0));
    dp[0][summ] = 1;
    for (int i = 1; i <= n; i++)
    {
        vii Z(n + 1, vi(k + 1, 0));
        for (int j = 0; j <= n; j++)
        {
            for (int h = 0; h <= k; h++)
            {
                if (!dp[j][h]) continue;
                Z[j][h] = (Z[j][h] + (j + 1) * dp[j][h]) % MODE;
                if (j && h + X[i] <= k) Z[j-1][h+X[i]] = (Z[j-1][h+X[i]] + j * dp[j][h]) % MODE;
                if (j < n && h - X[i] >= 0) Z[j+1][h-X[i]] = (Z[j+1][h-X[i]] + dp[j][h]) % MODE;
            }
        }
        swap(Z, dp);
    }

    ll sol = 0;
    for (int i = summ; i <= k; i++)
        sol = (sol + dp[0][i]) % MODE;
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("spainting.in", "r", stdin);
    // freopen("spainting.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
