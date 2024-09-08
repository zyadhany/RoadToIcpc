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

vi commonEdge(vi &A, vi &B) {
    ll x1 = max(A[0], B[0]);
    ll x2 = min(A[2], B[2]);
    ll y1 = max(A[1], B[1]);
    ll y2 = min(A[3], B[3]);

    if (x1 > x2 || y1 > y2) return vi(4, -1);
    return {x1, y1, x2, y2};
}

ll RecArea(vi &A) {
    return (A[2] - A[0]) * (A[3] - A[1]);
}

ll commonArea(vi &A, vi &B) {
    vi rec = commonEdge(A, B);
    return RecArea(rec);
}


void solve(int tc) {
    ll H, W;
    ll x1, x2, y1, y2;
    ll a, b;    

    cin >> W >> H;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a >> b;

    ll w = x2 - x1;
    ll h = y2 - y1;
    ll mn = INT32_MAX;

    if (W - w >= a) {
        mn = min({mn, a - x1, x2 - W + a});
    }

    if (H - h >= b) {
        mn = min({mn, b - y1, y2 - H + b});
    }
    
    if (mn == INT32_MAX) MUN;
    cout << max(mn, 0ll) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("billboard.in", "r", stdin);
    //freopen("billboard.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
