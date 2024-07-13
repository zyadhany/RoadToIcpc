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

string req(map<string, string> &X) {
    string res, s, t;
    res = "";

    s = X["author"] + ", ";
    ll at = 0;
    while (s.find(',') != string::npos)
    {
        ll re = s.find(',');
        t = s.substr(0, re);
        if (!res.empty()) res += ", ";
        res += t.substr(0, 2) + ". ";
        res += t[t.find(' ') + 1];
        s = s.substr(re + 2, -1);
    }
    res += ". " + X["title"];
    res += ". " + X["journal"];
    res += ". " + X["year"];
    res += ";" + X["volume"];
    res += "(" + X["number"] + ")";
    res += ":" + X["pages"] + ".";
    return (res);
}

void solve(int tc) {
    ll n;
    string s, t;
    cin >> n;


    while (n--)
    {
        cin >> t; cin.ignore();
        map<string, string> X;
        for (int i = 0; i < 8; i++)
        {
            getline(cin, s);
            t = "";
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == '=') {
                    string r = s.substr(j + 2, -1);
                    if (r.back() == ',') r.pop_back();
                    if (r.back() == '}') r.pop_back();
                    X[t] = r;
                    break;
                }
                t += s[j];
            }
        }
        cin >> t;
        cout << req(X) << '\n';
    }
    
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
