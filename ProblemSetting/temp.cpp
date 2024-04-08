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




void writeTest(int test) {

    int n, m, q, l, r, k, L, R;	

    n = q = 100'000;

    L = 1, R = 1000'000'000;

    cout << n << endl;

    for (int i = 1; i <= n / 2; i++)
    {
        cout << R;
        if (i != n) cout << ' ';
    }
    for (int i = n / 2 + 1; i <= n; i++)
    {
        cout << R - 1;
        if (i != n) cout << ' ';
    }
    cout << endl;

    cout << q << endl;
    q--;
    cout << 1 << ' ' << n << ' ' << R << endl;
    while (q--)
    {
        l = rnd.next(1, n);
        r = rnd.next(l, n);
        k = R;

        cout << l << ' ' << r << ' ' << k << endl;
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int TEST = 1;
    //TEST = rnd.next(1, 10'000);cout << TEST << endl;

    for (int i = 1; i <= TEST; i++)
        writeTest(i);
}

/*
<#list 1..40 as i >
     igen --minn 1 --maxx 1000000 ${i} > $ 
</#list>
*/