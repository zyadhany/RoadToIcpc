#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll a, b, c;

    cin >> a >> b >> c;

    ll h = 0;

    if (c != a + 1) {
        cout << "-1\n";
        return;
    }

    if (a) {
        h = log2(a) + 1;
        ll pw = pow(2, h);
        ll cnt = pw - 1 - a;

        if (b >= cnt) {
            b -= cnt;
            h += (b + a) / (a + 1);
            cnt = b % (a + 1);
        }
        else cnt -= b;

        if (c > cnt) {
            c -= cnt;
            h += (c + a) / (a + 1);
            cnt = c % (a + 1);
        }

    } else h = b + c;

    cout << h - 1 << '\n';  
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
