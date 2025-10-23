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

const int LOG = 62;
struct Basis {
  ll basis[LOG];
  vi IND;
  ll cnt;
  Basis() {
    cnt = 0;
    clear();
  };
 
  bool insert(int mask, int ind) {
    for (int i = LOG - 1; ~i; --i) {
      if ((mask >> i) & 1) {
        if (!basis[i]) {
          basis[i] = mask;
          cnt++;
          IND.push_back(ind);
          return 1;
        }
        mask ^= basis[i];
      }
    }
    return 0;
  }

  bool get(int mask) {
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
    IND.clear();
}
 
  void merge(const Basis &other) {
    for (int i = LOG - 1; ~i; --i) {
      if (other.basis[i]) insert(other.basis[i], 1);
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

    ll orderofkey(ll x) {
        ll k = 1;
        ll v = 0;
        ll c = cnt-1;
        for(int i = LOG - 1; i >= 0; i --) {
            if(!basis[i]) continue;
            if ((x&(1<<i))) {
                k += (1ll << c);
            }
            c--;
        }
 
        return k;
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
            }else ret = min(ret, ret ^ basis[i]);
            c--;
        }
        return ret;
    }
};



void solve(int tc) {
    ll n, q;
    cin >> n >> q;

    vi X(n);
    for (int i = 0; i < n; i++) cin >> X[i];


    vi dp(n);
    Basis bs;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!(bs.insert(X[i], i))) {
            auto IND = bs.IND;
            IND.push_back(i);
            sortx(IND);
            bs.clear();
            for (auto a : IND) bs.insert(X[a], a);
        }

        auto IND = bs.IND;
        sortx(IND);

        dp[i] = i+1;
        ll ord = 1;
        ll lsind = i;
        ll sz = 2;

        Basis S;
        S.insert(X[i], i);

        for (auto a : IND) {
            if (a == i) continue;

            ll mxind = sz - ord + lsind;
            if (a > mxind + 1) break;

            ord += a - lsind - 1;
            ll v = S.kth(ord);
            S.insert(X[a], a);
            ord = S.orderofkey(v);
            sz *= 2;
            if (ord == sz) break;
            ord++;
            lsind = a;
            dp[i] = a + sz-ord;
        }
    }

    while (q--)
    {
        ll l, r; cin >> l >> r; l--, r--;
        if (r <= dp[l]) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int size = 1;    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}