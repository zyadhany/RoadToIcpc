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
    ll n;

    cin >> n;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    sort(X.begin(), X.end());    

    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        ll l, r, at, ran;

        ran = 0;        
        at = r = i;
        while (r < n && X[r] - X[at] <= ran)
        {
            while (r < n && X[r] - X[at] <= ran)
                r++;
            ran++; at = r - 1;
        }

        ran = 0;
        at = l = i;
        while (l >= 0 && X[at] - X[l] <= ran)
        {
            while (l >= 0 && X[at] - X[l] <= ran)
                l--;
            ran++; at = l + 1;
        }

        mx = max(mx, r - l - 1);
    }
    
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
