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

ll commonArea(vi &A, vi &B) {
    if (A[0] > A[2]) swap(A[0], A[2]);
    if (A[1] > A[3]) swap(A[1], A[3]);
    if (B[0] > B[2]) swap(B[0], B[2]);
    if (B[1] > B[3]) swap(B[1], B[3]);
    ll x1 = max(A[0], B[0]);
    ll x2 = min(A[2], B[2]);
    ll y1 = max(A[1], B[1]);
    ll y2 = min(A[3], B[3]);

    if (x1 > x2 || y1 > y2) return 0;
    return (x2 - x1) * (y2 - y1);
}

ll RecArea(vi &A) {
    return (A[2] - A[0]) * (A[3] - A[1]);
}

bool covered(int x, int y, int x1, int y1, int x2, int y2) {
	return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

void solve(int tc) {
    vii X(2, vi(4));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            cin >> X[i][j];
    ll sol = RecArea(X[0]);

    int corner_num = 0;
	if (covered(X[0][0], X[0][1], X[1][0], X[1][1], X[1][2], X[1][3])) corner_num++;
	if (covered(X[0][0], X[0][3], X[1][0], X[1][1], X[1][2], X[1][3])) corner_num++;
	if (covered(X[0][2], X[0][1], X[1][0], X[1][1], X[1][2], X[1][3])) corner_num++;
	if (covered(X[0][2], X[0][3], X[1][0], X[1][1], X[1][2], X[1][3])) corner_num++;

    if (corner_num >= 2) sol -= commonArea(X[0], X[1]);

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
