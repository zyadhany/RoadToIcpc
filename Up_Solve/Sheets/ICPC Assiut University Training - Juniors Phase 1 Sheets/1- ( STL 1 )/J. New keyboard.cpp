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
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(string s) {
    ll re = 0;
    string t;


    deque<char> X;
    mc M;
    M[']'] = 1;
    M['['] = 2;

    for (int i = 0; i < s.size(); i++)
    {
        if (M[s[i]]) {
            if (re == 1) {
                for (int j = 0; j < t.size(); j++)
                    X.push_back(t[j]);
            }else {
                for (int j = t.size() - 1; j >= 0; j--)
                    X.push_front(t[j]);
            }  
            
            re = M[s[i]];
            t = "";
        } 
        else t += s[i];
    }
    if (re == 1) {
        for (int j = 0; j < t.size(); j++)
            X.push_back(t[j]);
    }else {
        for (int j = t.size() - 1; j >= 0; j--)
            X.push_front(t[j]);
    }  
    for (auto m : X)
        cout << m;
    cout << '\n';
}   

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    string s;
    while (cin >> s)
    {
        solve(s);
    }
}
