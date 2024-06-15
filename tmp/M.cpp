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

ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (gcd(b, a % b));
}

vi P;

void solve(ll tc) {
    ll n;

    cin >> n;

    vi X;
    mi Y;
    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        if (!Y[a]) X.push_back(a);
        Y[a] = 1;
    }
    sortx(X);

    if (X.size() == 1) {
        cout << "2\n";
        return;
    }

    ll g = X[1] - X[0];

    for (int i = 1; i < n - 1; i++)
    {
        ll a = X[i + 1] - X[i];
        g = gcd(g, a);
    }

    if (g == 1) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < P.size(); i++)
    {
        if (P[i] > g) break;
        if (g % P[i] == 0) {
            cout << P[i] << '\n';
            return;
        }
    }

    cout << g << '\n';
}

vi prime(1e7 + 10, 0);
void INIT() {
    for (int i = 0; i < prime.size(); i++) prime[i] = i;
    for (int i = 2; i * i <= 1e7; ++i) if (prime[i] == i)
        for (int j = i; j <= 1e7; j += i) prime[j] = i;
    for (int i = 2; i < 3162278; i++)
        if (prime[i] == i) P.push_back(i);    
}

int main()
{
    INIT();
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
