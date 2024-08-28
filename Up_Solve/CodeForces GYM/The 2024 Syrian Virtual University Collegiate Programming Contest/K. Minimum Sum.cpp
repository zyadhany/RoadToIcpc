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

const int MODE = 998244353;

using namespace std;

bool com(pair<string, ll> &a, pair<string, ll> &b) {
    if (a.first.size() != b.first.size()) 
        return a.first.size() < b.first.size();
    return a.first < b.first;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vector<pair<string, ll>> X(n);

    for (int i = 0; i < n; i++) {
        cin >> X[i].first;
        X[i].second = i;
    }
    sort(X.begin(), X.end(), com);

    string s;
    if (X[0].second) s = X[0].first;
    else s = X[1].first;
    
    ll summ = 0;
    for (int i = 0; i < n; i++)
    {
        summ *= 10;
        summ += s[i] - '0';
        summ %= MODE;
    }
    summ = (summ * n) % MODE;
    cout << summ << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
