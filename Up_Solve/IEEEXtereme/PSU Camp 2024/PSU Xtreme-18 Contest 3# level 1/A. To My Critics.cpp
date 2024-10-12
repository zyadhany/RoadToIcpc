#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) (X.begin(),X.end());
#define ln '\n'


const ll mode = 3 * 1e6;


using namespace std;


void FP()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}


void solve() {
    vi X(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> X[i];
    }
    sortx(X);
    if (X[2] + X[1] >= 10)
    {
        cout << "YES\n";
    }
    else cout << "NO\n";
}


int main()
{
    FP();
    int size = 1;

    cin >> size;
    while (size--)
    {
        solve();
    }
}