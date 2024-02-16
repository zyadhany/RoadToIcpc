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

struct node
{
    ll l;
    ll r;
};

void addNode(node* m, ll k) {
    if (m->l == k || m->r == k) return;
        
    if (!m->l) m->l = k;
    else m->r = k;
}

ll req(vector<node> &Y, vi& Z, ll n) {
    if (Z[n]) return (0);
    if (!n) return (1);
    
    Z[n] = 1;

    return (req(Y, Z, Y[n].l) | req(Y, Z, Y[n].r));
}

void solve(int tc) {
    ll n, mn , mx, re, k;

    cin >> n;

    mn = mx = re = k = 0;
    vi X(n + 1), Z(n + 1);
    vector<node> Y(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> X[i];

    for (int i = 1; i <= n; i++)
    {
        addNode(&Y[i], X[i]);
        addNode(&Y[X[i]], i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (Z[i]) continue;
        mx++;
        re = req(Y, Z, i);

        if (!re) mn++;
        else k = 1;
    }
    
    cout << mn + k << ' ' << mx << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}