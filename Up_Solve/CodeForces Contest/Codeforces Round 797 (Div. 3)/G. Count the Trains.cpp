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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vi X(n + 1);

    for (int i = 0; i < n; i++)
        cin >> X[i + 1];

    set<ll> st;
    st.insert(0); X[0] = INT32_MAX;
    ll mn = INT32_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (X[i] < mn) {
            mn = X[i];
            st.insert(i);
        }
    }

    while (q--)
    {
        ll ind, k; cin >> ind >> k;

        X[ind] -= k;
        auto it = st.upper_bound(ind);
        it--;
        if (*it != ind) {
            if (X[*it] > X[ind]) {
                st.insert(ind);
                it++;
            } else {
                cout << st.size() - 1 << ' ';
                continue;
            }
        }

        it++;
        while (it != st.end())
        {
            auto tt = it;
            it++;
            if (X[*tt] >= X[ind]) st.erase(tt);
            else break;
        }

        cout << st.size() - 1 << ' ';
    }

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("sabotage.in", "r", stdin);
    // freopen("sabotage.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
