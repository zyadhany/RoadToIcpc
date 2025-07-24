// #pragma GCC optimize("Ofast,fast-math,unroll-loops")
// #pragma GCC target("avx2,fma")
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

	int ckmin(int &a, int b) { return a > b ? ((a = b), true) : false; }

/**
 * @return the jobs of each worker in the optimal assignment,
 * or -1 if the worker is not assigned
 */
template <class T> vector<int> hungarian(const vector<vector<T>> &C) {
	int J = C.size();
	int W = C[0].size();
	assert(J <= W);

	// job[w] = job assigned to w-th worker, or -1 if no job assigned
	// note: a W-th worker was added for convenience
	vector<int> job(W + 1, -1);
	vector<T> h(W);  // Johnson potentials

	const T inf = numeric_limits<T>::max();
	// assign j_cur-th job using Dijkstra with potentials
	for (int j_cur = 0; j_cur < J; j_cur++) {
		int w_cur = W;  // unvisited worker with minimum distance
		job[w_cur] = j_cur;

		vector<T> dist(W + 1, inf);  // Johnson-reduced distances
		dist[W] = 0;
		vector<bool> vis(W + 1);     // whether visited yet
		vector<int> prv(W + 1, -1);  // previous worker on shortest path
		while (job[w_cur] != -1) {   // Dijkstra step: pop min worker from heap
			T min_dist = inf;
			vis[w_cur] = true;
			int w_next = -1;  // next unvisited worker with minimum distance

			// consider extending shortest path by w_cur -> job[w_cur] -> w
			for (int w = 0; w < W; w++) {
				if (!vis[w]) {
					// sum of reduced edge weights w_cur -> job[w_cur] -> w
					T edge = C[job[w_cur]][w] - h[w];
					if (w_cur != W) {
						edge -= C[job[w_cur]][w_cur] - h[w_cur];
						assert(edge >= 0);
					}
					if (ckmin(dist[w], dist[w_cur] + edge)) { prv[w] = w_cur; }
					if (ckmin(min_dist, dist[w])) { w_next = w; }
				}
			}
			w_cur = w_next;
		}

		for (int w = 0; w < W; w++) {  // update potentials
			ckmin(dist[w], dist[w_cur]);
			h[w] += dist[w];
		}

		while (w_cur != W) {  // update job assignment
			job[w_cur] = job[prv[w_cur]];
			w_cur = prv[w_cur];
		}
	}

	return job;
}

void solve(int tc) {
    ll n;
    cin >> n;

    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            cin >> C[i][j];
        }
    }

    auto res = hungarian(C);
    ll summ = 0;
    for (int i = 0; i < n; i++)
    {
        summ += C[res[i]][i];
    }
    
    cout << summ << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << res[i] + 1 << ' ' << i + 1 << '\n';
    }
}

int main()  
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("piscine.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // INIT();
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
