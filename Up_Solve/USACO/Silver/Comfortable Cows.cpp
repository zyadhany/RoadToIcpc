#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<int, int>
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

const int MODE = 1e9;

using namespace std;

vi dx = {1, -1, 0, 0};
vi dy = {0, 0 , 1, -1};

pair<ll, pl> countar(vector<vector<bool>> &cw, ll l, ll r) {
    ll cnt = 0;
    pl lf = {l, r};
    for (int i = 0; i < 4; i++)
    {
        ll a = dx[i] + l;
        ll b = dy[i] + r;
        if (cw[a][b]) cnt++;
        else lf = {a, b};
    }
    return {cnt, lf};
}

void solve(int tc) {
    ll n;

    cin >> n;

    ll tot = 0;
    vector<vector<bool>> cw(4010, vector<bool>(4010));
    stack<pl> st;
    
    for (int i = 1; i <= n; i++)
    {
        pl p; cin >> p.first >> p.second;
        p.first += 1000;
        p.second += 1000;
        
        st.push(p);

        while (!st.empty())
        {
            pl tp = st.top();
            st.pop();
            if (cw[tp.first][tp.second]) continue;
            cw[tp.first][tp.second] = 1;
            tot++;
            
            auto cc = countar(cw, tp.first, tp.second);
            if (cc.first == 3) st.push(cc.second); 

            for (int mod = 0; mod < 4; mod++) {
                ll a = tp.first + dx[mod];
                ll b = tp.second + dy[mod];
                if (!cw[a][b]) continue;
                cc = countar(cw, a, b);
                if (cc.first == 3) st.push(cc.second); 
            }
        }
        
        cout << tot - i << '\n';
    } 
}  

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("mooyomooyo.in", "r", stdin);
    // freopen("mooyomooyo.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
