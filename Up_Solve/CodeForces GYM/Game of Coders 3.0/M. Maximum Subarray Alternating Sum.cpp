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

    cin >> n;

    vi Z(n + 1);
    multiset<ll> st;
    st.insert(0);

    for (int i = 1; i <= n; i++)
    {
        cin >> Z[i];
        if (i % 2) Z[i] *= -1;
        Z[i] += Z[i - 1];
        st.insert(Z[i]);
    }
    
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        st.erase(st.find(Z[i]));

        auto it = st.end();
        it--;
        ll re = *it;
        
        
        mx = max(mx, abs(Z[i] - *st.begin()));
        mx = max(mx, abs(Z[i] - re));
    }
    
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
