#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll int
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
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
using namespace std;
 
const int MODE = 1e9+7;

struct Matrix {
    ll a[2][2];
    Matrix() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }
    Matrix operator*(const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MODE;
                }
            }
        }
        return c;
    }
};

ll modinv(ll x) {
    ll res = 1, y = MODE - 2;
    while (y) {
        if (y & 1) res = (1LL * res * x) % MODE;
        x = (1LL * x * x) % MODE;
        y >>= 1;
    }
    return res;
}

Matrix inverse(Matrix A) {
    Matrix B;
    ll a = A.a[0][0], b = A.a[0][1], c = A.a[1][0], d = A.a[1][1];
    ll det = (1LL * a * d - 1LL * b * c + MODE) % MODE;
    ll inv_det = modinv(det);

    B.a[0][0] = 1LL * d * inv_det % MODE;
    B.a[0][1] = (MODE - 1LL * b % MODE) * inv_det % MODE;
    B.a[1][0] = (MODE - 1LL * c % MODE) * inv_det % MODE;
    B.a[1][1] = 1LL * a * inv_det % MODE;

    return B;
}



void solve(int tc) {
    ll n, k
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[],
               int final_height[]) {
	Segtree st(n);
	for (int i = 0; i < k; i++) {
		if (op[i] == 1) {
			st.update(left[i], right[i], {height[i], INT_MAX});
		} else {
			st.update(left[i], right[i], {0, height[i]});
		}
	}
	for (int i = 0; i < n; i++) { final_height[i] = st.get(i).min_val; }
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}
