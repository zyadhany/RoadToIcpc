// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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

using namespace std;

const int MODE =1e9+7;
const ll INF = 1e16;

const int LOG = 61;
struct Basis {
  ll basis[LOG];
  ll cnt;
  Basis() {
    cnt = 0;
    clear();
  };
 
  bool insert(ll mask) {
    for (int i = LOG - 1; ~i; --i) {
      if ((mask >> i) & 1) {
        if (!basis[i]) {
          basis[i] = mask;
          cnt++;
          return 1;
        }
        mask ^= basis[i];
      }
    }
    return 0;
  }

  ll orderofkey(ll x) {
        ll k = 1;
        ll c = cnt-1;
        for(int i = LOG - 1; i >= 0; i --) {
            if ((x >> i) & 1) {
                if (!basis[i]) return 0;
                k += (1ll << c);
            }
            c--;
        }
        return k;
    }

  bool get(ll mask) {
    for (int i = LOG - 1; ~i; --i) {
      if ((mask >> i) & 1) {
        if (!basis[i]) {
          return 0;
        }
        mask ^= basis[i];
      }
    }
    return 1;
  }
 
  void clear() {
    memset(basis, 0, sizeof basis);
  }
 
  void merge(const Basis &other) {
    for (int i = LOG - 1; ~i; --i) {
      if (other.basis[i]) insert(other.basis[i]);
    }
  }
 
  ll getmax() {
    int ret = 0;
    for (int i = LOG - 1; ~i; --i) {
      if ((ret >> i) & 1) continue;
      ret ^= basis[i];
    }
    return ret;
  }
 
 
    ll kth(ll k) {
        if (k > (1ll << cnt)) return -1;
        ll c = cnt-1;
        ll ret = 0;
        for(int i = LOG - 1; i >= 0; i --) {
            if(!basis[i]) continue;
            if(k > (1ll << c)) {
                k -= (1ll << c);
                ret = max(ret, ret ^ basis[i]);
            } else ret = min(ret, ret ^ basis[i]);
            c--;
        }
        return ret;
    }

};

void solve(int tc) {
    ll n, k;
    cin >> n >> k;

    Basis bs;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        bs.insert(a);
    }
    
    ll lef = n - bs.cnt;
    lef = min(21ll, lef);
    lef = (1ll << lef);

    ll at = 1;
    vi res;
    while (res.size() < k) {
        ll g = bs.kth(at);
        ll b = lef;
        while (b-- && res.size() < k) res.push_back(g);
        at++;
    }

    for (auto a : res) cout << a << ' ';
    cout << '\n';
}
    
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
