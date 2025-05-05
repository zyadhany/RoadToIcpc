
const int special_mod = 998244353, primitive_root = 3, lim = 64;
int mod_exp(int b, int e, ll m)
{
    int res = 1;
    for(; e; b = (ll) b * b % m, e /= 2) if(e & 1) res = (ll) res * b % m;
    return res;
}

int mod_div_2(int x)
{
    if(x >= special_mod) x -= special_mod;
    if(x & 1) x += special_mod;
    return x/2;
}

vector < int > mod_poly(vector < int > &a, int x)
{
    int n = a.size();
    int c = mod_exp(primitive_root, x, special_mod);

    vector < int > out(n/2);
    for(int i = 0; i < n/2; i++)  out[i] = (a[i] + (ll) c * a[i + n/2]) % special_mod;

    return out;
}

pair < vector < int >, vector < int > > mod_poly2(vector < int > &a, int x)
{
    int n = a.size();
    int c = mod_exp(primitive_root, x, special_mod);

    vector < int > a_minus(n/2), a_plus(n/2);

    for(int i = 0; i < n/2; i++)
    {
        int tmp = (ll) c * a[i + n / 2] % special_mod;
        int m = a[i] + tmp;
        a_minus[i] = (m >= special_mod ? m - special_mod : m);
        int p = a[i] - tmp;
        a_plus[i] = (p < 0 ? p + special_mod : p);
    }

    return {a_minus, a_plus};
}


vector < int > fast_ntt_poly_mul(vector < int > &a, vector < int> &b, int x)
{
    int n = a.size();

    if((n <= lim) || (n & 1))
    {
        vector <unsigned ll> ans2(2*n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++) ans2[i + j] += (ll) a[i] * b[j];

            if((i & 15) == 15) for(int j = i + 1; j < i + n; j++) ans2[j] %= special_mod;
        }

        vector < int > ans(n);
        int c = mod_exp(primitive_root, x, special_mod);
        for(int i = 0; i < n; i++) ans[i] = (ans2[i] + c * (ans2[i + n] % special_mod)) % special_mod;

        return ans;
    }

    int x1 = x/2;
    int x2 = (x1 + special_mod/2) % (special_mod - 1);

    vector < int > ans_minus, ans_plus;

    {
        auto [a_minus, a_plus] = mod_poly2(a, x1);
        auto [b_minus, b_plus] = mod_poly2(b, x1);
        ans_minus = fast_ntt_poly_mul(a_minus, b_minus, x1);
        ans_plus = fast_ntt_poly_mul(a_plus, b_plus, x2);
    }

    int sqrtc_inv = mod_exp(primitive_root, special_mod - 1 - x1, special_mod);
    int two_sqrtc_inv = mod_div_2(sqrtc_inv);

    vector < int > ans(n);
    for(int i = 0; i < n/2; i++) ans[i] = mod_div_2(ans_minus[i] + ans_plus[i]);
    for(int i = 0; i < n/2; i++) ans[i + n/2] = (ll) (ans_minus[i] - ans_plus[i] + special_mod) * two_sqrtc_inv % special_mod;

    return ans;
}

vector < int > fast_ntt_poly_mul(vector < int > &a, vector < int > &b)
{
    int n1 = a.size(), n2 = b.size();
    int len = n1 + n2 - 1;
    int x = 1;
    while((lim << x) < len) ++x;
    int y = ((len - 1) >> x) + 1;
    int n = (y << x);
    a.resize(n); b.resize(n);
    vector < int > ans = fast_ntt_poly_mul(a, b, 0);
    a.resize(n1); b.resize(n2); ans.resize(len);
    return ans;
}
