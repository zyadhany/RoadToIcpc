/*
===============================================================================
                    LAGRANGE INTERPOLATION - CP REFERENCE
===============================================================================

1. CORE FORMULA:
   Given k points (x_0, y_0), (x_1, y_1), ..., (x_{k-1}, y_{k-1}) with distinct x_i:
   Unique polynomial P(x) of degree <= k - 1:
   
   P(x) = sum_{i=0}^{k-1} y_i * L_i(x)
   where L_i(x) = prod_{j != i} (x - x_j) / (x_i - x_j)

2. CP TRICKS & PROPERTIES:

   [A] WHEN TO INTERPOLATE:
       - Sum of powers: S_d(n) = sum_{i=1}^n i^d is a polynomial in n of degree d + 1.
         -> Requires (d + 2) points. Evaluate at n = 0, 1, ..., d + 1, then interpolate.
       - DP / Grid paths where states grow as degree D polynomial.
         -> Evaluate first D + 1 points, then interpolate for large N.

   [B] LEADING COEFFICIENT (x^{k-1}):
       coef[x^{k-1}] = sum_{i=0}^{k-1} ( y_i / prod_{j != i} (x_i - x_j) )

       For contiguous points x_i = i (0 <= i < k):
       coef[x^{k-1}] = sum_{i=0}^{k-1} ( y_i / ( i! * (-1)^{k-1-i} * (k-1-i)! ) )

   [C] SUB-LEADING COEFFICIENT (x^{k-2}):
       Let S = sum_{m=0}^{k-1} x_m.
       coef[x^{k-2}] = sum_{i=0}^{k-1} ( y_i * (x_i - S) / prod_{j != i} (x_i - x_j) )

   [D] CONSTANT TERM (x^0 = P(0)):
       P(0) = sum_{i=0}^{k-1} y_i * prod_{j != i} ( -x_j / (x_i - x_j) )
       (If x_i = 0, 1, ..., k-1, then P(0) is simply y_0).

   [E] EXTRACT ALL COEFFICIENTS in O(k^2):
       1. Compute L(x) = prod_{j=0}^{k-1} (x - x_j) of degree k in O(k^2).
       2. For each point i, compute Q_i(x) = L(x) / (x - x_i) in O(k) via synthetic division.
       3. Scale Q_i(x) by y_i / prod_{j != i} (x_i - x_j) and accumulate.

3. COMPLEXITY:
   - General evaluation P(x): O(k^2)
   - Contiguous evaluation P(x): O(k)
   - Specific Coefficient (Leading / Sub-leading): O(k^2) general, O(k) contiguous
   - Extract All Coefficients: O(k^2)
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

ll add(ll a, ll b) { return (a + b) % MOD; }
ll sub(ll a, ll b) { return (a - b % MOD + MOD) % MOD; }
ll mul(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = mul(res, base);
        base = mul(base, base);
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

/*
===============================================================================
 BLACK BOX: lagrange_eval_general
 ------------------------------------------------------------------------------
 INPUT : vector<pair<ll, ll>> points - k arbitrary distinct points (x_i, y_i)
         ll x                       - target point to evaluate P(x)
 OUTPUT: ll                         - value P(x) % MOD
 TIME  : O(k^2)
 DESC  : Evaluates interpolated polynomial at point x for arbitrary x_i.
===============================================================================
*/
ll lagrange_eval_general(const vector<pair<ll, ll>>& points, ll x) {
    ll res = 0;
    int k = points.size();
    for (int i = 0; i < k; i++) {
        ll term = points[i].second % MOD;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                ll num = sub(x, points[j].first);
                ll den = sub(points[i].first, points[j].first);
                term = mul(term, mul(num, modInverse(den)));
            }
        }
        res = add(res, term);
    }
    return res;
}

/*
===============================================================================
 BLACK BOX: lagrange_eval_contiguous
 ------------------------------------------------------------------------------
 INPUT : vector<ll> y - y-coordinates corresponding to x_i = 0, 1, ..., k-1
         ll x        - target point to evaluate P(x)
 OUTPUT: ll          - value P(x) % MOD
 TIME  : O(k)
 DESC  : Fast O(k) evaluation when x-coordinates are contiguous starting at 0.
===============================================================================
*/
ll lagrange_eval_contiguous(const vector<ll>& y, ll x) {
    int k = y.size();
    if (x < k && x >= 0) return (y[x] % MOD + MOD) % MOD;

    vector<ll> pref(k), suff(k);
    pref[0] = sub(x, 0);
    for (int i = 1; i < k; i++) pref[i] = mul(pref[i - 1], sub(x, i));

    suff[k - 1] = sub(x, k - 1);
    for (int i = k - 2; i >= 0; i--) suff[i] = mul(suff[i + 1], sub(x, i));

    vector<ll> fact(k);
    fact[0] = 1;
    for (int i = 1; i < k; i++) fact[i] = mul(fact[i - 1], i);

    ll res = 0;
    for (int i = 0; i < k; i++) {
        ll num = 1;
        if (i > 0) num = mul(num, pref[i - 1]);
        if (i < k - 1) num = mul(num, suff[i + 1]);

        ll den = mul(fact[i], fact[k - 1 - i]);
        ll term = mul(y[i] % MOD, mul(num, modInverse(den)));

        if ((k - 1 - i) % 2 == 1) term = sub(0, term);
        res = add(res, term);
    }
    return res;
}

/*
===============================================================================
 BLACK BOX: get_leading_coefficient
 ------------------------------------------------------------------------------
 INPUT : vector<pair<ll, ll>> points - k arbitrary points (x_i, y_i)
 OUTPUT: ll                         - coefficient of x^{k-1} in P(x) % MOD
 TIME  : O(k^2)
 DESC  : Computes leading coefficient of the degree (k-1) polynomial.
===============================================================================
*/
ll get_leading_coefficient(const vector<pair<ll, ll>>& points) {
    ll coef = 0;
    int k = points.size();
    for (int i = 0; i < k; i++) {
        ll den = 1;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                den = mul(den, sub(points[i].first, points[j].first));
            }
        }
        ll term = mul(points[i].second % MOD, modInverse(den));
        coef = add(coef, term);
    }
    return coef;
}

/*
===============================================================================
 BLACK BOX: get_subleading_coefficient
 ------------------------------------------------------------------------------
 INPUT : vector<pair<ll, ll>> points - k arbitrary points (x_i, y_i)
 OUTPUT: ll                         - coefficient of x^{k-2} in P(x) % MOD
 TIME  : O(k^2)
 DESC  : Computes second leading coefficient of the polynomial.
===============================================================================
*/
ll get_subleading_coefficient(const vector<pair<ll, ll>>& points) {
    ll coef = 0;
    int k = points.size();
    
    ll S = 0;
    for (int i = 0; i < k; i++) S = add(S, points[i].first);

    for (int i = 0; i < k; i++) {
        ll den = 1;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                den = mul(den, sub(points[i].first, points[j].first));
            }
        }
        ll num = mul(points[i].second % MOD, sub(points[i].first, S));
        ll term = mul(num, modInverse(den));
        coef = add(coef, term);
    }
    return coef;
}

/*
===============================================================================
 BLACK BOX: get_all_coefficients
 ------------------------------------------------------------------------------
 INPUT : vector<pair<ll, ll>> points - k arbitrary points (x_i, y_i)
 OUTPUT: vector<ll> c               - c[i] is coefficient of x^i in P(x) % MOD
 TIME  : O(k^2)
 DESC  : Recovers explicit polynomial coefficients c_0 + c_1 x + ... + c_{k-1} x^{k-1}.
===============================================================================
*/
vector<ll> get_all_coefficients(const vector<pair<ll, ll>>& points) {
    int k = points.size();
    
    // 1. Compute L(x) = prod_{j=0}^{k-1} (x - x_j) of degree k
    vector<ll> L(k + 1, 0);
    L[0] = 1;
    for (int i = 0; i < k; i++) {
        ll xi = points[i].first % MOD;
        for (int j = i + 1; j >= 1; j--) {
            L[j] = sub(L[j - 1], mul(L[j], xi));
        }
        L[0] = sub(0, mul(L[0], xi));
    }

    vector<ll> P(k, 0);

    // 2. For each point i, compute Q_i(x) = L(x) / (x - x_i) using synthetic division
    for (int i = 0; i < k; i++) {
        ll xi = points[i].first % MOD;
        ll yi = points[i].second % MOD;

        ll den = 1;
        for (int j = 0; j < k; j++) {
            if (i != j) den = mul(den, sub(points[i].first, points[j].first));
        }
        ll scale = mul(yi, modInverse(den));

        // Synthetic division: Q[k-1] = L[k], Q[r] = L[r+1] + xi * Q[r+1]
        vector<ll> Q(k, 0);
        Q[k - 1] = L[k];
        for (int r = k - 2; r >= 0; r--) {
            Q[r] = add(L[r + 1], mul(xi, Q[r + 1]));
        }

        // Accumulate scale * Q(x) into P(x)
        for (int r = 0; r < k; r++) {
            P[r] = add(P[r], mul(scale, Q[r]));
        }
    }

    return P;
}