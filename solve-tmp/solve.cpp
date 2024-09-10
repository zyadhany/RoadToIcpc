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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void req(vi &X) {
    ll n = X.size();
    vp Y(n + 10);

    for (int i = 0; i < n; i++)
        Y[i] = {X[i], i};
    sort(Y.rbegin(), Y.rend());

    vi Z(n + 10);
    for (int i = 0; i < min(n, 3ll); i++)
        Z[Y[i].second] = i + 1;


    ll cnt = (Y[0].first != 0) + (Y[1].first != 0) + (Y[2].first != 0);

    for (int i = 0; i < n; i++)
    {
        if (!Z[i]) cout << "pushBack\n";
        else if (Z[i] == 1) cout << "pushFront\n";
        else if (Z[i] == 2) cout << "pushQueue\n";
        else cout << "pushStack\n";
    }
    
    cout << cnt;
    for (int i = 0; i < cnt; i++)
    {
        cout << " ";
        if (i == 0) cout << "popFront";
        else if (i == 1) cout << "popQueue";
        else cout << "popStack";
    }
    
    cout << '\n';
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X;
    vii Z;

    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        if (a) X.push_back(a);
        else
        {
            Z.push_back(X);
            X.clear();
        }
    }
    
    for (int i = 0; i < Z.size(); i++)
        req(Z[i]);
    for (int i = 0; i < X.size(); i++)
        cout << "pushStack\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("whatbase.in", "r", stdin);
    //freopen("whatbase.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
