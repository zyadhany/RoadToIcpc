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

    int n, k, m;	
    int maxx = opt<int>("maxx");
    n = rnd.next(1, 100'000);
    k = rnd.next(1, 1000'000'000);
    
    cout << n << ' ' << k << endl;

    for (int i = 1; i <= n; i++)
    {
        m = rnd.next(1, 1000'000'000);
        cout << m;
        if (i != n) cout << ' ';
    }

    cout << endl;
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