#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
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



void solve(int tc) {
    ll n, m = 20;

    cin >> n;

    vi X(n);
    vi frq(1<<m);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        frq[X[i]]++;
    }
    
    // sand[i]: count of element y such that (i&y)=y (ie. i|y=i).
    vector<int> sor(all(frq));
    for (int i = 0; i < m; i++) {
        for (int x = 0; x < (1 << m); x++) {
            if (x & (1 << i)) { sor[x] += sor[x ^ (1 << i)]; }
        }
    }

    vector<int> sand(all(frq));
    for (int i = m-1; i >= 0; i--) {
        for (int x = (1 << m)-1; x > 0; x--) {
            if ((x & (1 << i))==0) { sand[x] += sand[x ^ (1 << i)]; }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << sor[X[i]] << ' ' << sand[X[i]] << ' ' << n - sor[((1<<m)-1)^X[i]]<< '\n';
    }    
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
  
    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
