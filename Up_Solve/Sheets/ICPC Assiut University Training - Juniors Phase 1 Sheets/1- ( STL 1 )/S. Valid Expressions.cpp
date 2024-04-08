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
#define YES {cout << "Valid\n"; return;}
#define NO {cout << "Invalid\n"; return;}

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
    ll num, zer, div, opp, mun;
    string s;

    cin >> s;

    num = zer = div = opp = mun = 0;
    mc X;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0') zer++;
        else if (s[i] == '/') div++;
        else if (s[i] > '0') num++;
        else opp++;
        if (s[i] == '-') mun = 1;
    }
    
    if (num + zer == div + opp){
        if (mun && num) mun = 2;
        else NO;
        opp--;
    }

    if (num + zer != div + opp + 1) NO;
    if (num - (mun == 2) < div) NO; 

    YES;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
