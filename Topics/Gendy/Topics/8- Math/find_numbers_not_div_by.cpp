// number or element nor div by any element in ar

ll ar[5]; // array of the numbers
ll go(ll id, ll cnt, ll me, ll upto){
    if (id == 5){  // +even , -odd
        if (cnt % 2) return - me / upto;
        else return me / upto;
    }
    ll ret = 0;
    ret += go(id + 1, cnt + 1, me, lcm(upto, ar[id]));
    ret += go(id + 1, cnt, me, upto);
    return ret;
}

void solve(ll test) {

    ll n,m,a,d;
    cin >> n >> m >> a >> d;
    ar[0] = a;
    ar[1] = a + d;
    ar[2] = a + 2 * d;
    ar[3] = a + 3 * d;
    ar[4] = a + 4 * d;

    cout << go(0, 0, m, 1) - go(0, 0, n - 1, 1) << "\n";

}


