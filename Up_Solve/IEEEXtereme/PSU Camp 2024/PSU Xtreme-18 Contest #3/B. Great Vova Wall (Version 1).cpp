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


void solve(int tc) {
    ll n;

    cin >> n;
    
    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    stack<pl> st;
    st.push({X[0] % 2, 1});
    for (int i = 1; i < n; i++)
    {
        ll at = X[i] % 2;

        if (at == st.top().first) st.top().second ^= 1;
        else st.push({at, 1});
        
        pl tmp = st.top();
        st.pop();

        while (!st.empty())
        {
            if (st.top().second == 0 || st.top().first == tmp.first) {
                tmp.first += st.top().second;
                st.pop();
            } else if (tmp.second == 0) {
                tmp.first = st.top().first;
                tmp.second += st.top().second;
                st.pop();
            } else break;
        }

        st.push(tmp);
    }
        
    if (st.size() == 1) YES;
    NO;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("backforth.in", "r", stdin);
    //freopen("backforth.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
