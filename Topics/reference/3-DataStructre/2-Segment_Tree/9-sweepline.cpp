 
struct query
{
    ll l, r, x, ty;
    query(){}
    query(ll la, ll ra, ll xa, ll tya) {
        l = la;
        r = ra;
        x = xa;
        ty = tya;
    }
    bool operator<(const query& q) {
        if (x != q.x) return x < q.x;
        return ty < q.ty;
    }
};
 
void solve(int tc) {
    ll n;
 
    cin >> n;
 
    vector<query> Q;
    for (int i = 0; i < n; i++)
    {
        ll x1, x2, y1, y2;
 
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) {
            Q.push_back(query(y1, y2, x1, 0));
            Q.push_back(query(y1, y2, x2, 2));
        } else Q.push_back(query(y1, y2, x1, 1));
    }
    sortx(Q);
 
    SegmentTree sg;
    sg.build(MXN);
    ll sol = 0;
 
    for (auto q : Q) {
        if (q.ty == 0) {
            sg.set(BS+q.l, 1);
        } else if (q.ty == 1) {
            sol += sg.getrange(q.l+BS, q.r+BS);
        } else {
            sg.set(BS+q.l, -1);
        }
    } 
}
 