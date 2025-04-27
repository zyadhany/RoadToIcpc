#include <bits/stdc++.h>
#include <unordered_map>
#include "testlib.h"

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

using namespace std;

string conv(int i, int len)
{
    string s = "";
    for (int j = 0; j < len; j++)
    {
        if (i & (1 << j)) s += '(';
        else s += ')';
    }
    return s;
}
bool validcor(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
    }
    return cnt == 0;
}

void req(vii &adj, vi &ndcnt, string &s, ll n, ll p, ll &at) {
    while (at < s.size())
    {
        if (s[at] == ')') {
            at++;
            break;
        }
        ll nn = ndcnt.back();
        ndcnt.pop_back();
        adj[n].push_back(nn);
        at++;
        req(adj, ndcnt, s, nn, n, at);
    }
    
}

vii coverttree(string &s) {
    ll n = s.size() / 2 + 1;
    vi ndcount;
    for (int i = 2; i <= n; i++)
    {
        ndcount.push_back(i);
    }
    shuffle(all(ndcount));

    vii adj(n + 1);
    ll at = 0;

    req(adj, ndcount, s, 1, 0, at);
    return adj;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int TEST = 10'000;

    vector<string> X;
    for (int len = 0; len <= 10; len+=2)
    {
        for (int i = 0; i < 1 << len; i++)
        {
            string s = conv(i, len);
            if (!validcor(s)) continue;
            X.push_back(s);
        }
    }

    for (auto s : X) {
        auto adj = coverttree(s);

        for (int i = 1; i <= s.size()/2+1; i++)
        {
            for (auto j : adj[i]) cout << i << ' ' << j << '\n';
        }
        

        cout << "=====\n";
    }

    cout << X.size() << '\n';
    return 0;

    cout << TEST << '\n';
    for (int i = 0; i < TEST; i++)
    {
        ll a = 1e9-i;
        cout << a << '\n';
    }
}

/*
<#list 1..10 as i >
     igen --m 10 ${i} > $ 
</#list>
*/