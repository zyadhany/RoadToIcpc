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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;
/*given n,m find how many pronablity to get uniq set of n peaple with values from 1 to m*/
void solve(int tc) {
    ll n, m, summ;

    cin >> n >> m;

    vi X(m, 1);

    while (n--)
    {
        for (int i = 0; i < m; i++)
        {
            summ = 0;
            for (int j = i; j < m; j++)
            {
                summ += X[j];
                summ %= MODE;
            }
            X[i] = summ;
        }
    }
    
    cout << X[0] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
