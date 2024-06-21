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

    bool isBipartite(int src)
    {   
        int m;
        stack<int> st;
        st.push(src);
        
        if (colorArr[src] != -1) return(true);
        colorArr[src] = 0;

        while (!st.empty())
        {
            m = st.top();
            st.pop(); 
    
            for (auto neg : adj[m])
            {
                if (colorArr[neg] == colorArr[m]) return (false);
                if (colorArr[neg] == -1)
                {
                    colorArr[neg] = (1 ^ colorArr[m]);
                    st.push(neg);
                }
            }
        }

        return (true);
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
    
    
    for (int i = 1; i <= n; i++)
        if (!gr.isBipartite(i)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    for (int i = 1; i <= n; i++)
        cout << gr.colorArr[i] + 1 << ' ';
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
