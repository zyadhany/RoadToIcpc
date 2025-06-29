#include "bits/stdc++.h"
#define ll long long
#define ld long double
#define vi vector<ll>
#define all(X) X.begin(), X.end()

using namespace std;

void solve() {
    ll n;

    cin >> n;

    vi X(n+1);
    vi P(n+1);

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        P[i] = X[i] + P[i-1];
    }
    
    stack<ll> st;
    ll sol = 0;

    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && P[i-1] - P[st.top()-1] < X[i]) st.pop();
        if (!st.empty()) sol += i - st.top();
        st.push(i);
    }
    
    cout << sol << '\n';
}

int main() {
    int t = 1;
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);


    // cin >> t;
    while (t--)
    {
        solve();
    }
    
}