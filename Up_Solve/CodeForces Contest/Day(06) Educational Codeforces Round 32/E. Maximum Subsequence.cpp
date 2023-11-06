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
#define YES {cout << "Yes\n"; return;}
#define NO {cout << "No\n"; return;}

using namespace std;

void makeset(vi& X, ll m) {
    ll re;
    
    mi Y;
    set<ll> Z;
    Z.insert(0);

    for (int i = 0; i < X.size(); i++)
        for (auto& a : Z) {
            if (Y[a] == i + 1) continue;
            re = (a + X[i]) % m;
            if (!Y[re]) {
                Y[re] = i + 1;
                Z.insert(re);
            }            
        }

    X.clear();
    for (auto& a : Z) X.push_back(a);
}

void solve(int tc) {
    ll n, m, mx = 0, re;

    cin >> n >> m;

    vi L((n + 1) / 2), R(n / 2);

    for (int i = 0; i < (n + 1) / 2; i++)
        cin >> L[i];
    for (int i = 0; i < n / 2; i++)
        cin >> R[i];

    makeset(L, m);
    makeset(R, m);

    for (int i = 0; i < L.size(); i++)
    {
        re = lower_bound(all(R), m - L[i]) - R.begin();
        if (re) re--;
        mx = max(mx, (L[i] + R[re]) % m);
        mx = max(mx, (L[i] + R.back()) % m);
    }

    cout << mx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int size = 1;

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}