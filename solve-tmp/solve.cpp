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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

const int MODE = 998244353;

ll req(string &s, vp &Y, ll k) {
    ll n = s.size();
    ll lf = 0;
    mc M;
    string t = "";

    for (int i = 0; i < Y.size(); i++){
        if (Y[i].first % k) return 0;
        M[Y[i].second] = Y[i].first / k;
        lf += Y[i].first / k;
    }

    for (int i = 0; i < n && lf; i++)
    {
        if (s[i] == 'a' && t == "") continue;
        t += s[i];
        if (s[i] == 'a') continue;
        if (!M[s[i]]) return(0);
        M[s[i]]--;
        lf--;
    }
    ll  m;
    ll at = 0;
    vp Z;

    m = t.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' && !at) continue;
        if (s[i] != t[at]) return(0);
        at++;
        if (at == m) {
            Z.push_back({i-m+1, i});
            at = 0;
        }
    }
    if (at) return (0);
    ll l, r;
    ll mn = INT32_MAX;
    ll mnl = INT32_MAX;
    ll mnr = INT32_MAX;
    if (Z.size() == 1) {
        l = Z[0].first + 1;
        r = n - Z[0].second;
        //cout << l << ' ' << r << "|\n";
        return (l * r);
    }

    mnl = Z[0].first;
    mnr = n - Z.back().second - 1;
    for (int i = 0; i < Z.size() - 1; i++)
    {
        l = Z[i + 1].first -  Z[i].second - 1;
        mnl = min(mnl, l);
        mnr = min(mnr, l);
    }

    ll summ = 0;
    for (int i = 0; i <= mnl; i++)
    {
        summ += max(mnr - i + 1, 0ll);
    }
    //cout << t << ' ' << mnl << ' ' << mnr << ' ' << "|\n";
    
    return (summ);
}

void solve(ll tc) {
    ll n;
    string s;

    cin >> s;

    n = s.size();
    mc freq;

    for (auto a : s) freq[a]++;

    if (freq['a'] == n) {
        cout << n - 1 << '\n';
        return;
    }

    vp CH;
    for (char i = 'b'; i <= 'z'; i++)
        if (freq[i]) CH.push_back({freq[i], i});
    
    int mn = min_element(all(CH))->first;
    ll summ = 0;

    for (int i = 1; i * i <= mn; i++) {
        if (mn % i) continue;
        summ += req(s, CH, i);
        if (i * i != n)
        summ += req(s, CH, mn / i);
    }
    cout << summ << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
