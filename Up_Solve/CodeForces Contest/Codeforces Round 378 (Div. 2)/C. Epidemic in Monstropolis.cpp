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


void solve(int tc) {
    ll n, m, l, r, re, k, mx;

    cin >> n;

    l = r = 0;
    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        l += X[i];
    }

    cin >> m;

    vi Y(m);
    for (int i = 0; i < m; i++)
    {
        cin >> Y[i];
        r += Y[i];
    }

    if (l != r) NO;

    vii Z(m);
    l = r = 0;

    for (int i = 0; i < n; i++)
    {
        l += X[i];
        if (l > Y[r]) NO;
        Z[r].push_back(X[i]);
        if (l == Y[r]) {
            l = 0;
            r++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int issame = 1;
        for (int j = 0; j < Z[i].size(); j++)
        {
            if (Z[i][j] != Z[i][0]) {
                issame = 0;
                break;
            }
        }

        if (!issame || Z[i].size() == 1) continue;
        NO;
    }
    cout << "YES\n";

    for (int i = 0; i < m; i++)
    {
        mx = *max_element(all(Z[i]));

        for (int j = 0; j < Z[i].size(); j++)
        {
            if (Z[i][j] != mx) continue;
            if (Z[i][max(0, j - 1)] != mx) {
                re = j;
                break;
            }
            if (Z[i][min(j + 1ll, n - 1)] != mx) {
                re = j;
                break;
            }
        }
        l = re;
        r = Z[i].size() - re - 1;
        if (l && r) {
            if (Z[i][re - 1] == Z[i][re]) {
                r--;
                cout << re + i + 1 << ' ' << 'R' << '\n';
            }
        }

        while (l--)
        {
            cout << re + i + 1 << ' ' << 'L' << '\n';
            re--;
        }
        while (r--)
        {
            cout << re + i + 1 << ' ' << 'R' << '\n';
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}