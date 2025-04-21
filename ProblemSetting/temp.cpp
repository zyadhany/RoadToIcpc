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

ll n = 1, l = 2;
void writeTest(int test) {
    cout << n << ' ' << l << '\n';
    l += n/60;
    n%=60;
    n++;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int TEST = 1;
    TEST = 10'000;
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