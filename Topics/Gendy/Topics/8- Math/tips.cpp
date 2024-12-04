// arithmetic -> The difference between every two numbers is constant.

3 is always bigger mul 3*3=9

Number or elemets is (even)
2 4 6 8
Sum equals
(a First + a Last)*(n/2)  n-> Num of elements

Number or elemets is (odd)
1 2 3 4 5

mid numper * n
3 * 5 = 15

Number of ways for substring
sum(n-k)

----------------------------
Geometric progression

1 2 4 8
Each number divided by the one before it equals a specific ratio.
r=2 --> the ratio of each number to the one before it is 2

an = a*powl(r,(n-1))

sn --> sum to n numpers

sn = a*(1- powl(r,n))/(1-r)

------------------------------
ncr

     n!
  --------
(r! * (n-r)!)

Selection of the number of elements (r)  
Size of the array (n)  
Without considering the order.
-----------------------------
npr

     n!
   -----
   (n-r)!

Selection of the number of elements (r)
Size of the array (n)
Considering the order


double customLog(double base, double x) {
    return log(x) / log(base);
}


// big mod
int mod(string num, int a)
{
    int res = 0;
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + num[i] - '0') % a;

    return res;
}


// sum from a to b
    ll sum = (b-a+1)*(a+b)/2;


// round
round(x, y) = (x + y/2)/y; // x > 0
round(x, y) = (x - y/2)/y; // x < 0

// round x to multiple of m
round(x, m) = round(x/m) * m;


// x have odd divisors -> x have sqrt







