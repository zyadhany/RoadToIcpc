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
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vp X(n);
    
    set<int> st;

    for (int i = 0; i < n; i++) {
        cin >> X[i].first;
        st.insert(X[i].first);
    }
    sortx(X);

    ll at = 1;
    for (auto a : st) {
        for (int i = 0; i < n; i++)
            if (X[i].first == a) X[i].second = at;
        at++;
    }


    ll summ = 0;
    vi Y(n + 10);

    for (int i = 0; i < n; i++)
    {
        if (!Y[X[i].second]) summ++;
        Y[X[i].second]++;
    }
    
    ll mn = summ;

    for (int i = 0; i < n; i++)
    {
        ll re = 0;
        for (int j = i; j >= 0; j--)
        {
           
            Y[X[j].second]--;
            if (!Y[X[j].second]) summ--;

            re += abs(X[j].first - X[i].first);

            if (!Y[X[i].second]) summ++;
            Y[X[i].second]++;
            
            ll a = re;
            for (int h = i; h < n; h++)
            {
                Y[X[h].second]--;
                if (!Y[X[h].second]) summ--;
                    
                if (!Y[X[i].second]) summ++;
                Y[X[i].second]++;
                
                a += abs(X[h].first - X[i].first);
                if (a <= k) mn = min(mn, summ);
            }

            for (int h = i; h < n; h++)
            {
                if (!Y[X[h].second]) summ++;
                Y[X[h].second]++;
                    
                Y[X[i].second]--;
                if (!Y[X[i].second]) summ--;
            }
        }

        for (int j = 0; j <= i; j++)
        {
            if (!Y[X[j].second]) summ++;
            Y[X[j].second]++;

            Y[X[i].second]--;
            if (!Y[X[i].second]) summ--;
        }
    }

    cout << mn << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}