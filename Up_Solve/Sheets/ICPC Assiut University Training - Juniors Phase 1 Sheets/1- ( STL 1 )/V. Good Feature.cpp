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
    ll n, re, summ;
    string s;

    cin >> s;

    vi X;
    stack<ll> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{'){
            st.push(1);
            if (st.size() > X.size()) X.push_back(1);
        } 
        else if (s[i] == ',') st.top()++;
        else if (s[i] == '}'){
            X[st.size() - 1] = max(X[st.size() - 1], st.top());
            st.pop();
        }
    }
    
    for (int i = 0; i < X.size(); i++)
        cout << '[' << X[i] << ']';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
