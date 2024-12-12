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

ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (gcd(b, a % b));
}

ll lcm(ll a, ll b) 
{ 
    return (a / gcd(a, b)) * b; 
}

void solve(int tc) {
    ll n;
    string s;

    cin >> n;
    cin >> s;

    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i]; X[i]--;
    }
    
    vi RE;
    vi vis(n);
    string t = s;
    for (int i = 0; i < n; i++)
    {
        if (vis[i]) continue;
        vi Z;

        ll at = i;
        while (!vis[at])
        {
            vis[at] = 1;
            Z.push_back(at);
            at = X[at];
        }
        
        ll cnt = 1;
        while (true)
        {
            bool isit = 1;

            char c = t[i];
            for (int j = 0; j < Z.size() - 1; j++)
                t[Z[j]] = t[Z[j + 1]];
            t[Z.back()] = c;            
            
            for (auto a : Z) {
                if (s[a] != t[a]) isit = 0;
            }

            if (isit) break;
            cnt++;
        }
        
        RE.push_back(cnt);
    }
    

    ll res = RE[0];
    for (auto a : RE) res = lcm(res, a);
    cout << res << '\n';
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
