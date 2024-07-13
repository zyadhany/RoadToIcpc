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
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    int n, sol;

    cin >> n;

    sol = n;
    vector<int> X(n), vis(n);
    vp L, R;

    for (int i = 0; i < n; i++)
        cin >> X[i];

    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;
        if (c == 'M') L.emplace_back(X[i], i);
        else R.emplace_back(X[i], i);
    }   
    sortx(L);
    sortx(R);
    for (auto &l : L) for (auto &r : R) 
        if (!vis[r.second] && __gcd(l.first, r.first) > 1) {
            vis[r.second] = 1, sol--;
            break;
        }

    cout << sol << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
