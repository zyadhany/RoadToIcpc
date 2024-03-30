#include <bits/stdc++.h>
#include <unordered_map>
#include "testlib.h"
#include <random>
#include <vector>
#include <algorithm>

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

    int n, k, m, sol;	
    n = rnd.next(1, 1000);
    sol = rnd.next(1, 2);
    cout << n << endl;

    vi X(n);
    
    if (sol == 1){
        for (int i = 1; i <= n; i++)
        {
            X[i - 1] = i;
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(X.begin(), X.end(), gen);
    }
    else {
        for (int i = 1; i <= n; i++)
        {
            X[i - 1] = rnd.next(1, 1000);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << X[i - 1];
        if (i != n) cout << ' ';
    }

    cout << endl;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int TEST = rnd.next(1, 10'000);
    TEST = 1;
    //cout << TEST << endl;

    for (int i = 1; i <= TEST; i++)
        writeTest(i);
}

/*

*/