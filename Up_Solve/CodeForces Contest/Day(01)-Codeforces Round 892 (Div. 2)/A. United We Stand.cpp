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
    we need to get to but the smallest element in first array,
    al the other element in second.

    if that way all the element in second array will be bigger than first,
    so no element will be devisor for it.
*/
void solve(int tc) {
    int n, at = 0;

    cin >> n;

    vi X(n);


    for (int i = 0; i < n; i++)
        cin >> X[i];
    sortx(X);

    /*
        if all elements are equal
        there is no solution
    */
    if (X[0] == X.back())
    {
        cout << "-1\n";
        return;
    }

    //making pointer to first element great than smallest element.
    while (X[at] == X[0])
        at++;

    /*
        makking all the element before pointer in first arr,
        and all other in second.
    */
    cout << at << ' ' << n - at << "\n";
    for (int i = 0; i < at; i++)
        cout << X[i] << ' ';
    cout << "\n";
    for (int i = at; i < n; i++)
        cout << X[i] << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}