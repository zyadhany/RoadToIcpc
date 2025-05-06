#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
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
using namespace std;

vector<int> manacher_odd(vp &s) {
    int n = s.size();
    vector<int> p(n);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (s[i].first <= -6) p[i] = 0, l = i+1, r = i+2, i++;
        else 
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(vp&s) {
    vp t;
    t.push_back(pl(-1,-1));
    for(auto &v: s) {
        t.push_back(pl(-3,-3));
        t.push_back(v);
    }
    t.push_back(pl(-3,-3));
    t.push_back(pl(-2,-2));
    auto res = manacher_odd(t);
    for (int i = 0; i < res.size(); i++)
    {
        res[i]--;
    }
    return vector<int>(begin(res) + 1, end(res));
}
const int MODE = 1e9+7;
const int p = 31;
const int MODE2 = 1e9+9;
const int p2 = 37;
 
void solve(int tc)  {
    ll n, m;

    cin >> n >> m;

    vector<string> X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }

    vi pw(300, 1);
    vi pwpr(300, 1);
    for (int i = 1; i < pw.size(); i++)
    {
        pw[i] = (pw[i-1]*p) % MODE;
        pwpr[i] = (pw[i]+pwpr[i-1]) % MODE;
    }
    vi pw2(300, 1);
    vi pwpr2(300, 1);
    for (int i = 1; i < pw2.size(); i++)
    {
        pw2[i] = (pw2[i-1]*p2) % MODE2;
        pwpr2[i] = (pw2[i]+pwpr2[i-1]) % MODE2;
    }
    
    ll cnt = 0;
    vp frq(n);
    for (int i = 0; i < m; i++)
    {
        vii pr(n, vi(26));
        for (int j = i; j < m; j++)
        {
            for (int h = 0; h < n; h++)
            {
                pr[h][X[h][j]-'a']++;
                pl re = {0,0};
                ll cnod = 0;
                for (int c = 0; c < 26; c++)
                {
                    int cpr = pr[h][c];
                    cnod += cpr%2;
                    if (!cpr) continue;
                    re.first = (re.first *pw[cpr] + (c+1)*pwpr[cpr-1])%MODE;
                    re.second = (re.second *pw2[cpr] + (c+1)*pwpr2[cpr-1])%MODE2;
                }
                frq[h] = re;
                if (cnod >= 2) frq[h] = {-10-h, -10-h};
            }

            auto res = manacher(frq);
            for (auto a: res) cnt += (a+1)/2;
        }        
    }
    
    cout << cnt << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    // freopen("dec.in", "r", stdin);
    // freopen("dec.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}