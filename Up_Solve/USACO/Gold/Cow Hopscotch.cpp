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


ll rangequery(const vii &BIT, int l, int r) {
    ll summ = 0;

    for (int i = l; i > 0; i -= i & -i)
        for (int j = r; j > 0; j -= j & -j)
            summ = (summ + BIT[i][j]) % MODE;
    
    return summ;
}

ll rangequery(const vii& BIT, int l1, int r1, int l2, int r2) {
    ll res = 0;
    res += rangequery(BIT, l2, r2);
    res -= rangequery(BIT, l1 - 1, r2);
    res -= rangequery(BIT, l2, r1 - 1);
    res += rangequery(BIT, l1 - 1, r1 - 1);
    res = (res%MODE + MODE) % MODE;
    return res;
}

void updatepoint(vii& BIT, int l, int r, ll val) {
    for (int i = l; i < BIT.size(); i += i & -i)
        for (int j = r; j < BIT[0].size(); j += j & -j)
            BIT[i][j] = (BIT[i][j] + val) % MODE;
}

ll rangequery(const vi& Z, int l, int r) {
	ll summ = 0;
	for (int i = r; i > 0; i -= i & -i)
		summ = (summ + Z[i]) % MODE;
    
    for (int i = l - 1; i > 0; i -= i & -i)
        summ = (summ - Z[i] + MODE) % MODE;

    return summ;
}

void updatepoint(vi& Z, ll n, int at) {
	for (int i = at; i < Z.size(); i += i & -i)
		Z[i] = (Z[i] + n) % MODE;
}

void solve(int tc) {
    ll n, m, k;
    cin >> n >> m >> k;
    vii DP(n + 1, vi(m + 1, 0));
    vii X(n + 1, vi(m + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> X[i][j];
            X[i][j]--;
        }


    vii IND(k, vi(1, 0));
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (IND[X[i][j]].back() != j)
                IND[X[i][j]].push_back(j);
        }
    }
    
    vii freq(k);
    for (int i = 0; i < k; i++)
    {
        freq[i].resize(IND[i].size());
    }
    
    

    updatepoint(DP, n, m, 1);
    updatepoint(freq[X[n][m]], 1, freq[X[n][m]].size()-1);
    for (int i = n-1; i >= 1; i--)
    {
        vi temp(m + 1, 0);
        for (int j = m-1; j >= 1; j--)
        {
            ll re = rangequery(DP, i+1, j+1, n, m);

            ll ind = upper_bound(all(IND[X[i][j]]), j) - IND[X[i][j]].begin();

            re -= rangequery(freq[X[i][j]], ind, freq[X[i][j]].size()-1);
            re = (re%MODE + MODE) % MODE;

            temp[j] = re;
            updatepoint(DP, i, j, re);
        }
        for (int j = 1; j <= m-1; j++)
        {
            ll ind = lower_bound(all(IND[X[i][j]]), j) - IND[X[i][j]].begin();
            updatepoint(freq[X[i][j]], temp[j], ind);
        }
        
    }
    
    cout << rangequery(DP, 1, 1) << ln;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
