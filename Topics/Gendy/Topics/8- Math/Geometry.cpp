// interior angles is ( n − 2 ) × 180
// Litre = 1000 cm^3

// pi
const double PI = acos(-1.0);
#define pi  3.14159265358979323846


/*
 Points can be on the same line from x, y in O(Log(n))
 if we took every point and get the a - x , y - x
 and after that we will get the gcd and divide it with
*/ 
ll n, x, y;
cin >> n >> x >> y;
set<pair<ll, ll>> s;
for (int i = 0; i < n; ++i)
{
    ll a, b;
    cin >> a >> b;
    a -= x, b -= y;
    ll g = gcd(a, b);
    s.insert({a / g, b / g});
}
ll ans = s.size();
cout << ans;




// Check two lines intersect
const double EPS = 1e-10;
#define point complex<double>
#define X real()
#define Y imag()
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
// return the point line ab intesect cd and 1e9, 1e9 if no intersect
point lines_intersect(point a, point b, point c, point d){
    // C = Ax + By
    double a1 = b.Y - a.Y;
    double b1 = a.X - b.X;
    double c1 = a1*(a.X) + b1*(a.Y);

    double a2 = d.Y - c.Y;
    double b2 = c.X - d.X;
    double c2 = a2*(c.X) + b2*(c.Y);

    double det = a1*b2 - a2*b1;
    // No intersection (parallel //) return (1e9, 1e9)
    if (det == 0)
        return {1e9, 1e9};

    double x = (b2*c1 - b1*c2)/det;
    double y = (a1*c2 - a2*c1)/det;
    return {x,y};
}

bool isCollinear(point a, point b, point c) {
    return fabs( cp(b-a, c-a) ) < EPS;
}

void solve(ll test){

    ll x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    point a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
    point ans = lines_intersect(a, b, c, d);

    
    if (isCollinear(a, b, c) && isCollinear(a, b, d)){
        // if they intersect in a line no point
        cout<<"LINE\n";
    }
    else if (ans.X == 1e9 && ans.Y == 1e9)
    {
        // if they not intersect
        cout<<"NONE\n";
    }
    else
    {
        // if they intersect

        // to change ( -0 ) to ( 0 ) if needed
        point tx(ans.X, 0);
        point ty(0, ans.Y);
        if (fabs(ans.X) <= EPS )
            ans -= tx;
        if (fabs(ans.Y) <= EPS )
            ans -= ty;
        cout<<"POINT "<<fixed(2)<<ans.X<<' '<<ans.Y<<"\n";
    }


}