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
    we can build array from end to begin.
    
    if we need to make {1, 1, 1, 0}, we need to at 3 zeroes at pos_0 then add zero at pos_3,
    it will reverse all previos so it wil be like that {0, 0, 0, 3}.

    if the array is big we can seprate it to several ones and zeros like that.
    {1, 0, 1, 1, 0, 0, 1, 0} ->> 
    {1, 0},
    {1, 1, 0},
    {0},
    {1, 0}
    solution for each part will zeros and last element will be number of ones in array,
    after getting sol we can put it in reverse order.
    
*/
void solve(int tc) {
    ll n, at = 0, re;
    
    cin >> n;

    vi X(n + 1), sol(n);

    for (int i = 1; i <= n; i++)
        cin >> X[i];

    // if last element is 1, no solution.
    if (X[n] == 1) {
        cout << "NO\n";
        return;
    }

    for (int i = n; i > 0; i--)
    {
        re = 0;
        while (X[i - 1])
            re++, i--;
        sol[at + re] = re;
        at += re + 1;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << sol[i] << " ";
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}