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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n;

    cin >> n;

    vp X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i].first >> X[i].second;

    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                vp Y = {X[i], X[j], X[k]};
                sortx(Y);
                do
                {
                    if (Y[0].first == Y[1].first && Y[1].second == Y[2].second) {
                        ll re = abs(Y[1].second - Y[0].second) * abs(Y[2].first - Y[1].first);
                        mx = max(mx, re);
                    }                    
                } while (next_permutation(all(Y)));
            }
        }
    }
    
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
