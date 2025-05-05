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

void solve(int tc)  {
    int n,m; cin>>n>>m;
    vi v(m);
    int cnt[1000005]{};
    int res[n+1]{};
    for(int i = 0 ; i < m ; i++) cin>>v[i],cnt[v[i]]++;
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    for(auto it : v){
        for(int i = it ; i <= n ; i+=it){
            res[i]+=cnt[it];
        }
    }
    res[0] = 1;
    int ans = 0;
    for(int i = 0  ;i  < n; i ++){
        cout<<i<<" "<<res[i]<<" "<<n-i<<" "<<res[n-i]<<"\n";
        ans += res[i] * res[n-i];
    }
    ans/=2;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("tree.in", "r", stdin);
    // freopen("island.out", "w", stdout);

     cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
