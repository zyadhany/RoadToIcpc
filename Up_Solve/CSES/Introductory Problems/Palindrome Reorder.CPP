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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

const int MODE = 1e9 + 7;

void solve(ll tc) {
    string s, l, r;

    cin >> s;

    char a = '\0';
    l = r = "";

    vi X(26);

    for (int i = 0; i < s.size(); i++)
        X[s[i] - 'A']++;
    
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < X[i] / 2; j++)
        {
            l += i + 'A';
            r += i + 'A';
        }
        if (X[i] % 2){
            if (a) {
                cout << "NO SOLUTION\n";
                return;
            }
            a = i + 'A';
        }
    }
    
    if (a) l += a;
    reverse(all(r));
    cout << l + r << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
