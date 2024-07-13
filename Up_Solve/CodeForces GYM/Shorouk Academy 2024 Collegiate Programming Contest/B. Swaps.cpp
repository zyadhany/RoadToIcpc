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

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n;
    string s, t;

    cin >> s >> t;

    n = s.size();
    if (s.size() != t.size()) NO;

    vi L(255), R(255), VL(255, -1), VR(255, -1);

    for (int i = 0; i < n; i++)
        L[s[i]]++;
    for (int i = 0; i < n; i++)
        R[t[i]]++;

    for (int i = 0; i < n; i++) {
        if (VL[s[i]] != VR[t[i]]) NO;
        VL[s[i]] = VR[t[i]] = i;
        if (L[s[i]] != R[t[i]]) NO;
    }
    YES;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}