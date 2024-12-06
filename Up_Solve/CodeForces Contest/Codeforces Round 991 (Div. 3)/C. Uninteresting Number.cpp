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

using namespace std;

const int MX = 1e5 + 1;

void solve(int tc) {
    ll n;

    string s;

    cin >>  s;

    ll summ = 0;
    for (int i = 0; i < s.size(); i++)
    {
        summ += s[i] - '0';
    }
    
    ll cnt2 = count(all(s), '2');
    ll cnt3 = count(all(s), '3');

    for (int i = 0; i <= min(9ll, cnt2); i++)

        for (int j = 0; j <= min(9ll, cnt3); j++)
            if ((summ + i * 2 + j * 6) % 9 == 0) YES;

    NO;
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
