// CHT, O(n)
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int N = 3005;
 
int ps[N], pp[N];
int dp1[N][N], dp2[N][N];
 
struct line {
    int m, n;
    line(int m, int n) {
        this->m = m;
        this->n = n;
    }
    int eval(int x) {
        return m*x+n;
    }
    long double intX(line l) {
        return (long double)(l.n-n)/(m-l.m);
    }
};
 
deque<line> cht1[N], cht2[N]; 
 
signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ///
    int n, K;
    cin >> n >> K;
    ps[0] = pp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int ai;
        cin >> ai;
        ps[i] = ps[i-1]+ai;
        pp[i] = pp[i-1]+ai*i;
    }
    dp2[0][0] = 0;
    cht1[1].push_back(line(0, 0));
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= K; ++k) {
            { // dp1
                while (cht1[k].size() >= 2 && cht1[k][cht1[k].size()-1].eval(i) >= cht1[k][cht1[k].size()-2].eval(i)) {
                    cht1[k].pop_back();
                }
                dp1[k][i] = i*ps[i]-pp[i]+cht1[k][cht1[k].size()-1].eval(i);
                line l = line(-i, i*ps[i]-pp[i]+dp1[k][i]);
                while (cht2[k].size() >= 2 && cht2[k][0].intX(l) <= cht2[k][1].intX(l)) {
                    cht2[k].pop_front();
                }
                cht2[k].push_front(l);
            }
            { // dp2
                while (cht2[k].size() >= 2 && cht2[k][cht2[k].size()-1].eval(ps[i]) >= cht2[k][cht2[k].size()-2].eval(ps[i])) {
                    cht2[k].pop_back();
                }
                dp2[k][i] = pp[i]+cht2[k][cht2[k].size()-1].eval(ps[i]);
                line l = line(-ps[i], pp[i]+dp2[k][i]);
                while (cht1[k+1].size() >= 2 && cht1[k+1][0].intX(l) <= cht1[k+1][1].intX(l)) {
                    cht1[k+1].pop_front();
                }
                cht1[k+1].push_front(l);
            }
        }
    }
    cout << dp2[K][n] << '\n';
}
