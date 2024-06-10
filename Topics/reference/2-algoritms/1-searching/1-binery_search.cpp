// method 1
int a = 0, b = n-1;
while (a <= b) {
    int k = (a+b)/2;
    if (array[k] == x) {
        // x found at index k
    }
    if (array[k] > x) b = k-1;
    else a = k+1;
}


// method 2
int k = 0;
for (int b = n/2; b >= 1; b /= 2) {
    while (k+b < n && array[k+b] <= x) k += b;
}

if (array[k] == x) {
    // x found at index k
}


// built-in function.

/**
 * lower_bound returns a pointer to the first array element whose value is at least x.
 * upper_bound returns a pointer to the first array element whose value is larger than x.
 * equal_range returns both above pointers.
*/

// count number of x in array.
auto a = lower_bound(array, array+n, x);
auto b = upper_bound(array, array+n, x);
cout << b-a << "\n";

auto r = equal_range(array, array+n, x);
cout << r.second-r.first << "\n";


// you have array, x is increasing and then decreasing.
/**
 * f (x) < f (x+1) when x < k, and
 * f (x) > f (x+1) when x >= k.
 *  finding the largest value of x for which f (x) < f (x+1). 
*/

int x = -1;
for (int b = z; b >= 1; b /= 2) {
    while (f(x+b) < f(x+b+1)) x += b;
}
int k = x+1;

