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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii X(m + 1, vi(n + 1));
    vii Z(n + 1, vi(n + 1));
    map<int, mi> Y;
    map<int, mi> M;

    /*
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            Y[i][j] = 1;    
    */

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> X[i][j];
    //cout << "|" << endl;
            Z[i][j] = X[i][j];
            Y[X[i][j]][j] = 1;
        }
    }
    
    /*
    for (int i = 1; i <= n; i++)
    {
        for (auto a : Y[i]) {
            for (int j = m + 1; j <= n; j++)
                if (!Z[j][a.first] && M[i][j] == 0) {
                    Z[j][a.first] = i;
                    M[i][j] = 1;
                    break;
                }
            
        }
    }
    */


    for (int i = m + 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i % 2) {

            for (int h = 1; h <= n; h++)
            {
                if (Y[h][j] || M[h][i]) continue;
                Z[i][j] = h;
                Y[h][j] = M[h][i] = 1;
                break;
            }
            } else {
                for (int h = n; h >= 1; h--)
                {
                    if (Y[h][j] || M[h][i]) continue;
                    Z[i][j] = h;
                    Y[h][j] = M[h][i] = 1;
                    break;
                }
            }
            
        }
        /*
        for (auto a : Y[i]) {
            for (int j = m + 1; j <= n; j++)
                if (!Z[j][a.first] && M[i][j] == 0) {
                    Z[j][a.first] = i;
                    M[i][j] = 1;
                    break;
                }
            
        }
        */
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << Z[i][j] << ' ';
        cout << '\n';        
    }
}

int main()
{
		ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int size = 1;

		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);

		//cin >> size;
		for (int i = 1; i <= size; i++)
				solve(i);
}