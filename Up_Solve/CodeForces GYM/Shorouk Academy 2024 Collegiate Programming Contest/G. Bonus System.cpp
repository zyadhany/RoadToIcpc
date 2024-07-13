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


void solve(int tc) {
    ll n;
    string pass;

    cin >> n >> pass;

    vector<pair<pl, string>> X(n);
    vi Z(n);

    for (int i = 0; i < n; i++) {
        cin >> X[i].second;
        X[i].first.second = i + 1;
    }
   
    ll q; cin >> q;
    while (q--)
    {
        string opp; cin >> opp;

        if (opp == "scoreboard")  {
            sortx(X);
            ll at = 1;
            for (int i = 0; i < n; i++)
            {
                if (i && X[i].first.first != X[i - 1].first.first) at++;
                if (!X[i].first.first) break;
                cout << at << ' ' << X[i].first.second << ' ' << X[i].second << ' ' << -X[i].first.first << '\n';
            }
        } else
        {
            ll id, k;
            string s;
            cin >> id >> k >> s;
            if (s != pass) cout << "Wrong password please try again\n";
            else
            {
                cout << "Updated successfully\n";
                for (int i = 0; i < n; i++)
                    if (X[i].first.second == id) X[i].first.first -= k;                
            }
            
        }

        cout << "---\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
