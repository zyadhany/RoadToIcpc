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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

const int MODE = 1e9 + 7;


void solve(ll tc) {
    ll n, q, l, r, summ, a;

    cin >> n >> q;

    summ = 1;
    vi X(n + 10);
    vi Y(n + 10);
    set<pl> st;
    Y[n + 1] = n + 1;

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        Y[X[i]] = i;
    }
    
    for (int i = 1; i <= n; i++)
        if(Y[i] > Y[i + 1]) st.insert({i, i + 1});

    while (q--)
    {
        cin >> l >> r;
        if (X[l] > X[r]) swap(l, r);
        swap(X[l], X[r]);
        a = l, l = X[r], r = X[a];

        if (st.find({l, l + 1}) != st.end()) st.erase({l, l + 1});
        if (st.find({l - 1, l}) != st.end()) st.erase({l - 1, l});
        if (st.find({r, r + 1}) != st.end()) st.erase({r, r + 1});
        if (st.find({r - 1, r}) != st.end()) st.erase({r - 1, r});

        swap(Y[l], Y[r]);

        if (Y[l] > Y[l + 1]) st.insert({l, l + 1});
        if (Y[l - 1] > Y[l]) st.insert({l - 1,l});
        if (Y[r] > Y[r + 1]) st.insert({r, r + 1});
        if (Y[r - 1] > Y[r]) st.insert({r - 1,r});

        cout << st.size() + 1 << '\n';
    }    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
