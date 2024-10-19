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
    ll n;

    cin >> n;

    vector<string> X(n);
    set<ll> st;
    
    for (int i = 0; i < n; i++)
        cin >> X[i];

    for (auto i : X)
        for (auto j : i)
            if (j != '0') st.insert(j);

    vi vis(255);
    vis['0'] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[X[i][j]]) continue;
            pl l, r;
            l = r = {i, j};
            
            for (ll a = 0; a < n; a++)
            {
                for (ll b = 0; b < n; b++)
                {
                    if (X[a][b] == X[i][j]) {
                        l.first = min(l.first, a);
                        l.second = min(l.second, b);
                        r.first = max(r.first, a);
                        r.second = max(r.second, b);
                    }
                }
            }

            for (int a = l.first; a <= r.first; a++)
            {
                for (int b = l.second; b <= r.second; b++)
                {
                    if (X[a][b] == X[i][j]) continue;
                    auto it = st.find(X[a][b]);
                    if (it != st.end()) st.erase(it);
                }
            }                        
            
            vis[X[i][j]] = 1;
        }
    }
    
    cout << st.size() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
