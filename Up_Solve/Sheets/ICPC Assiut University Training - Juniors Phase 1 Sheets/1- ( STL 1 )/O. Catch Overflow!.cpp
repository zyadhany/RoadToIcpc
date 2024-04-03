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

ll getInd(vp& X, ll k) {
    ll re;
    pl m = { k, INT32_MAX };
    re = upper_bound(all(X), m) - X.begin() - 1;
    if (re < 0 || k > X[re].second) return (-1);
    return (re);
}

void solve(int tc) {
    ll n, k, summ, mul, mx, re;
    string s;
    bool over;

    cin >> n;

    summ = re = over = 0;
    mul = 1;
    mx = 1;
    mx <<= 32;

    stack<ll> X;

    while (n--)
    {
        cin >> s;

        if (s == "for")
        {
            cin >> k;
            
            if (!over) {
                mul *= k;
                X.push(k);
            }
            else re++;
            if (mul >= mx && !over) X.push(-1), over = 1;
        }
        else if (s == "end")
        {
            if (re) {
                re--;
                continue;
            }
            if (X.top() == -1) over = 0, X.pop();
            mul /= X.top();
            X.pop();
        }
        else
        {
            summ += mul;
            if (over || summ >= mx) {
                cout << "OVERFLOW!!!\n";
                return;
            }
        }
    }


    cout << summ << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
