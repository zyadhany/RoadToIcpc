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

using namespace std;

void solve(int tc) {
    ll n, m, q, k;

    cin >> n >> m >> q;

    char X[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> X[i][j];
    
    while (q--)
    {
        cin >> k;


        for (int i = 0; i < k - 1; i++){
            char Y[100];
            for (int j = 0; j < n; j++)
                Y[(i + m - 1) % m] = X[j][i];
            for (int j = 0; j < n; j++)
                X[j][i] = Y[j];
        }

        for (int i = k; i < m; i++){
            char Y[100];
            for (int j = 0; j < n; j++)
                Y[(i + n + 1) % n] = X[j][i];
            for (int j = 0; j < n; j++)
                X[j][i] = Y[j];
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << X[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
