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

const int MODE = 998244353;

using namespace std;

void solve(int tc) {
    ll n, l, r, summ, re;
    string s;

    cin >> s;

    n = s.size();
    summ = 0;
    deque<ll> L, R;

    l = r = 0;
    while (l < n && r < n)
    {
        r = max(r, l);
        if (s[l] != 'C') l++;
        else if (s[r] != 'A') r++;
        else swap(s[l], s[r]);
    }
    
    for (int i = 0; i < n; i++)
        if (s[i] == 'C') R.push_back(i);

    re = 0;
    for (int i = 0; i < n && !R.empty(); i++)
    {
        if (i == R.front()) R.pop_front();
        else if (s[i] == 'A') re++;
        else if (s[i] == 'B' && re) {
            re--;
            summ++;
            R.pop_front();
        }
    }

    cout << summ << '\n';
}

int main()
{
		ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int size = 1;

		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);

		//cin >> size;
		for (int i = 1; i <= size; i++)
				solve(i);
}