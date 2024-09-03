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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void req(set<pl> &st, vi &X, vi &Y, ll l, ll r, ll dy) {
    if (!dy) {
        st.insert({l, r});
        return;
    }

    for (int i = 0; i < X.size(); i++)
    {
        ll re = X[i];
        l -= re;
        r += re;
        X.erase(X.begin() + i);
        Y.push_back(re);

        req(st, Y, X, r, l, dy - 1);

        Y.pop_back();
        X.insert(X.begin() + i, re);
        l += re;
        r -= re;
    }
}

void solve(int tc) {
    vi X(10), Y(10);
    
    ll l, r;
    l = r = 0;
    set<pl> st;

    for (int i = 0; i < 10; i++) {
        cin >> X[i];
        l += X[i];
    }

    for (int i = 0; i < 10; i++) {
        cin >> Y[i];
        r += Y[i];
    }

    req(st, X, Y, l, r, 4);
    cout << st.size();
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
