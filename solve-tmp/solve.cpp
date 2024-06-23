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


vp Longest_Increasing_SubSeq(vi &X) {
    vp res;
    vp Z(1, {INT32_MIN, -1});
    vi prev(X.size());

    for (int i = 0; i < X.size(); i++) {
        pl k = {X[i], 0};
        ll re = lower_bound(Z.begin(), Z.end(), k) - Z.begin();
        prev[i] = Z[re - 1].second;
        if (re == Z.size()) Z.push_back({X[i], i});
        else Z[re] = {X[i], i};
    }

    int at = Z.back().second;

    while (at != -1)
    {
        res.push_back({X[at], at});
        at = prev[at];
    }
    res.push_back({0, -1});
    reverse(all(res));
    res.push_back({INT32_MAX, INT32_MAX});
    return res;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);
    set<int> st;

    for (int i = 0; i < n; i++)
        cin >> X[i];
    vp Z = Longest_Increasing_SubSeq(X);

    for (int i = 0; i < Z[0].second; i++)
        st.insert(X[i]);

    for (int i = 1; i < Z.size() - 1; i++)
        cout << Z[i].first << ' ' << Z[i].second << '\n';
    

    ll at = 0;
    for (int i = 0; i < n; i++)
    {
        while (i >= Z[at].second)
            at++;
        if (X[i] < Z[at - 1].first || X[i] > Z[at].first) st.insert(X[i]);
    }
    
    cout << st.size() << '\n';
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