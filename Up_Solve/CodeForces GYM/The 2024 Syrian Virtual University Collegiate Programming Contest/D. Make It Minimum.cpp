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
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

ll summtion(string &s) {
    ll summ = 0;

    for (int i = 0; i < s.size() - 1; i++)
        summ += stoi(s.substr(i, 2));

    return (summ);
}

void solve(int tc) {
    ll n;
    string s, t;

    cin >> n >> s;
    t = s;
    sortx(t);

    if (n == 1) {
        cout << 0 << ' ' << 0 << '\n';
        return;
    }

    ll sol = 0;

    if (s.back() != t.back()) {
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == t.back()) {
                swap(s[i], s[n - 1]);
                break;
            }
        }
        sol++;
    }


    if (s[0] != t[n - 2]) {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == t[n - 2]) {
                swap(s[i], s[0]);
                break;
            }
        }
        sol++;
    }

    cout << sol << ' ' << summtion(s) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
