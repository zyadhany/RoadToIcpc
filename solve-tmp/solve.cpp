#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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

const int MODE = 1e9 + 7;

using namespace std;

vi dx = {1, 0, -1, 0};
vi dy = {0, -1, 0, 1};

pl BFS(ll l, ll r)
{
    ll k, a, b, mx;
    pl res;

    cin >> k;

    mx = 0;
    vii vis(l + 1, vi (r + 1, 0));
    queue<pl> que;

    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        que.push({a, b});
        vis[a][b] = 1;
    }
    

    while (!que.empty())
    {
        pl m = que.front();
        que.pop();
        if (vis[m.first][m.second] > mx) {
            mx = vis[m.first][m.second];
            res = m;
        }

        for (int i = 0; i < dx.size(); i++)
        {
            pl re = m;
            re.first += dx[i];
            re.second += dy[i];
            if (re.first > l || re.second > r|| re.first <= 0 || re.second <= 0) continue;
            if (!vis[re.first][re.second]){
                vis[re.first][re.second] = vis[m.first][m.second] + 1;
                que.push(re);
            }
        }
        
    }

    return (res);
}



void solve(int tc) {
    ll n, m;

    cin >> n >> m;
    pl res = BFS(n, m);
    cout << res.first << ' ' << res.second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++) {
        solve(i);
    }
}   
