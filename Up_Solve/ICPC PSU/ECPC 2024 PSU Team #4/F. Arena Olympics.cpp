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


const int MODE = 1e9 + 7;

using namespace std;

const double PI = 3.1415926535897932384626433832795028841971;

void solve(int tc) {
    ll n;

    cin >> n;

    vi vie(n + 1);
    stack<ll> st;
    vi res;
    vii Y(n + 1);
    vii X(n + 1, vi(4));

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++)
            cin >> X[i][j];
    
    for (int i = 1; i <= n; i++)
    {
        ll l = (X[i][2] - X[i][3] + 360) % 360;
        ll r = (X[i][2] + X[i][3]) % 360;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            ll x = X[j][0] - X[i][0];
            ll y = X[j][1] - X[i][1];
            double ang;

            if (x == 0) ang = 90 + 180 * (y < 0);
            else if (y == 0) ang = 180 * (x < 0);
            else
            {
                ll a = abs(x), b = abs(y);
                ang = atan(b * 1.0 / a) * 180 / PI;
                
                if (x < 0 && y < 0) ang += 180;
                else if (x < 0) ang = 180 - ang;
                else if (y < 0) ang = 360 - ang;
            }
            
            if (ang >= l && ang <= r || (r < l && (ang <= r || ang >= l))) {
                Y[i].push_back(j);
                vie[j]++;
            }

        }
    }
    
    for (int i = 1; i <= n; i++)
        if (!vie[i]) st.push(i);
    
    while (!st.empty())
    {
        ll m = st.top();
        res.push_back(m);
        st.pop();

        for (auto neg : Y[m]) {
            vie[neg]--;
            if (!vie[neg]) st.push(neg);
        }
    }
    
    if (res.size() != n) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
