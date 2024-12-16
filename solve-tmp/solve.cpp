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

struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

pair<long, long> CRT(vector<long long> rem, vector<long long> num)
{   
    for (int i = 0; i < num.size(); i++)
        rem[i] = (rem[i] % num[i] + num[i]) % num[i];

    long long ans = rem[0];
    long long lc = num[0];

    for (int i = 1; i < num.size(); i++)
    {
        auto pom = ex_GCD(lc, num[i]);
        int x1 = pom.x;
        int d = pom.d;

        if ((rem[i] - ans) % d != 0)
            return {-1, -1};
    
        ans = ans + x1 * (rem[i] - ans) / d % (num[i] / d) * lc;
        lc =  lc * num[i] / d;
        ans = (ans % lc + lc) % lc;
    }

    return {ans, lc};    
}

void solve(int tc) {
    ll a, n, b, m;

    cin >> a >> n >> b >> m;

    vi rem = {a, b};
    vi num = {n, m};

    auto ans = CRT(rem, num);

    if (ans.first == -1)
        cout << "no solution" << ln;
    else cout << ans.first << " " << ans.second << ln;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
