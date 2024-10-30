#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>
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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 998244353;

using namespace std;


// Helper function to add two numeric strings
string addStrings(const string &num1, const string &num2) {
    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
    string result;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry + (i >= 0 ? num1[i--] - '0' : 0) + (j >= 0 ? num2[j--] - '0' : 0);
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Karatsuba multiplication for large numbers
string karatsuba(const string &x, const string &y) {
    int n = max(x.size(), y.size());

    // Base case for single-digit multiplication
    if (n == 1) return to_string((x[0] - '0') * (y[0] - '0'));

    // Pad numbers to be the same length by making them even-length strings
    int half = n / 2;
    string x1 = x.substr(0, x.size() - half);
    string x0 = x.substr(x.size() - half);
    string y1 = y.substr(0, y.size() - half);
    string y0 = y.substr(y.size() - half);

    // Recursive calls
    string z2 = karatsuba(x1, y1);
    string z0 = karatsuba(x0, y0);
    string z1 = karatsuba(addStrings(x1, x0), addStrings(y1, y0));

    // Calculate result: z2 * 10^(2*half) + (z1 - z2 - z0) * 10^half + z0
    string result = addStrings(z2 + string(2 * half, '0'), 
                    addStrings(z1 + string(half, '0'), z0));

    return result;
}


void solve(int tc) {

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
