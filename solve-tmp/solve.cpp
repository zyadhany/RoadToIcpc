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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
using namespace std;
 
const int MODE = 1e9 + 7;

struct Query
{
    int L, R, ind;
};

void solve(ll tc) {
    ll n, q;

    cin >> n >> q;

    vi X(n + 10);
    vi Z(n + 10);
    vector<vp> Q(n + 10);
    vi res(q);

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        Z[i] = Z[i - 1] + X[i];
    }
    
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        Q[l].push_back({r, i});
    }
    
    vp st(1, {INT32_MAX, n + 1});
    vi pref(1, 0);
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && st.back().first <= X[i])
        {
            st.pop_back();
            pref.pop_back();
        }
        ll lst = st.back().second;
        ll cont = X[i] * (lst - i) - (Z[lst - 1] - Z[i - 1]);

        st.push_back({X[i], i});    
        pref.push_back(pref.back() + cont);
        
        for (auto m : Q[i]) {
            int ind = m.second;
            ll summ = 0;
            ll l, r, at;
            l = 0, r = st.size() - 1;
            while (l < r)
            {
                at = (l + r) / 2;
                if (st[at].second > m.first) l = at + 1;
                else r = at;
            }
            r = st[l].second;
            summ = pref.back() - pref[l];
            summ += (m.first - r + 1) * X[r] - (Z[m.first] - Z[r - 1]);
            
            res[ind] = summ;
        }
    }
    
    for (int i = 0; i < q; i++)
        cout << res[i] << '\n';
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
