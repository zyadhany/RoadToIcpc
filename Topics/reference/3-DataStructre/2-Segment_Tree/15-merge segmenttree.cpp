struct node {
    int val = 0;
    node *l, *r;
    node(){
        l = r = NULL;
        val = 0;
    }
};
ll sol = 0, c;

ll getval(node *nd) {
    if (!nd) return 0;
    return nd->val;
}
node *update(node *nd, ll lx, ll rx, ll ind, ll val) {
    if (!nd) {
        nd = new node();
    }
    if (lx == rx) {
        nd->val = val;
        return nd;
    }
    ll mid = (lx + rx) / 2;
    if (ind <= mid) nd->l = update(nd->l, lx, mid, ind, val);
    else nd->r = update(nd->r, mid+1, rx, ind, val);
    nd->val = getval(nd->l) + getval(nd->r);
    return nd;
}

void clc(node *nd) {
    if (nd) {
        clc(nd->l);
        clc(nd->r);
        delete nd;
    }
}

node *sgmerge(node *nd1, node *nd2) {
    if (!nd1) return nd2;
    if (!nd2) return nd1;
    c += getval(nd1->l) * getval(nd2->r);
    nd1->val += nd2->val;
    nd1->l = sgmerge(nd1->l, nd2->l);
    nd1->r = sgmerge(nd1->r, nd2->r);
    delete nd2;
    return nd1;
}

ll sgsize;
node *take() {
    ll x ; cin >> x;
    if (x) {
        return update(NULL, 0, sgsize, x, 1);
    }
    node * l = take();
    node *r = take();
    c = 0;
    ll sz = l->val;
    sz *= r->val;
    node *n = sgmerge(l, r);
    sol += min(c, sz-c);
    return n;
}

void solve() {
    ll n;
    cin >> n;   
    sgsize = n; 
    node *root = take(); 
    clc(root);
    cout << sol << '\n';
}
