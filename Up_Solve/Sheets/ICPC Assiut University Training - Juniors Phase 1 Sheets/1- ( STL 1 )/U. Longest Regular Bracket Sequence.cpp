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
#define YES {cout << "Valid\n"; return;}
#define NO {cout << "Invalid\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;



void solve(int tc) {
    ll n, mx, l, re;
    string s;

    cin >> s;

    n = s.size();

    vi Z(n);
    mc X;
    stack<pair<char, int>> st;

    X['['] =  1;
    X[']'] = -1;
    X['{'] = 2;
    X['}'] = -2;
    X['('] = 3;
    X[')'] = -3;
    X['<'] = 4;
    X['>'] = -4;

    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty() && X[s[i]] < 0 && X[s[i]] == -X[st.top().first]){
            Z[i] = 1;
            Z[st.top().second] = 1;
            st.pop();
        }else if (X[s[i]] > 0){
            st.push({s[i], i});
        }else {
            while (!st.empty())
                st.pop();
        }
    }

    mx = 0, re = 0, l = 1;

    for (int i = 0; i < n; i++)
    {
        re++;
        if (!Z[i]) re = 0;
        else if (re == mx) l++;
        else if (re > mx) mx = re, l = 1;
    }
    
    cout << mx << ' ' << l << '\n';    
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
