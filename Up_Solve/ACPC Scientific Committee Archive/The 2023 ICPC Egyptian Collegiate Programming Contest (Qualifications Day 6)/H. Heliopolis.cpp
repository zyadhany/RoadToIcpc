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

const int MODE = 998244353;

using namespace std;

void solve(int tc) {
    ll n, q;
    string s;

    cin >> n >> q;
    cin >> s;

    vi Y(255);    
    vi Z(n + 1, 1);

    for (auto a : s) Y[a]++;

    for (int freq = 1; freq <= n; freq++)
    {
        if (n % freq) {
            Z[freq] = 0;
            continue;
        }
        vi X(255);
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (Y[i] % freq) Z[freq] = 0;
            X[i] = Y[i] / freq;
        }
        if (!Z[freq]) continue;

        vector<set<int>> M(255);
        vii K(freq, vi(1, -1));
        vi vis(n);

        for (int i = 0; i < n; i++)
            M[s[i]].insert(i);

        for (int i = 0; i < n && Z[freq]; i++)
        {
            if (vis[i]) continue;
            for (int j = 0; j < freq; j++)
            {
                ll re = K[j].back();
                auto it = M[s[i]].insert(re).first;
                it++;
                if (it == M[s[i]].end()) {
                    Z[freq] = 0;
                    break;
                }
                K[j].push_back(*it);
                vis[*it] = 1;
                M[s[i]].erase(it);
                M[s[i]].erase(re);
            }
        }
    }
    

    while (q--)
    {
        ll a;
        cin >> a;

        if (n % a == 0 && Z[n / a]) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++)
            solve(i);
}
