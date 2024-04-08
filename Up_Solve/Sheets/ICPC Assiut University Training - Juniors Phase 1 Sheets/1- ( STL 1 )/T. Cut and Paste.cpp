#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

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
#define YES {cout << "Valid\n"; return;}
#define NO {cout << "Invalid\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;



void solve(int tc) {
    ll n, k, summ, is;
    string s, t;

    cin >> k >> s;

    is = 0;
    n = summ = s.size();

    for (int i = 0; i < k; i++)
    {
        if (summ < k && !is){
            t = s.substr(i + 1, -1);
            for (int j = 1; j < s[i] - '0'; j++)
            {
                s += t;
            }
            
        }else is = 1;

        summ += (s[i] - '0' - 1) * ((summ - i - 1 + MODE) % MODE);
        summ %= MODE;
    }
    
    cout << summ % MODE << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
