#include <bits/stdc++.h>
#include <unordered_map>
#include "testlib.h"
 
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
 
using namespace std;
 
int MAXN = 1e5, MAXQ = 1e5;
int N, Q, ml, mr, TEST;
 
void writeTest(int test) {
 
    int n, q, m, l, r;	
    bool ch = 0;
 
 
    n = N;
    q = Q;
    
    cout << n << ' ' << q << endl;
 
    for (int i = 1; i <= n; i++)
    {
        m = rnd.next(ml, mr);
        cout << m;
        if (i != n) cout << ' ';
    }
    cout << endl;
 
    while (q--)
    {
        m = rnd.next(1, 2);
 
        if (q == 1 && !ch) m = 2;
        if (m == 2) ch = 1;
 
        cout << m << ' ';
 
        if (m == 1){
            r = rnd.next(ml, mr);
            cout << rnd.next(1, n) << ' ' << r << endl;
        }else {
            l = rnd.next(ml, mr);
            r = rnd.next(l, mr);
            cout << l << ' ' << r << endl;
        }
    }
}
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
 
    N = opt<int>("mxn");
    Q = opt<int>("mxq");
    TEST = opt<int>("test");
    ml = opt<int>("ml");
    mr = opt<int>("mr");
 
    if (!TEST) TEST = rnd.next(1, 10'000);
    cout << TEST << endl;
 
    for (int i = 1; i <= TEST; i++)
        writeTest(i);
}
 
/*
<#list 1..40 as i >
     igen --minn 1 --maxx 1000000 ${i} > $ 
</#list>
*/
