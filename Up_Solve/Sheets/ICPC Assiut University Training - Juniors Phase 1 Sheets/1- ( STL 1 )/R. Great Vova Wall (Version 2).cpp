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

ll getInd(vp& X, ll k) {
    ll re;
    pl m = { k, INT32_MAX };
    re = upper_bound(all(X), m) - X.begin() - 1;
    if (re < 0 || k > X[re].second) return (-1);
    return (re);
}

void solve(int tc) {
    ll n;

    cin >> n;

    pl k;
    vi X(n);
    stack<pl> Y;


    for (int i = 0; i < n; i++)
        cin >> X[i];

    for (int i = 0; i < n; i++)
    {
        k = { X[i], 1 };
        while (!Y.empty())
        {
            if (Y.top().first == k.first ||
                (Y.top().first < k.first && Y.top().second % 2 == 0) ||
                (Y.top().first > k.first && k.second % 2 == 0)) {
                k.first = max(k.first, Y.top().first);
                k.second += Y.top().second;
                Y.pop();
            }else break;
        }
        Y.push(k);
    }

    if (Y.size() == 1) YES;
    NO;
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
