// Combinatorics

// Formulas

C(0 ,n)^2 + C(1, n)^2 +...+ C(n,n)^2 = C(n, 2*n)

1*C(1,n) + 2*C(2,n) +...+ n*C(n,n) = n * (2^(n-1))

C(0, n) + C(1, n-1) +...+ C(k, n-k) +...+ C(n, 0) = Fibonacci(n+1)

SUM k = 0:n for C(k,n) = 2^n

SUM m = 0:n for C(k, m) = C(k+1, n+1)

SUM k = 0:m for C(n+k, k) = C(m, n+m+1)

SUM m = 0:n for C(k, m) = C(k+1, n+1)



// If I have to find 4 numpers >= 0 equals 100
a + b + c + d = 100

= C(n+k-1, k-1)

n = 100, k = 4


// If a >= 3 and b >= 0 and c >= 2 and d >= 1
(a+3) + (b+0) + (c+2) + (d+1) = 100
a + b + c + d + 6 = 100
a + b + c + d = 94

= C(n+k-1, k-1)

n = 94, k = 4






// To find the numper of ways to split the number
// into non inscreasing sequence of positive
-> Fibonacci(number)

/*
Ex: number = 5

5
4+1
3+2
3+1+1
2+2+1
2+1+1+1
1+1+1+1+1

Total ways = 7
*/


/*
find how many number from 1 to n such that the
diffrence keep increase every time
1, 2, 4, 7, 11, 16, 22, 
Can get the values 40000 iteration for 1e9
or use this formula
ans = ((-1+sqrtl(1+8*r))/2)+1
*/
