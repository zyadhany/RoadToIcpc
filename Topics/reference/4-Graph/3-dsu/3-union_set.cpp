const int MXN = 1e6 + 1;
int PAR[MXN];
vector<set<ll>> ST(MXN);
 
ll get(ll k) {
    if (k == PAR[k]) return k;
    return PAR[k] = get(PAR[k]);
}
 
void add(ll u, ll v) {
    u = get(u), v = get(v);
    
    if (u == v) return;
    
    if (ST[u].size() < ST[v].size()) swap(u, v);
        
    for (auto a : ST[v]) ST[u].insert(a);
    PAR[v] = u;
}
 
void INIT() {
    for (int i = 0; i < MXN; i++) {
        PAR[i] = i;
    } 
}
 