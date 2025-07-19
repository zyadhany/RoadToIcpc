#include <iostream>
#include <complex>
using namespace std;

// define x, y as real(), imag()
typedef complex<double> point;
#define x real()
#define y imag()

// sample program
int main() {
	point a = 2;
	point b(3, 7);
	cout << a << ' ' << b << endl; // (2, 0) (3, 7)
	cout << a + b << endl;         // (5, 7)
}
// Oh goodie! We can use std:cout for debugging! We can also add points as vectors without having to define operator+. Nifty. And apparently, we can overall add points, subtract points, do scalar multiplication without defining any operator. Very nifty indeed.

Example
point a(3, 2), b(2, -7);

// vector addition and subtraction
cout << a + b << endl;   // (5,-5)
cout << a - b << endl;   // (1,9)

// scalar multiplication
cout << 3.0 * a << endl; // (9,6)
cout << a / 5.0 << endl; // (0.6,0.4)
Functions using std::complex
// What else can we do with complex numbers? Well, there's a lot that is really easy to code.

// Vector addition: a + b

// Scalar multiplication: r * a

// Dot product: (conj(a) * b).x

// Cross product: (conj(a) * b).y

// notice: conj(a) * b = (ax*bx + ay*by) + i (ax*by — ay*bx)

// Squared distance: norm(a - b)

// Euclidean distance: abs(a - b)

// Angle of elevation: arg(b - a)

// Slope of line (a, b): tan(arg(b - a))

// Polar to cartesian: polar(r, theta)

// Cartesian to polar: point(abs(p), arg(p))

// Rotation about the origin: a * polar(1.0, theta)

// Rotation about pivot p: (a-p) * polar(1.0, theta) + p

// UPD: added more useful functions

// Angle ABC: abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI))

// remainder normalizes the angle to be between [-PI, PI]. Thus, we can get the positive non-reflex angle by taking its abs value.

// Project p onto vector v: v * dot(p, v) / norm(v);

// Project p onto line (a, b): a + (b - a) * dot(p - a, b - a) / norm(b - a)

// Reflect p across line (a, b): a + conj((p - a) / (b - a)) * (b - a)

// Intersection of line (a, b) and (p, q):

point intersection(point a, point b, point p, point q) {
  double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}
    