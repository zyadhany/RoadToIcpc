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

int M;

void writeTest(int test) {

    int n, k, m;	
    n = rnd.next(1, 1000'000);
    m = M;
    
    cout << n << ' ' << m << endl;

    for (int i = 1; i <= m; i++)
    {
        m = rnd.wnext(1, n, -5);
        cout << m;
        if (i != n) cout << ' ';
    }

    cout << endl;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int TEST = 1;
    TEST = rnd.next(1, 10'000);
    // M = opt<int>("m");
    // TEST = 100, 1000 / M;
    
    cout << TEST << '\n';
    for (int i = 1; i <= TEST; i++)
        writeTest(i);
}

/*
<#list 1..10 as i >
     igen --m 10 ${i} > $ 
</#list>
*/