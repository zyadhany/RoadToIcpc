#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>
 
#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;

const int MODE = 1e9+7;

ll dp[300][18][18][3] = {0};

void reset(){
    for (int i2 = 0; i2 < 300; i2++)
        for (int i3 = 0; i3 < 18; i3++)
            for (int i4 = 0; i4 < 18; i4++)
                for (int i5 = 0; i5 < 3; i5++)
                    dp[i2][i3][i4][i5] = 0;    
}

ll comp(char a, char b) {
    if (a > b) return 0;
    if (a == b) return 1;
    return 2;
}

vii req(vc &X, ll A) {
    ll n = X.size();
    string s = to_string(A);
    vii res(n, vi(n));
    
    for (int i = 0; i < n; i++)
    {
        reset();
        for (int j = i; j < n; j++)
        {
            for (int l = s.size() - 1; l >= 0; l--)
            {
                dp[j][l][l][comp(X[j], s[l])]+=2;
                if(j==i) continue;
                
                for (int t = 0; t < 3; t++)
                {
                    dp[j][l][l][t] += dp[j-1][l][l][t];
                    dp[j][l][l][t] %= MODE;
                }

                for (int r = l+1; r < s.size(); r++)
                {
                    for (int t = 0; t < 3; t++) dp[j][l][r][t] = dp[j-1][l][r][t];
    
                    ll t = comp(X[j], s[r]);

                    dp[j][l][r][0] += (dp[j-1][l][r-1][0]);
                    dp[j][l][r][0] %= MODE;
                    dp[j][l][r][2] += (dp[j-1][l][r-1][2]);
                    dp[j][l][r][2] %= MODE;
                    if (t == 0) {
                        dp[j][l][r][0] += (dp[j-1][l][r-1][1]);
                        dp[j][l][r][0] %= MODE;
                    } else if (t == 1) {
                        dp[j][l][r][1] += (dp[j-1][l][r-1][1]);
                        dp[j][l][r][1] %= MODE;
                    } else {
                        dp[j][l][r][2] += (dp[j-1][l][r-1][1]);
                        dp[j][l][r][2] %= MODE;
                    }

                    t = comp(X[j], s[l]);
                    
                    if (t == 0) {
                        dp[j][l][r][0] += (dp[j-1][l+1][r][0] + dp[j-1][l+1][r][1] + dp[j-1][l+1][r][2]);
                        dp[j][l][r][0] %= MODE;
                    } else if (t == 1) {
                        dp[j][l][r][1] += (dp[j-1][l+1][r][1]);
                        dp[j][l][r][1] %= MODE;
                        dp[j][l][r][0] += (dp[j-1][l+1][r][0]);
                        dp[j][l][r][0] %= MODE;
                        dp[j][l][r][2] += (dp[j-1][l+1][r][2]);
                        dp[j][l][r][2] %= MODE;
                    } else {
                        dp[j][l][r][2] += (dp[j-1][l+1][r][0] + dp[j-1][l+1][r][1] + dp[j-1][l+1][r][2]);
                        dp[j][l][r][2] %= MODE;
                    }                    
                }
            }

            for (int l = 0; l < s.size(); l++)
            {
                for (int t = 0; t < 3; t++)
                {
                    res[i][j] += dp[j][l][s.size()-1][t];
                    res[i][j] %= MODE;
                }
            }
            res[i][j] -= dp[j][0][s.size()-1][0];
            res[i][j] = (res[i][j]%MODE + MODE)%MODE;
        }        
    }
    
    return res;
}

void solve(ll tc) {
    ll n, A, B;

    cin >> n >> A >> B;
    A--;

    vc X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }

    auto dp1 = req(X, A);
    auto dp2 = req(X, B);    

    ll q; cin >> q;
    while (q--)
    {
        ll l, r; cin >> l >> r; l--, r--;
        ll res = (dp2[l][r] - dp1[l][r] + MODE) % MODE;
        cout << res << '\n';
    }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   

    // freopen("subrev.in", "r", stdin   );
    // freopen("subrev.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
