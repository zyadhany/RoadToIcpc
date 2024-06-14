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
    ll n, summ, q, l, r;

    cin >> n >> q;

    summ = 1;
    vi X(n + 1);
    vi Y(n + 10);
    Y[n + 1] = n;
    Y[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        Y[X[i]] = i;
    }
    
    for (int i = 1; i < n; i++)
        if (Y[i] > Y[i + 1]) summ++;
        

    while (q--)
    {
        cin >> l >> r;
        swap(X[l], X[r]);
        l = X[r], l = X[l];
        
        summ -= Y[l] > Y[l + 1];
        summ -= Y[l] < Y[l - 1];
        summ -= Y[r] > Y[r + 1];
        summ -= Y[r] < Y[r - 1];
        swap(Y[l], Y[r]);
        summ += Y[l] < Y[l - 1];
        summ += Y[r] < Y[r - 1];
        summ += Y[l] > Y[l + 1];
        summ += Y[r] > Y[r + 1];
        
        cout << summ << '\n';
    }
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
