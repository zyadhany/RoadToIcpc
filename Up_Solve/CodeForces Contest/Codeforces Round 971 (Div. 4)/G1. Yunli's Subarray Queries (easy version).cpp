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
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, k, q;

    cin >> n >> k >> q;

    vi X(n), res(n + 1);
    mi Z;
    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    ll at = 0;

    multiset<ll> st;
    for (int i = 0; i < n; i++)
        st.insert(0);
    
    for (int i = 0; i < n; i++)
    {
        st.erase(st.find(Z[X[i] - i]));
        Z[X[i] - i]++;
        st.insert(Z[X[i] - i]);
        if (i - at + 1 == k) {
            auto it = st.end(); it--;
            res[at + 1] = k - *it;
            
            st.erase(st.find(Z[X[at] - at]));
            Z[X[at] - at]--;
            st.insert(Z[X[at] - at]);
            at++;
        }
    }
    
    while (q--)
    {
        ll l, r; cin >> l >> r;
        cout << res[l] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("backforth.in", "r", stdin);
    //freopen("backforth.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
