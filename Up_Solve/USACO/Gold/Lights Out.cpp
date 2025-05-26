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
using namespace std;

const int MODE = 1e9+7;
const int p = 31;

void solve(int tc) {
    ll n;

    cin >> n;

    vp X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first >> X[i].second;
    }

    ll m = 0;
    vi dis(n);
    ll summ = 0;
    vector<string> Y(n);
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = X[i];
        auto [nx, ny] = X[(i+1)%n];
        auto [px, py] = X[(i+n-1)%n];
        
        if (x == px) {
            ll degree;
            if (y > py && nx > x) degree = 90;
            else if (y < py && nx > x) degree = 270;
            else if (y > py && nx < x) degree = 270;
            else degree = 90; 
            Y[i] += '$' + to_string(degree) + '$';
            dis[i] = abs(y-py);
        } else {
            ll degree;
            if (x > px && ny > y) degree = 270;
            else if (x < px && ny > y) degree = 90;
            else if (x > px && ny < y) degree = 90;
            else degree = 270;
            Y[i] += '$' + to_string(degree) + '$';
            dis[i] = abs(x-px);
        }
    }


    vi dp(n), prf(dis);
    prf.push_back(dis[0]);
    prf[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prf[i] += prf[i-1];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i] = min(prf[i], prf[n]-prf[i]);
    }
    dp[0] = 0;

    
    map<string, ll> HS;
    for (int i = 1; i < n; i++)
    {
        string t = "";
        for (int j = 1; j <= n-1; j++)
        {
			ll at = (i+j)%n;
            if (at == 0) break;
            t += Y[(at-1+n)%n];
            HS[t]++;
			t += to_string(dis[at]);
			HS[t]++;
        }
    }
    
    ll mx = 0;
    for (int i = 1; i < n; i++)
    {
        string t = "";
        ll d = 0;
        for (int j = 1; j <= n-1; j++)
        {
            ll at = (i+j)%n;
            t += Y[(at-1+n)%n];
			
			bool found = (at == 0);
			
			if (!found) {
				if (HS[t] == 1) {
					at = (at-1+n)%n;
					found = true;
				} else {
					d += dis[at];
					t += to_string(dis[at]);
					if (HS[t] == 1) found = 1;
				}
			}

			if (found) {
                mx = max(mx, d + dp[at] - dp[i]);
                break;
            }
        }
    }

    cout << mx << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
