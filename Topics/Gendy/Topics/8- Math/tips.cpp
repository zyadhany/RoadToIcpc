// arithmetic ->

3 is always bigger mul 3*3=9

2 4 6 8

1 2 3 4 5

mid numper * n
3 * 5 = 15

sum(n-k)

----------------------------
Geometric progression

1 2 4 8

an = a*powl(r,(n-1))

sn --> sum to n numpers

sn = a*(1- powl(r,n))/(1-r)

------------------------------
ncr

     n!
  --------
(r! * (n-r)!)

-----------------------------
npr

     n!
   -----
   (n-r)!



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

