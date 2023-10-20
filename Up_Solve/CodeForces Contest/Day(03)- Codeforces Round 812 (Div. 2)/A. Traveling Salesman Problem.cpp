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
#define all(X) (X.begin(),X.end());
#define ln '\n'

using namespace std;



/*
  get max value of each direction
  add it to summ.
  mult summ * 2 as to go and back.
*/
void solve(int tc) {
    ll n, summ, l, r, a, b, c, d;
    
    cin >> n;

    a = b = c = d = 0;

    while (n--)
    {
        cin >> l >> r;

        if (!l)
        {
            if (r < 0) a = max(a, -r);
            else b = max(b, r);
        }
        else
        {
            if (l < 0) c = max(c, -l);
            else d = max(d, l);
        }
    }

    summ = a + b + c + d;

    cout << summ * 2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
