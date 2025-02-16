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


    #include <ext/pb_ds/assoc_container.hpp> 
    #include <ext/pb_ds/tree_policy.hpp> 
    using namespace __gnu_pbds; 

    // macros to define set 
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


    const int MODE = 998244353;
    using namespace std;

    const int MXN = 1e4;

    vii getgrav(ll n, vi &X, vi &Y) {
        vii Z(n, vi(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < X[i]; j++)
            {
                Z[i][j] = Y[i];
            }
        }

        // down grav
        for (int j = 0; j < n; j++)
        {
            for (int i = n-1; i >= 0; i--)
            {
                ll at = i;
                if (Z[i][j] == 0) continue;
                while (at < n - 1 && Z[at+1][j] == 0) {
                    swap(Z[at][j], Z[at+1][j]);
                    at++;
                }
            }
        }

        return Z;
    }

    ll req(ll n, vi &X, vi &Y) {
        vii Z = getgrav(n, X, Y);

        vi perm(n);
        for (int i = 0; i < n; i++)
        {
            perm[i] = i + 1;
        }

        ll cnt = 0;
        do {
            vii W = getgrav(n, perm, Y);
            if (W == Z) cnt++;
        } while (next_permutation(all(perm)));
        return cnt;
    }

    vi MonomaticStack(vi& X)
    {
        ll n = X.size();
        stack<pair<ll, ll>> s;
        vi Z(n, n);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top().first < X[i]) {
                Z[s.top().second] = i;
                s.pop();
            }
            s.push({ X[i] , i });
        }

        return (Z);
    }

    vi MonomaticStackLeft(vi& X)
    {
        ll n = X.size();
        stack<pair<ll, ll>> s;
        vi Z(n, -1);

        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && s.top().first < X[i]) {
                Z[s.top().second] = i;
                s.pop();
            }
            s.push({ X[i] , i });
        }

        return (Z);
    }

    void solve(int tc) {
        ll n;

        cin >> n;

        vp X(n);
        vi Y(n);
        vi C(n);
        for (int i = 0; i < n; i++)
        {
            cin >> X[i].first;
            X[i].second = i;
        }
        for (int i = 0; i < n; i++) cin >> C[i];
        for (int i = 0; i < n; i++) Y[i] = X[i].first;

        sort(X.rbegin(), X.rend());
        vi dpl(n + 1, 0), dpr(n + 1, 0);
        vi msl = MonomaticStackLeft(Y), msr = MonomaticStack(Y);
        vector<ordered_set> ord(n+1);
        ll res = 1;
        for (int i = 0; i < n; i++)
        {
            ll ind = X[i].second;
            ll l = msl[ind], r = msr[ind];
            if (l != -1 && C[ind] == C[l]) dpl[ind] = dpl[l];
            else dpl[ind] = l;
            if (r != n && C[ind] == C[r]) dpr[ind] = dpr[r];
            else dpr[ind] = r;

            r = ord[C[ind]].order_of_key(dpr[ind]+1);
            l = ord[C[ind]].order_of_key(dpl[ind]);
            ll len = r - l + 1;
            ord[C[ind]].insert(ind);
            res = (res * len) % MODE;
        }
        
        cout << req(n, Y, C) << ' ';
        cout << res << '\n';
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
