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


void solve(int tc) {
    ll n, k, re;
    char a;

    cin >> n;

    if (n == 2) {
        cout << "! 0 1" << endl;
        return;
    }

    k = 0;
    for (int i = 1; i < n; i++)
    {
        cout << "? " << k << " " << k << " " << i << " " << i << endl;
        cin >> a;

        if (a == '<') k = i;
    }

    vi X;
    X.push_back(0);

    for (int i = (k == 0); i < n; i++)
    {
        if (i == k) continue;

        cout << "? " << k << " " << X.back() << " " << k << " " << i << endl;
        cin >> a;

        if (a == '<') {
            X.clear();
            X.push_back(i);
        }
        else if (a == '=') {
            X.push_back(i);
        }
    }

    re = 0;
    for (int i = 1; i < X.size(); i++)
    {
        cout << "? " << X[re] << " " << X[re] << " " << X[i] << " " << X[i] << endl;
        cin >> a;

        if (a == '>') re = i;
    }

    cout << "! " << k << ' ' << X[re] << endl;
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}