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

const int MODE = 998244353;

using namespace std;


void solve(int tc) {
    ll n, k;

    cin >> n;

    k = 0;
    vi X(n), Z;
    deque<pl> Y;

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        Y.push_back({ X[i], X[i] });
    }

    while (!Y.empty())
    {
        sortx(Y);

        k |= Y.back().second;
        cout << Y.back().second << ' ';
        Y.pop_back();
        
        while (!Y.empty() && Y.front().first == 0) {
            Z.push_back(Y.front().second);
            Y.pop_front();
        }

        for (int i = 0; i < Y.size(); i++)
        {
            for (int j = 0; j < 32; j++)
            {
                if ((k >> j) & 1) {
                    Y[i].first ^= (((Y[i].first >> j) & 1) << j);
                }
            }
        }
    }

    for (int i = 0; i < Z.size(); i++)
        cout << Z[i] << ' ';
    cout << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}