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

const double PI = 3.141592653589793;

void solve(int tc) {
    ll n;
    string s;
    string t;

    cin >> n >> s;

    t = "";
    vi res(n + 1);
    stack<int> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9') {
            t += s[i];
            continue;
        }

        if (!t.empty()) {
            st.push(stoi(t));
            t = "";
        }

        if (s[i] == ')') {
            ll re = st.top();
            st.pop();
            res[re] = st.top();
        }
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';
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
