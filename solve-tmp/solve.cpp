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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

int longestCycleLength = -1;

// Helper function to perform DFS
void dfs(int node, const vector<vector<int>> &adj, vector<int> &visited, vector<int> &recStack, vector<int> &entryTime, int currentTime) {
    visited[node] = 1;        // Mark as visiting
    recStack[node] = currentTime; // Track entry time
    entryTime[node] = currentTime;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, recStack, entryTime, currentTime + 1);
        } else if (recStack[neighbor] != -1) { // Found a back edge
            longestCycleLength = max(longestCycleLength, currentTime - recStack[neighbor] + 1);
        }
    }

    recStack[node] = -1; // Mark as no longer in the stack
}

// Function to find the longest cycle in a directed graph
int findLongestCycle(int n, const vector<vector<int>> &adj) {
    vector<int> visited(n, 0);
    vector<int> recStack(n, -1); // Tracks entry times for nodes in the recursion stack
    vector<int> entryTime(n, -1);
    longestCycleLength = -1;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, recStack, entryTime, 0);
        }
    }

    return longestCycleLength;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (i & (1 << j) && i ^ (1 << j)) {
                adj[i].push_back(i ^ (1 << j));
                adj[i ^ (1 << j)].push_back(i);
            }
        }
    }

    
    
    cout << findLongestCycle(n, adj) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
