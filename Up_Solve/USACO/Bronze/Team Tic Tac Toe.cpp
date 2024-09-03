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

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    vector<string> X(3);

    cin >> X[0] >> X[1] >> X[2];

    mc Y;
    for (auto a : X) for (auto b : a) Y[b] = 1;

    ll o = 0, e = 0;
    for (char a = 'A'; a <= 'Z'; a++)
    {
        if (!Y[a]) continue;
        for (char b = a; b <= 'Z'; b++)
        {
            if (!Y[b]) continue;
            bool isit = 0;

            for (int i = 0; i < 3; i++)
            {
                ll re = 1;
                ll l = 0, r = 0;
                for (int j = 0; j < 3; j++)
                {
                    l += (X[i][j] == a);
                    r += (X[i][j] == b);
                    if (X[i][j] != a && X[i][j] != b) re = 0;
                }
                if (!l || !r) re = 0;
                isit |= re;
            }

            for (int i = 0; i < 3; i++)
            {
                ll re = 1;
                ll l = 0, r = 0;
                for (int j = 0; j < 3; j++)
                {
                    l += (X[j][i] == a);
                    r += (X[j][i] == b);
                    if (X[j][i] != a && X[j][i] != b) re = 0;
                }
                if (!l || !r) re = 0;
                isit |= re;
            }
            
            ll re = 1;
            ll l = 0, r = 0;
            for (int i = 0; i < 3; i++)
            {
                l += (X[i][i] == a);
                r += (X[i][i] == b);
                if (X[i][i] != a && X[i][i] != b) re = 0;
            }
            if (!l || !r) re = 0;
            isit |= re;            

            re = 1;
            l = r = 0;
            for (int i = 0; i < 3; i++)
            {
                l += (X[2 - i][i] == a);
                r += (X[2 - i][i] == b);
                if (X[2 - i][i] != a && X[2 - i][i] != b) re = 0;
            }
            if (!l || !r) re = 0;
            isit |= re;            

            if (a == b) o += isit;
            else if (isit) e += isit;
        }
    }
    
    cout << o << '\n' << e << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
