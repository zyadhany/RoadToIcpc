#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
 
const int MODE = 1e9 + 7;
const int TWO_MOD_INV = 500000004;
 
using namespace std;
 
const int MXN = 2e5 + 1;
 
long long total_sum(long long start, long long end) {
	return ((((end - start + 1) % MODE) * ((start + end) % MODE) % MODE) * TWO_MOD_INV %
	        MODE);
}
 
void solve(int tc) {
    ll n;
 
    cin >> n;
 
    ll summ = 0;
    ll at = 1;
    while (at <= n)
    {
        ll d = n / at;
        ll ls = n / d;
        summ += (total_sum(at, ls) * d) % MODE;
        summ %= MODE;
        at = ls + 1;
    }
 
    cout << summ << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}