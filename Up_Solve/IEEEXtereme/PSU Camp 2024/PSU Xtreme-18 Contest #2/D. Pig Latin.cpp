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

vector<string> parseString(string &s) {
    vector<string> X;
    string t = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') {
            X.push_back(t);
            t = "";
        }
        else t += s[i];
    }
    if (!t.empty()) X.push_back(t);
    return (X);
}

void solve(int tc) {
    string s;

    getline(cin, s);

    vector<string> X = parseString(s);

    for (int i = 0; i < X.size(); i++)
    {
        if (i) cout << ' ';
        string t = X[i].substr(1, -1);
        t += X[i][0];
        if (isupper(t.back())) {
            t.back() = tolower(t.back());
            t[0] = toupper(t[0]);
        }
        cout << t << "ay";
    }
    
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    cin.ignore();
    for (int i = 1; i <= size; i++) solve(i);
}
