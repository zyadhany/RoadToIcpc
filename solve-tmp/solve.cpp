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
    #define mc map<char,int>
    #define sortx(X) sort(X.begin(),X.end());
    #define all(X) X.begin(),X.end()
    #define allr(X) X.rbegin(),X.rend()
    #define ln '\n'
    #define YES {cout << "YES\n"; return;}
    #define NO {cout << "NO\n"; return;}
    #define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

    void solve(int tc) {
        ll n;

    cin >> n;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    vi Z(512, INT32_MAX);
    Z[0] = -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < Z.size(); j++)
            if (Z[j] <= X[i]) Z[j ^ X[i]] = min(Z[j ^ X[i]], X[i]);

    vi sol;
    for (int i = 0; i < Z.size(); i++)
        if (Z[i] != INT32_MAX) sol.push_back(i);
    cout << sol.size() << '\n';
    for (auto a : sol) cout << a << ' ';
}

    int main()
    {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int size = 1;

        // freopen("cowjog.in", "r", stdin);
        // freopen("cowjog.out", "w", stdout);

        cin >> size;
        for (int i = 1; i <= size; i++)
            solve(i);
    }
