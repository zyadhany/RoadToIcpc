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

/*
    for each value of a_i we add greatest a_i elements to our summ.
*/
void solve(int tc) {
    ll n, a, b, summ = 0;

    cin >> n;

    vii X(n + 1);

    // 2d array so i can put all the elements of value a together.
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        X[a].push_back(b);
    }

    for (int i = 0; i <= n; i++)
    {
        //sort array so the greatest elements be at begining.
        sort(X[i].rbegin(), X[i].rend());
        //add greates i elements to summ
        for (int j = 0; j < i && j < X[i].size(); j++)
            summ += X[i][j];
    }

    cout << summ << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}