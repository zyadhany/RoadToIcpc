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

const int MAXSZ = 1e7 + 1;
int prime[MAXSZ] = {0};
vi primes;
 
void INIT() {
    for (int i = 0; i < MAXSZ; i++) prime[i] = i;
    for (int i = 2; i * i < MAXSZ; ++i) if (prime[i] == i)
        for (int j = i; j < MAXSZ; j += i) prime[j] = i;
    for (int i = 2; i < MAXSZ; i++) if(prime[i] == i) primes.push_back(i);
}

vi PF(ll n) {
    vi X;

    while (n > 1)
    {
        X.push_back(prime[n]);
        n /= prime[n];
    }
 
    set<ll> st(all(X));
    vi Y(all(st));
    return Y;
}

int frq[MAXSZ] = {0};

ll req(vii &adj, vi &res, ll n, ll k) {
    if (res[n]) {
        if (res[n] == k) return 1;
        else return -1;
    }

    res[n] = k;
    if (k == 1) k = 2;
    else k = 1;
    for (auto a : adj[n]) {
        ll re = req(adj, res, a, k);
        if (re == -1) return -1;
    }

    return 1;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);
    vi res(n);
    
    vii adj(n);
    

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    
    }
    
    for (int i = 0; i < n; i++)
    {
        if (X[i] == 1) {
            res[i] = 1;
            continue;
        }
        auto Z = PF(X[i]);
    
        for (auto a : Z) {
            if (frq[a] == -1) MUN;
            if (frq[a] == 0) frq[a] = i + 1;
            else {
                adj[i].push_back(frq[a]-1);
                adj[frq[a]-1].push_back(i);
                frq[a] = -1;
            }            
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (res[i] == 0) {
            ll re = req(adj, res, i, 1);
            if (re == -1) MUN;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    
    INIT();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
