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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

const int MODE = 1e9 + 7;



void solve(ll tc) {
    ll n, k, summ;

    cin >> n;

    k = n * (n + 1) / 2;

    if (k % 2) NO;
    cout << "YES\n";
    k /= 2;
    
    summ = 0;
    vi L, R;
    for (int i = n; i >= 1; i--)
    {
        if (i + summ <= k) {
            summ += i;
            L.push_back(i);
        }else R.push_back(i);
    }
    

    cout << L.size() << '\n';
    for (int i = 0; i < L.size(); i++)
        cout << L[i] << ' ';
    cout << '\n';   

    cout << R.size() << '\n';
    for (int i = 0; i < R.size(); i++)
        cout << R[i] << ' ';
    cout << '\n';    
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
