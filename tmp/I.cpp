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

const int MODE = 1e9 + 7;
const int MAXX = (1 << 30) - 1;

pl getmx(pl a, pl b){
    if (a.first > b.first) return (a);
    if (b.first > a.first) return (b);
    if (a.second < b.second) return (a);
    return b;
}

void solve(ll tc) {
    ll n;

    cin >> n;

    vii X(n, vi(3));
    priority_queue<vi, vii, greater<vi>> L;
    pl mx = {0, 0};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> X[i][j];
    sortx(X);

    for (int i = 0; i < n; i++)
    {
        while (!L.empty() && L.top()[0] < X[i][0])
        {
            mx = getmx(mx, {L.top()[1], L.top()[2]});
            L.pop();
        }
        pl re = mx;
        re.first++;
        re.second = max(re.second, X[i][2]);
        L.push({X[i][1], re.first, re.second});
    }
    
    while (!L.empty())
    {
        mx = getmx(mx, {L.top()[1], L.top()[2]});
        L.pop();
    }

    cout << mx.first << ' ' << mx.second << '\n';
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
