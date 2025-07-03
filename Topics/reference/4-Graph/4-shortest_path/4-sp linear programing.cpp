/*
We can use spfa to solve some linear programming problems.
for array A we need some condtions in term of A[j] - A[i] <= w
for that we add edge from i to j with weight w.

if there is negative cycle in the graph, the there is no solution.
otherwise we use spfa from the source node to find the value of array. it gives us the max value
*/

/*
ID: USACO_template
LANG: C++
PROG: https://oj.uz/problem/view/RMI19_restore
*/
#include <iostream>  //cin , cout
#include <fstream>   //fin, fout
#include <stdio.h>   // scanf , pringf
#include <cstdio>
#include <algorithm> // sort , stuff
#include <stack>     // stacks
#include <queue>     // queues
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <assert.h>     /* assert */


using namespace std;

typedef pair<int, int>          pii;
typedef vector<int>             vi;     /// adjlist without weight
typedef vector<pii>             vii;    /// adjlist with weight
typedef vector<pair<int,pii>>   vpip;   /// edge with weight
typedef long long               ll;

#define mp  make_pair
#define ff  first
#define ss  second
#define pb  push_back
#define sz(x)   (int)(x).size()

const int MOD = 1e9+7;  // 998244353;
const int MX  = 2e5+5;   //
const ll  INF = 1e18;    //

#define MAXV 5007
#define MAXE 100007


bool debug;

int N, M;
vii adjlist[MAXV];
int useNode[MAXV];
int dist[MAXV], cnt[MAXV], inq[MAXV];

bool spfa(int s) {  /// Shortest Path Faster Algorithm
    for(int i=0; i<N; i++) {
        dist[i] = MX;
        cnt[i] = 0; inq[i] = 0;
    }
    queue<int> q;

    dist[s] = 0;
    q.push(s); inq[s] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop(); inq[v] = 0;

        for(auto e : adjlist[v]) {
            int u = e.ff, w = e.ss;
            if(dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                if(dist[u] < 0 ) return false; /// optimization for TLE.
                if(!inq[u]) {
                    q.push(u); inq[u] = 1;
                    cnt[u]++;
                    if(cnt[u]>N) return false;
                }
            }
        }
    }

    return true;
}

int main() {
    debug = false;
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;

    /// solve linear inequality function using negative weight SSSP approach
    for(int i=0;i<M; i++) {
        int l, r, k, val; cin >> l >> r >> k >> val;
        /// xi is number of 1 from 0 to i
        l++; r++;
        if(val == 1) {
            /// k-th smallest is 1, i.e. # of 0 < k
            /// (r-l+1) - (x[r] - x[l-1]) < k, i.e. x[l-1] - x[r] <= -(r-l+1) + k -1
            adjlist[r].pb(mp(l-1, -(r-l+1) + k -1));
            if(debug) cout << r << "->" << l-1 << " = " << -(r-l+1) + k -1 << endl;
        } else {
            /// k-th smallest is 0, i.e. # of 0 >= k
            /// (r-l+1) - (x[r] - x[l-1]) >= k, i.e. x[r] - x[l-1] <= (r-l+1)-k
            adjlist[l-1].pb(mp(r, (r-l+1)-k));
            if(debug) cout << l-1 << "->" << r << " = " << k -1 << endl;
        }
    }
    /// restriction: the increase from x[i-1] to x[i] is either 0 or 1
    for(int i=1; i<=N; i++) {
        /// x[i] - x[i-1] <=1
        adjlist[i-1].pb(mp(i, 1));
        /// x[i] - x[i-1] >=0, i.e. x[i-1] - x[i] <=0
        adjlist[i].pb(mp(i-1, 0));
    }
    N++;

    /// SPFA
    if(!spfa(0)) {
        cout << -1 << endl;
        if(debug) {
            cout << endl;
            for(int i=1; i<N; i++) cout << dist[i] << endl;
        }
        exit(0);
    }

    /// output a possible solution which is the distance from source s
    for(int i=1; i<N; i++) {
        if(dist[i] > dist[i-1]) cout << 1;
        else cout << 0;
        cout << " ";
    }
    cout << endl;

    if(debug) cout << endl << "EOL" << endl;

}

/**
4 5
0 1 2 1
0 2 2 0
2 2 1 0
0 1 1 0
1 2 1 0
*/
