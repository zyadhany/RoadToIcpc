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

bool isGood(string& s) {
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1]) return (0);
    return (1);
}

void solve(int tc) {
    ll n, at = 0, k = 300;
    string s;

    cin >> n >> s;
    
    vi Z;
    deque<char> X;

    for (int i = 0; i < n; i++)
        X.push_back(s[i]);

    while (!X.empty())
    {
        if (X.front() != X.back()) {
            at++;
            X.pop_back();
            X.pop_front();
            continue;
        }

        if (!k) {
            cout << "-1\n";
            return;
        }

        if (X.front() == '1') {
            X.push_front('1');
            X.push_front('0');
            Z.push_back(at);
        }
        else
        {
            X.push_back('0');
            X.push_back('1');
            Z.push_back(at + X.size() - 2);
        }

        k--;
    }

    cout << Z.size() << '\n';
    for (int i = 0; i < Z.size(); i++)
        cout << Z[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
