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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, k, summ, re, m;

    cin >> n >> k;

    summ = re = m = 0;
    vi X(n), Y(2010), Z(n);

    for (int i = 0; i < n; i++) {
        cin >> X[i];
        Z[i] = X[i];
    }

    sortx(Z);
    reverse(all(Z));

    for (int i = 0; i < k; i++)
        Y[Z[i]]++, summ += Z[i];

    cout << summ << "\n";
    for (int i = 0; i < n; i++)
    {
        re++;
        if (Y[X[i]]) {
            m++;
            if (m == k) re += n - i - 1;
            cout << re << ' ';
            re = 0;
            Y[X[i]]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}