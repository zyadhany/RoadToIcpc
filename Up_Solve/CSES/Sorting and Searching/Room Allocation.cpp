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

void solve(ll tc) {
    ll n;

    cin >> n;

    vector<pair<pl, ll>> X(n);
    vi res(n);
    set<int> st;
    priority_queue<pl, vp, greater<pl>> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first.first >> X[i].first.second;
        X[i].second = i; 
        st.insert(i + 1);
    }
    sortx(X);
    
    for (int i = 0; i < n; i++)
    {
        pl re = X[i].first;
        int ind = X[i].second;

        while (!pq.empty() && pq.top().first < re.first)
        {
            st.insert(pq.top().second);
            pq.pop();
        }

        int k = *st.begin();
        res[ind] = *st.begin();
        st.erase(st.begin());
        pq.push({re.second, k});
    }
    

    cout << *max_element(all(res)) << '\n';
    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
