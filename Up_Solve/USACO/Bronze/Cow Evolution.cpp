#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

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

void solve(int tc) {
    ll n;

    cin >> n;

    vii X(n);
    map<string, int> Y;

    for (int i = 0; i < n; i++)
    {
        ll m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string s; cin >> s;
            if (Y.count(s) == 0) {
                Y[s] = Y.size();
            }
            X[i].push_back(Y[s]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        vii Z;
        set<ll> st;
        for (auto j : X[i]) st.insert(j);
        for (int j = 0; j < n; j++)
        {
            if(i == j) continue;
            set<ll> hav;
            set<ll> ned;
            for (auto h : X[j]) {
                if (st.count(h)) hav.insert(h);
                else ned.insert(h);
            }


            for (int h = 0; h < n; h++)
            {
                bool isit = 0;
                int cnt = 0;
                for (auto k : X[h]) {
                    cnt += hav.count(k);
                    if (ned.count(k)) isit = 1;
                }

                if (isit && cnt != hav.size()) {
                    cout << "no\n";
                    return;
                }
            }
        }
    }
    
    cout << "yes\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
