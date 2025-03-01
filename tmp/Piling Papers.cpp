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


// l, r, a, b, stat
ll cr = 0;
int dp[2][300][300][20][20][4];

void reset() {
    for (int i = 0; i < 300; i++)
    for (int j = 0; j < 300; j++)
    for (int a = 0; a < 20; a++)
    for (int b = 0; b < 20; b++)
    for (int fl = 0; fl < 4; fl++)
        dp[cr][i][j][a][b][fl] = 0;
}

ll getstate(ll n, char c) {
    if (n < c-'0') return 0;
    else if (n == c-'0') return 1;
    return 2;
}

void sol(vi &X, string s) {
    reset();
    ll n = X.size();
    ll d = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        // range i, i. just one digit
        for (int l = 0; l < d; l++)
            dp[cr][i][i][l][l][getstate(X[i], s[l])] = 1;
        
        // range i -> j
        for (int j = i + 1; j < n; j++)
        {
            // check all l to r if extend left or right.
            for (int l = 0; l < d; l++)
            {
                for (int r = l; r < d; r++)
                {
                    ll a = dp[cr][i][j-1][l][r][0];
                    ll b = dp[cr][i][j-1][l][r][1];
                    ll c = dp[cr][i][j-1][l][r][2];
                    dp[cr][i][j][l][r][0] = (dp[cr][i][j][l][r][0] + a) % MODE;
                    dp[cr][i][j][l][r][1] = (dp[cr][i][j][l][r][1] + b) % MODE;
                    dp[cr][i][j][l][r][2] = (dp[cr][i][j][l][r][2] + c) % MODE;

                    // cout << i << ' ' << j << ' ' << a << ' ' << b << ' ' << c << "|\n"; 
                    // extend left
                    if(l) {
                        ll st = getstate(X[j], s[l-1]);
                        if (st == 0) {
                            dp[cr][i][j][l-1][r][0] = (dp[cr][i][j][l-1][r][0] +a + b + c) % MODE;
                        } else if (st == 1) {
                            dp[cr][i][j][l-1][r][0] = (dp[cr][i][j][l-1][r][0] + a) % MODE;
                            dp[cr][i][j][l-1][r][1] = (dp[cr][i][j][l-1][r][1] + b) % MODE;
                            dp[cr][i][j][l-1][r][2] = (dp[cr][i][j][l-1][r][2] + c) % MODE;
                        } else {
                            dp[cr][i][j][l-1][r][2] = (dp[cr][i][j][l-1][r][2] +a + b + c) % MODE;
                        }
                    }

                    // extend right
                   if (r < d - 1) {
                        ll st = getstate(X[j], s[r+1]);
                        if (st == 0) {
                            dp[cr][i][j][l][r+1][0] = (dp[cr][i][j][l][r+1][0]+a+b) % MODE;
                            dp[cr][i][j][l][r+1][2] = (dp[cr][i][j][l][r+1][2]+c) % MODE;
                        } else if (st == 1) {
                            dp[cr][i][j][l][r+1][0] = (dp[cr][i][j][l][r+1][0] + a) % MODE;
                            dp[cr][i][j][l][r+1][1] = (dp[cr][i][j][l][r+1][1] + b) % MODE;
                            dp[cr][i][j][l][r+1][2] = (dp[cr][i][j][l][r+1][2] + c) % MODE;
                        } else {
                            dp[cr][i][j][l][r+1][0] = (dp[cr][i][j][l][r+1][0]+a) % MODE;
                            dp[cr][i][j][l][r+1][2] = (dp[cr][i][j][l][r+1][2]+c+b) % MODE;
                        }
                   }
                }
            }
            
        }
    }
}

ll calc(ll l, ll r, ll d) {
    ll res = dp[cr][l][r][0][d-1][1];
    res += dp[cr][l][r][0][d-1][1];
    for (int j = 1; j < d; j++)
    {
        for (int h = 0; h < 3; h++)
        {
            res += dp[cr][l][r][j][d-1][h];
        }
        res %= MODE;
    }
    
    return res;
}

void solve(int tc) {
    ll n;
    string s, t;

    cin >> n;
    cin >> s >> t;

    vi X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];    

    sol(X, s);
    cr ^= 1;
    sol(X, t);
    cr ^= 1;

    ll q; cin >> q;
    while (q--)
    {
        ll l, r; cin >> l >> r;
        l--, r--;
        ll a = calc(l, r, s.size()) - dp[cr][l][r][0][s.size()-1][1];
        cr ^= 1;
        ll b = calc(l, r, t.size());
        cr ^= 1;
        ll res = b - a;
        res = (res%MODE+MODE)%MODE;
        cout << b << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
