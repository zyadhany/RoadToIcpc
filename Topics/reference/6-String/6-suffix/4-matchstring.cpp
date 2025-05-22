#include <bits/stdc++.h>

#define ll int
#define ld long double
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) (X.begin(),X.end());
#define ln '\n'


const ll mode = 3 * 1e6;


using namespace std;


void FP()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}




vi tree(mode, INT32_MAX);


void updateRangeUtil(ll si, ll ss, ll se, ll us,
    ll ue, ll diff)
{


    if (ss > se || ss > ue || se < us)
        return;

    if (ss >= us && se <= ue)
    {
        tree[si] = diff;

        return;
    }

    ll mid = (ss + se) / 2;
    updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
    updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);

    tree[si] = min(tree[si * 2 + 1], tree[si * 2 + 2]);
}


void updateRange(ll n, ll us, ll ue, ll diff)
{
    updateRangeUtil(0, 0, n - 1, us, ue, diff);
}

ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{


    if (ss > se || ss > qe || se < qs)
        return INT32_MAX;

    if (ss >= qs && se <= qe)
        return tree[si];

    ll mid = (ss + se) / 2;
    return min(getSumUtil(ss, mid, qs, qe, 2 * si + 1),
        getSumUtil(mid + 1, se, qs, qe, 2 * si + 2));
}

ll getSum(ll n, ll qs, ll qe)
{
    return getSumUtil(0, n - 1, qs, qe, 0);
}







vi X, Y, Z;

//faster time;
vi suffix_array(const string& s, int lim = 128)
{
    int n = s.size() + 1, cl = lim;
    vi sa(n), c(n), cn(n), pn(n), cnt(max(n, lim));
    iota(pn.begin(), pn.end(), 0);
    for (int i = 0; i < n - 1; i++) c[i] = s[i];

    for (int k = 0; k <= n; k = k ? 2 * k : 1)
    {
        if (k) for (int i = 0; i < n; i++) pn[i] = (sa[i] + n - k) % n;
        for (int i = 0; i < cl; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < cl; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--cnt[c[pn[i]]]] = pn[i];

        cn[sa[0]] = 0;
        cl = 1;
        for (int i = 1; i < n; i++)
        {
            if (c[sa[i]] != c[sa[i - 1]] || c[(sa[i] + k) % n] != c[(sa[i - 1] + k) % n])
                cl++;
            cn[sa[i]] = cl - 1;
        }
        if (cl == n) break;
        swap(c, cn);
    }
    sa.erase(sa.begin());;

    return sa;
}


//longest common prefixes for suffix array
void lcp_suffix(const vi& X, const string& s) {
    ll n = s.size(), k = 0;
    Y.resize(n);
    Z.resize(n);
    for (int i = 0; i < n; i++)
        Z[X[i]] = i;

    for (int i = 0; i < n - 1; i++)
    {
        while (s[i + k] == s[X[Z[i] - 1] + k])
            k++;
        Y[Z[i]] = k;
        k = max(k - 1, 0);
    }
}
string s;

bool req(pair<ll, ll> l, pair<ll, ll> r) {

    ll a = Z[l.first - 1], b = Z[r.first - 1], 
        L = l.second - l.first + 1, R = r.second - r.first + 1
        , k = getSum(Y.size() + 10, min(a, b) + 1, max(a, b));

    if (k >= R && k >= L && L == R) return l < r;
    if (k >= R || k >= L)return L < R;
    return s[l.first + k - 1] < s[r.first + k - 1];
}

// to get longest lcp betwen 2 string 
void solve() {
    ll n;
    cin >> s >> n;

    char a = '\n';
    s += a;
    X = suffix_array(s);

    lcp_suffix(X, s);

    vector<pair<ll, ll>> Z(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Z[i].first >> Z[i].second;

    }
    for (int i = 0; i < Y.size(); i++)
    {
        updateRange(Y.size() + 10, i, i, Y[i]);
    }

    sort(Z.begin(), Z.end(), req);
    for (int i = 0; i < n; i++)
    {
        cout << Z[i].first << ' ' << Z[i].second << "\n";
    }
}


int main()
{
    FP();
    int size = 1;

    //cin >> size;
    while (size--)
    {
        solve();
    }
}
