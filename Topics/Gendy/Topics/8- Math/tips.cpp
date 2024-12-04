// arithmetic -> الفرق بين كل رقمين ثابت

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
كل رقم علي الي قبله بيساوي نسبه معينة
r=2 --> نسبة القسمة كل رقم عل الي قبله

an = a*powl(r,(n-1))

sn --> sum to n numpers

sn = a*(1- powl(r,n))/(1-r)

------------------------------
ncr

     n!
  --------
(r! * (n-r)!)

اختيار عدد عناصر r 
حجم الاراي n
مع عدم مراعاه الترتيب
-----------------------------
npr

     n!
   -----
   (n-r)!

اختيار عدد عناصر r 
حجم الاراي n
مع مراعاه الترتيب


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







