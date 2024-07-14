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

vii buildSparseTable(vi &X)
{
    ll n, m;
    n = X.size(); m = ceil(log2(n));
    vii table(n, vi(m + 1));
    for (int i = 0; i < n; i++)
        table[i][0] = X[i];
 
    for (int j = 1; j <= m; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = min(table[i][j - 1],
               table[i + (1 << (j - 1))][j - 1]);

    return (table);
}
 
// optmization to get in O(1)
long long query(vii &table, int L, int R) 
{ 
    int j = (int)log2(R - L + 1); 
    return min (table[L][j], table[R - (1 << j) + 1][j]);
}

void solve(int tc) {
    ll n, q, summ;

    cin >> n >> q;

    summ = 0;
    vi X(n);
    vi res(q);
    map<int, vi> Y;

    for (int i = 0; i < n; i++) {
        cin >> X[i];
        summ += X[i];
        Y[X[i]].push_back(i);
    }
    
    auto Z = buildSparseTable(X);

    priority_queue<pair<pl, pl>> pq;
    pq.push({{n, 0}, {0, n - 1}});
    
    
    while (q--)
    {
        ll k; cin >> k;
        //cout << summ << "|" << endl;
        while (k && summ && !pq.empty())
        {
            auto pqa = pq.top();
            pq.pop();
            pl ran = pqa.second;
            ll mn = query(Z, ran.first, ran.second);
            ll left = mn - pqa.first.second;
            
            summ -= min(left, k) * pqa.first.first;
            if (k < left) {
                pqa.first.second += k;
                k = 0;
                pq.push(pqa);
            } else {
                k -= left;
                vi &M = Y[mn];
                auto at = lower_bound(all(M), ran.first);

                ll l = ran.first - 1, r;
                while (at != M.end() && *at <= ran.second)
                {
                    r = *at;
                    if (r - l > 1) {
                        pq.push({{r - l - 1, mn}, {l + 1, r - 1}});
                    }
                    l = r;
                    at++;
                }
                r = ran.second + 1;
                if (r - l > 1) {
                    pq.push({{r - l - 1, mn}, {l + 1, r - 1}});
                }
            }
        }
        
        cout << summ << '\n';
    }   
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
