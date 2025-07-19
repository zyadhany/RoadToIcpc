/*
Arithmetic Billiards: You have n * m grid, starting from (1, 1) you will move diagonally with 45 degree down right until you reach to boundary then you will bounce back to the opposite direction, it you hit corner you will get back as cyclic.
https://math.uni.lu/eml/assets/reports/2019/Carvalho-da-Veiga.pdf
*/


// gcd is number of point before first intersection
// lcm is length of the path before cycle
/*
To find the number of bounces: (n + m)/gcd(a,b) - 2
- for side 1: a/gcd(a,b)-1
- for side 2: b/gcd(a,b)-1
side1+side2 = (n + m)/gcd(a,b) - 2
*/
// number of intersections points starting from (0, 0)
// intersect = (a/gcd(a, b - 1) * (b/gcd(a, b - 1) - 1) / 2


// x0, y0 are the starting point
ll bouncing_points(ll a, ll b, ll x0, ll y0) {
    ll g = gcd(a, b);
    ll sum = x0 + y0;

    // Case 1: x0 + y0 == 0
    if (sum == 0) {
        return (a + b) / g - 2;
    }

    // Case 2: x0 + y0 is odd
    if (sum % 2 == 1) {
        if (g == 1) {
            return (a + b) - 2; // coprime
        } else {
            return 2 * ((a / g) + (b / g));
        }
    }

    // Case 3: x0 + y0 is even
    if (sum % 2 == 0) {
        if (g == 1) {
            return (a + b) - 2;
        }

        // both even, but b does not divide a
        if ((a % 2 == 0) && (b % 2 == 0) && (a % b != 0)) {
            return (a + b);
        }

        // one even, one odd, g != 1
        if ((a % 2 != b % 2) && (g != 1)) {
            return 2 * ((a / g) + (b / g));
        }

        // when b divides a
        if (a % b == 0) {
            return 2 * ((a / g) + (b / g));
        }

        // fallback
        return -1;
    }

    return -1; // unreachable in valid input
}

