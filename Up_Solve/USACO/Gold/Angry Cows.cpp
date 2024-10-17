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

ld getdis(ld a, ld b, ld da, ld db) {
    ld re = max(a, b) + 1;
    ld dis = (db - da) / 2.0;
    return max(re, dis);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];
    sortx(X);

    vi L(n);
    vi PL(n);
    vi R(n);
    vi PR(n);
    PR[n - 1] = n - 1;
    for (int i = 1; i < n; i++) {
        ll l = L[i - 1] + 1;
        ll r = X[i] - X[i - 1];
        if (l > r) {
            ll dist = X[i] - X[PL[i - 1]];
            if (dist <= l) L[i] = L[i - 1], PL[i] = PL[i - 1];
            else L[i] = l, PL[i] = i - 1;
        } else L[i] = r, PL[i] = i - 1;
    }
    
    for (int i = n - 2; i >= 0; i--) {
        ll l = R[i + 1] + 1;
        ll r = X[i + 1] - X[i];
        if (l > r) {
            ll dist = X[PR[i + 1]] - X[i];
            if (dist <= l) R[i] = R[i + 1], PR[i] = PR[i + 1];
            else R[i] = l, PR[i] = i + 1;
        } else R[i] = r, PR[i] = i + 1;
    }

    ld mn = INT32_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        ll a = PL[i];
        ll b = PR[i + 1];
        mn = min(mn, getdis(L[i], R[i + 1], X[i], X[i + 1]));
        mn = min(mn, getdis(L[i], R[b], X[i], X[b]));
        mn = min(mn, getdis(L[a], R[i + 1], X[a], X[i + 1]));
        mn = min(mn, getdis(L[a], R[b], X[a], X[b]));
    }

    cout << fixed << setprecision(1) << mn << '\n';       
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
