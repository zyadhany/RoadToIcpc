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


const ll mode = 3 * 1e6;

using namespace std;

void FP()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

/*
I made function to get all sequance and get the pattern
you can use it to get the patter and fin way


void solve() {
    ll n = 11, mx = 0, summ, re;

    vi X(n);
    vii Z;

    for (int i = 0; i < n; i++)
    {
        X[i] = i + 1;
    }

    do
    {
        summ = re = 0;

        for (int i = 0; i < n; i++)
        {
            summ += (i + 1) * X[i];
            re = max(re, (i + 1) * X[i]);
        }
        summ -= re;

        if (mx < summ)
        {
            mx = summ;
            Z.clear();
            Z.push_back(X);
        }
        else if (mx == summ) Z.push_back(X);

    } while (next_permutation(X.begin(), X.end()));


    cout << mx << "\n";

    for (int i = 0; i < Z.size(); i++)
    {
        for (int j = 0; j < Z[i].size(); j++)
        {
            cout << Z[i][j] << ' ';
        }cout << "\n";
    }
}


*/
void solve(int tc) {
    int n, mx = 0, summ, at, re;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        at = 1;
        summ = 0;
        re = 0;

        for (int j = 1; j < i; j++)
            summ += (j * at), re = max(re, j * at++);
        for (int j = n; j >= i; j--)
            summ += (j * at), re = max(re, j * at++);

        mx = max(mx, summ - re);
    }

    cout << mx << "\n";
}

int main()
{
    FP();
    int size = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}