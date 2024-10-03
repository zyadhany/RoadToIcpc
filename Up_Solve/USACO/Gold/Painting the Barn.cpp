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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}


const int MODE = 1e9 + 7;

using namespace std;    

const int SIZE = 200;
vii X(SIZE, vi(SIZE));
vii Y(SIZE, vi(SIZE));
vii dp(SIZE, vi(SIZE, -1));

ll getMax(ll l, ll r) {
    if (l == SIZE || r == SIZE) return 0;
    ll &res = dp[l][r];
    if (res != -1) return res;


    for (int j = l; j < SIZE; j++)
    {
        ll summ = 0;
        for (int h = r; h < SIZE; h++)
        {
            ll re = Y[j][h];
            if (l) re -= Y[l - 1][h];
            summ += re;
            if (summ < 0) summ = 0;
            res = max(res, summ);
        }
    }        

    res = max(res, getMax(l + 1, r));
    return res;
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;


    for (int i = 0; i < n; i++)
    {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int a = x1; a < x2; a++)
            for (int b = y1; b < y2; b++)
                X[b][a]++;
    }

    ll mx = 0;
    ll cnt = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (X[i][j] == k) Y[i][j] = -1, cnt++;
            if (X[i][j] == k - 1) Y[i][j] = 1;
        }       
    }

    for (int i = 1; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            Y[i][j] += Y[i - 1][j];
    

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i; j < SIZE; j++)
        {
            ll summ = 0;
            for (int h = 0; h < SIZE; h++)
            {
                ll re = Y[j][h];
                if (i) re -= Y[i - 1][h];
                summ += re;
                if (summ < 0) summ = 0;

                ll sec = max(getMax(0, h + 1), getMax(j + 1, 0));
                mx = max(mx, summ + sec + cnt);
            }
        }
    }

    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
