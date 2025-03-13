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

int block;
 
const int MAXSZ = 1e7 + 10;
int prime[MAXSZ] = {0};
 
void INIT() {
    for (int i = 0; i < MAXSZ; i++) prime[i] = i;
    for (int i = 2; i * i < MAXSZ; ++i) if (prime[i] == i)
        for (int j = i; j < MAXSZ; j += i) prime[j] = i;
}

void divsorFactors(vp &faccnt, vi &div, ll at, ll d) {
    if (at == faccnt.size()) {div.push_back(d); return;}
    divsorFactors(faccnt, div, at + 1, d);
    for (int i = 0; i < faccnt[at].second; i++)
    {
        d *= faccnt[at].first;
        divsorFactors(faccnt, div, at + 1, d);
    }
}

vi PF(ll n) {
    vi X;
    while (n>1)
    {
        X.push_back(prime[n]);
        n /= prime[n];
    }

    return (X);
}

// Structure to represent a query range
struct Query
{
    int L, R, ind;
};
 
// Function used to sort all queries so that all queries 
// of the same block are arranged together and within a block,
// queries are sorted in increasing order of R values.
bool compare(Query x, Query y)
{
    if (x.L/block != y.L/block)
       return x.L/block < y.L/block;
    return x.R < y.R;
}

void MoAdd(vi &Z, vi &freq, set<pl> &st) {
    for (auto a : Z) {
        if (freq[a])
        st.erase({freq[a], a});
        freq[a]++;
        st.insert({freq[a], a});
    }
}

void MoRemove(vi &Z, vi &freq, set<pl> &st) {
    for (auto a : Z) {
        st.erase({freq[a], a});
        freq[a]--;
        if (freq[a])
        st.insert({freq[a], a});
    }
}

vi MoQueryResult(vector<Query> Q, vi &X, vii &Z)
{
    ll n, m;

    n = X.size(), m = Q.size();
    block = (int)sqrt(n);
    vi res(m, -1);
    vi freq(MAXSZ, 0);
    set<pl> st;    

    sort(Q.begin(), Q.end(), compare);
 
    ll currL = 1, currR = 1;
 
    for (int i = 0; i < m; i++)
    {
        ll L = Q[i].L, R = Q[i].R, ind = Q[i].ind;
        
        while (currL > L)
        {
            MoAdd(Z[currL - 1], freq, st);
            currL--;
        }

        while (currR <= R)
        {
            MoAdd(Z[currR], freq, st);
            currR++;
        }
 
        while (currL < L)
        {
            MoRemove(Z[currL], freq, st);
            currL++;
        }
 
        while (currR > R+1)
        {
            MoRemove(Z[currR - 1], freq, st);
            currR--;
        }
 
        ll sz = (R-L+1);
        ll k = (sz + 1) / 2;
        auto it = prev(st.end());
        while (true) {
            if (it->first < k) break;
            res[ind] = max(res[ind], it->second);
            if (it == st.begin()) break;
            it--;
        }
    }

    return (res);
}


void solve(int tc) {
    ll n;

    cin >> n;
    vi X(n + 1);
    vii Z(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        Z[i] = PF(X[i]);
        // make Z[i] uniq
        sortx(Z[i]);
        Z[i].resize(unique(all(Z[i])) - Z[i].begin());
    }

    ll q;
    cin >> q;
    vector<Query> Q(q);
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].L >> Q[i].R;
        Q[i].ind = i;
    }

    vi res = MoQueryResult(Q, X, Z);
    for (auto x : res)
        cout << x << '\n';
} 

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    INIT();
    
    // freopen("promote.in", "r", stdin);
    // freopen("promote.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
