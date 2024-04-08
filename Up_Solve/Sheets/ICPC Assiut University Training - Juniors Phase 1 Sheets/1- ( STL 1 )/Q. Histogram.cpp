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

const int MODE = 1e9 + 7;

using namespace std;

ll LargestHistogram(vi &arr)
{
    ll n = arr.size(), mx = 0, at;
    stack<pl> st;

    for (int i = 0; i < n; i++)
    {
        at = i;
        while (!st.empty() && st.top().first >= arr[i])
        {
            mx = max(mx, st.top().first * (i - st.top().second));
            at = st.top().second;
            st.pop();
        }
        st.push({arr[i], at});
    }
    
    while (!st.empty())
    {
        mx = max(mx, st.top().first * (n - st.top().second));
        st.pop();
    }

    return (mx);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    cout << LargestHistogram(X) << '\n';
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
