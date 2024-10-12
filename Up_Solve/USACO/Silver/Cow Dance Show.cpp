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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, mt;

    cin >> n >> mt;

    vi X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];

    ll l = 1, r = n;

    while (l < r)
    {
        ll mid = (l + r) / 2;

        multiset<ll> st;
        for (int i = 0; i < mid; i++)
            st.insert(X[i]);

        for (int i = mid; i < n; i++)
        {
            ll re = *st.begin() + X[i];
            st.erase(st.begin());
            st.insert(re);
        }
        
        ll time = *prev(st.end());
        if (time <= mt) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
