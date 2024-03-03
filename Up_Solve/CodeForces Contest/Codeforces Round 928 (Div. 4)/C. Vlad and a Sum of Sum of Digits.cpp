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
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

vi vec(2e5 + 10);

void solve(int tc) {
    ll n, summ = 0;

    cin >> n;

    cout << vec[n] << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 1; i <= 2e5; i++)
    {
        ll re = i;
        while (re)
        {
            vec[i] += re % 10;
            re /= 10;
        }
        vec[i] += vec[i - 1];
    }

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
