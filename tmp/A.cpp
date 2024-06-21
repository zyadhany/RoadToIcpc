#define _CRT_SECURE_NO_WARNINGS
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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

class Graph {
public:
    int size;
    vi vis, colorArr;
    vii adj;
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vi findCircule() {
        vi res;

        for (int i = 1; i <= size && res.empty(); i++)
        {
            if (vis[i]) continue;
            stack<pl> st;
            stack<int> pros;
            st.push({i, 0});

            while (!st.empty())
            {
                auto m = st.top();
                st.pop();
                if (m.second == -1) {
                    pros.pop();
                    continue;
                }
                if (vis[m.first]) {
                    res.push_back(m.first);
                    while (pros.top() != m.first)
                    {
                        res.push_back(pros.top());
                        pros.pop();
                    }
                    res.push_back(m.first);  
                    break;                  
                }
                vis[m.first] = 1;
                pros.push(m.first);
                for (auto a : adj[m.first]) {
                    if (a != m.second) {
                        st.push({a, m.first});
                    }
                }
                st.push({m.first, -1});
            }
        }

        return (res);
    }
    
    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        colorArr.assign(size + 1, -1);
        adj.resize(n + 1);
    }
};


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    Graph gr(n);


    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        gr.addEdge(a, b);
        gr.addEdge(b, a);
    }

    auto X = gr.findCircule();    
    if (X.empty()) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << X.size() << '\n';
    for (int i = 0; i < X.size(); i++)
        cout << X[i] << ' ';
    cout << '\n';
}

int main()
{
		ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int size = 1;

		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);

		//cin >> size;
		for (int i = 1; i <= size; i++)
				solve(i);
}