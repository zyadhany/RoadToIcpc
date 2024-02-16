#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) (X.begin(),X.end());
#define ln '\n'


using namespace std;


void FP()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

/*
    we can look to it in gready way.
    
    we dont really need to work in all the element of the array
    ,only first 2 smallest element what we need to know.

    first we can sort array and work from there.

    if we need to make maximum value of an array we can get it's second element.

    to solve it we can will take summ of secont element of all arrays exepect the mimum one
    , we will remove smallest elem of all arrays and put it there then add it to our summ,
*/
void solve(int tc) {
    ll n, m, summ = 0, l = INT32_MAX, r = INT32_MAX;

    cin >> n;

    vii X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        X[i].resize(m);

        for (int j = 0; j < m; j++)
            cin >> X[i][j];
        sortx(X[i]);

        summ += X[i][1];
        // min element over all the arrays
        l = min(l, X[i][0]);
        // min second element.
        r = min(r, X[i][1]);
    }

    cout << summ + l - r << "\n";
}

int main()
{
    FP();
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}