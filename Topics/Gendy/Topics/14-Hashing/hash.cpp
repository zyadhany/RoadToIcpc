#define MOD 1000000007
const int BASE = 34;
vi power;
vi prefix_hash;
void compute_hashes(string &s) {
    ll n = s.length();
    power.resize(n + 1);
    prefix_hash.resize(n + 1);
    power[0] = 1;
    prefix_hash[0] = 0;
    for (int i = 0; i < n; i++) {
        power[i + 1] = (power[i] * BASE) % MOD;
        prefix_hash[i + 1] = (prefix_hash[i] * BASE + (s[i] - 'a' + 1)) % MOD;
    }
}

// To get the substrings equal or no
ll get_hash(ll l, ll r) {
    ll hash_value = prefix_hash[r + 1] - (prefix_hash[l] * power[r - l + 1]) % MOD;
    if (hash_value < 0) hash_value += MOD;
    return hash_value;
}