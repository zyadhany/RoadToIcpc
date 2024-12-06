// e^(a * i) = cos(a) + i * sin(a)
complex<double> num(2, 3); // 2 + 3i
num.real(); // 2
num.imag(); // 3


// As circle with vector from (0,0) to (1,1)
complex<double> num(1, 1);
cout << abs(num); // 1.41421
cout << arg(num); // 0.785398 degree in radian
cout << arg(num) * 180 / pi; // 45
cout << norm(num); // 2 -> (1^2 + 1^2)

// From polar to complex
// (0.99999998 , 0.999999997) -> (1,1)
complex<double> num = polar(1.41421, 0.785398);

// We can use (+, -, *, /) between complex numbers


// sqrt(-1) = 0 + i
complex<double> num = -1;
cout<<sqrt(num); // (0, 1)


// conj and pow
complex<double> c(2, 3);
cout<<conj(c); // (2, -3)
cout<<pow(c,2); // (-5, 12)

// exp
complex<double> c(0, -1);
cout<<exp(c*pi); // (-1, 0)


// defines
typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
// dp = a*b*cos(T), if zero -> prep
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
// cp = a*b*sin(T), if zero -> parllel
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
// hypot like sqrt but no over flow and slower
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
// we can use polar built in
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
// rotate around origin
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
// rotate around point
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
// reflect around origin
#define reflectO(v,m)  (conj((v)/(m))*(m))

// reflect around line
point reflect(point p, point p0, point p1) {
    point z = p-p0, w = p1-p0;
    return conj(z/w)*w + p0; // Refelect point p around line p0p1
}




double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}

// return min angle: aOb / bOa
// dp(v1, v2) = |v1|*|v2|*cos(theta)
double angleO(point a, point O, point b) {
  point v1(a - O), v2(b - O);
  return acos( fixAngle ( dp(v1, v2) / length(v1) / length(v2) ) );
}


// 0-> equal , 1-> a > b , -1-> a < b
int dcmp(double a, double b){
    return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1; 
}

double getAng(point &a, point &b, point &c) // find angle abc, anticlock bc to ba
{
    double ang = angle( vec(b, c)) - angle( vec(b, a));
    if(dcmp(ang, 0) < 0)
    	ang+=2*PI;
    return ang;
}






// Lines and Distances

// To know if 3 points on same line
bool isCollinear(point a, point b, point c) {	
	return fabs( cp(b-a, c-a) ) < EPS;	
}

// Does C or p2 on ray from A to b
// ray  a ----> b line with no end
bool isPointOnRay(point p0, point p1, point p2) {
    if(length(p2-p0) < EPS) return true;
    return same( normalize(p1-p0), normalize(p2-p0) );
}

bool isPointOnRay(point a, point b, point c) {
    if(!isCollinear(a, b, c))
    	return false;
    return dcmp(dp(b-a, c-a), 0) == 1;
}


// Does C on segment from A to b
// segment  a <----> b line with no start and no end
bool isPointOnSegment(point a, point b, point c) {
	return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}

bool isPointOnSegment(point a, point b, point c) {
	double acb = length(a-b), ac = length(a-c), cb = length(b-c);
	return dcmp(acb-(ac+cb), 0) == 0;
}


// Distance from p2 to line p0p1
double distToLine( point p0, point p1, point p2 ) {
	return fabs(cp(p1-p0, p2-p0)/length(p0-p1)); // area = 0.5*b*h
}


//distance from point p2 to segment p0-p1
double distToSegment( point p0, point p1, point p2 ) {
	double d1, d2;
	point v1 = p1-p0, v2 = p2-p0;
	if( (d1 = dp(v1, v2) ) <= 0)	return length(p2-p0);
	if( (d2 = dp(v1, v1) ) <= d1)	return length(p2-p1);
	double t = d1/d2;
	return length(p2 - (p0 + v1*t) );
}


