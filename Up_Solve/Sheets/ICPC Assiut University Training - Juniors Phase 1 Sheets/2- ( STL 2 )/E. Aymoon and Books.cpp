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
    ll n, q, mx;
    char a;

    cin >> n;

    mx = -1;
    deque<ll> X(n);
    priority_queue<ll> Y;

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    cin >> q;

    while (q--)
    {
        cin >> a;

        if (a == 'L' && !X.empty()) {
            Y.push(X.front());
            X.pop_front();
        } else if (a == 'R' && !X.empty()) {
            Y.push(X.back());
            X.pop_back();
        } else if (a == 'Q') {
            if (Y.empty()) cout << "-1\n";
            else {
                cout << Y.top() << '\n';
                Y.pop();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
