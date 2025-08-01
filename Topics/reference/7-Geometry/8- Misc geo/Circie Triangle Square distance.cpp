#define forn(i,n) for(int i=0;i<int(n);i++)

typedef long long tint;
typedef long double tdbl;

const tdbl INF = 1e50;

struct pto
{
    tint x,y;
    pto operator+ (const pto &o) const { return {x+o.x, y+o.y}; }
    pto operator- (const pto &o) const { return {x-o.x, y-o.y}; }
    tint operator^ (const pto &o) const { return x*o.y - o.x*y; }
    pto rot90() const { return {-y,x}; }
    pto operator/ (tint k) const { assert(x%k == 0); assert(y%k == 0); return {x/k, y/k}; }
    tdbl norm() const { return hypot(x,y); }
    
    tdbl dist(const pto &a, const pto &b) const
    {
        tint A = abs((b-*this)^(a-*this));
        tdbl B = (b-a).norm();
        tdbl H = A/B, C = hypot(B, H);
        tdbl d1 = (b-*this).norm();
        tdbl d2 = (a-*this).norm();
        if(C <= d1 || C <= d2)
            return min(d1, d2);
        else
            return H;
    }
};

// BUG PARA PROBAR: No multiplicar por dos las coordenadas (ni dividir la respuesta)
// const tint KFACTOR = 1;
const tint KFACTOR = 2;
 
tint readCoord()
{
    tint x;
    cin >> x;
    return KFACTOR*x;
}
 
pto readPoint()
{
    tint x,y;
    x = readCoord();
    y = readCoord();
    return {x,y};
}

struct Circ { pto c; tint r; };
struct Quad { pto v[4]; };
struct Triangle { pto v[3]; };

Quad fromOpposites(pto a, pto c)
{
    pto mid = (a+c)/2;
    pto delta = ((c-a)/2).rot90();
    pto b = mid - delta;
    pto d = mid + delta;
    return {a,b,c,d};
}

tdbl distCircleCircle(const Circ &a, const Circ &b)
{
    return (a.c - b.c).norm() - (a.r + b.r);
}

tdbl distSegSeg(const pto &a1, const pto & a2,
                const pto &b1, const pto & b2)
{
    return min(min(a1.dist(b1,b2), a2.dist(b1,b2)),
               min(b1.dist(a1,a2), b2.dist(a1,a2)));
}

tdbl distQuadTriangle(const Quad &q, const Triangle &tri)
{
    tdbl ret = INF;
    forn(i,4)
    forn(j,3)
        ret = min(ret, distSegSeg(q.v[i], q.v[(i+1)%4], 
                                  tri.v[j], tri.v[(j+1)%3]));
    return ret;
}

tdbl distCircleQuad(const Circ &circ, const Quad &quad)
{
    tdbl ret = INF;
    forn(i,4)
        ret = min(ret, circ.c.dist(quad.v[i], quad.v[(i+1)%4]));
    return ret - circ.r;
}

tdbl distCircleTriangle(const Circ &circ, const Triangle &triangle)
{
    tdbl ret = INF;
    forn(i,3)
        ret = min(ret, circ.c.dist(triangle.v[i], triangle.v[(i+1)%3]));
    return ret - circ.r;
}


void solve() {
    ll c, q, t;
    cin >> c >> q >> t;

    vector<Circ> C(c);
    for (int i = 0; i < c; i++)
    {
        tint x, y, r;
        x = readCoord();
        y = readCoord();
        r = readCoord();
        C[i] = {pto{x, y}, r};
    }
    vector<Quad> Q(q);
    for (int i = 0; i < q; i++)
    {
        pto a, b;
        a = readPoint();
        b = readPoint();
        Q[i] = fromOpposites(a, b);
    }
    vector<Triangle> T(t);
    for (int i = 0; i < t; i++)
    {
        pto a, b, c;
        a = readPoint();
        b = readPoint();
        c = readPoint();
        T[i] = {a, b, c};
    }
    

    ld sol = INF;
    
    vector<ld> D(c, INF), S(c, INF);
    for (int i = 0; i < c; i++) {
        for (auto &t : T) {
            D[i] = min(D[i], distCircleTriangle(C[i], t));
        }
        for (auto &q : Q) {
            S[i] = min(S[i], distCircleQuad(C[i], q));
        }
    }

    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld, int>>> pq;
    vector<bool> vis(c, false);
    for (int i = 0; i < c; i++) pq.push({D[i], i});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        sol = min(sol, d + S[u]);

        for (int v = 0; v < c; v++) {
            if (u == v || vis[v]) continue;
            ld dist = distCircleCircle(C[u], C[v]);
            if (D[v] > d + dist) {
                D[v] = d + dist;
                pq.push({D[v], v});
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < t; j++)
        {
            ld re = distQuadTriangle(Q[i], T[j]);
            sol = min(sol, re);
        }
    }

    cout << fixed << setprecision(7) << sol / KFACTOR << '\n';
}
