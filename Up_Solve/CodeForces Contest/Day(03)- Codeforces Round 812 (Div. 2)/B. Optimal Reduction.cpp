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
#define all(X) (X.begin(),X.end());
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;



/*
  we need to make f(a) minimum as possible.
  we can get it if the min value of array alway at edge.
  if we have {1, 4 ,5 , 3, 2}
  we have one at edge, then 2, 3 . 4 and so on.
  we can like keep poping min value from edges.
*/
void solve(int tc) {
    ll n, at,re, mn = 0;

    cin >> n;

    deque<ll> X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    while (!X.empty())
    {
        re = min(X.front(), X.back());
        if (re < mn) NO;

        if (X.front() <= X.back()) X.pop_front();
        else X.pop_back();

        mn = re;
    }

    YES;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}