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

const int MODE = 1e9 + 7;\

using namespace std;

void solve(int tc) {
    ll n;
    string s;

    cin >> n;

    map<string, int> X;

    cin >> s;

    if (s != "Header") {
        cout << "WA\n";
        return;
    }
n--;
    while (n-- > 1)
    {
        cin >> s;

        if (s.find("Header") != string::npos || s.find("ENDHeader") != string::npos) {
            cout << "WA\n";
            return;
        }


        if (s.find("End") != string::npos && s.substr(0, 3) == "End")
        {
            s = s.substr(3, -1);
            if (X[s]) X[s]--;
            else {
                cout << "WA\n";
                return;
            }
        }else X[s]++;
    }


    for (auto m : X){
        if (m.second) {
                cout << "WA\n";
                return;
            }
    }

    cin >> s;

    
    if (s != "EndHeader") {
        cout << "WA\n";
        return;
    }

    cout << "ACC\n";
}   

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
