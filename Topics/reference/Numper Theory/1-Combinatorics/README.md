Introduction

if we got a dice and through it, how many outcomes can we get?
= we can get 1,2,3,...6, so we have 6 outcomes.

but what if we through 2 dice consider 1/2 != 2/1 ,what we get?
at total there is 36 possibility, how?
first dice has 6 possibilitiesm, 1 to 6 and for each one of them the seconde dice has 6 also.
it's like for the first dice equal 1 so result is 1/1, 1/2, 1/3,...,1/6 and we can repeat it for all it's 6 possibilities.
so the answer will be (6*6 = 36).

if we think with same idea in 3 dice it will 6*6*6.

what if it isn't dice and some thing differnt like binary number which has only 2 values (0,1)
for 3 digit number it will have 8 possibilities which is 2*2*2.

more formally we can say if we have n opjects each has k value the number of possipossibilies if we rolling them is k^n.

---

permutations:
-when throw 3 dice the outcome be: 6*5*4
-if we got n opject and need to get k of them (don't care about ordering):-
n*(n-1)*(n-2)*(n-3)*...(n-k+1)

-The number of permutations of n things taken k at a time is
P(n, k) = n(n − 1)(n − 2)· · ·(n − k + 1) = n! / (n − k)!.

----

combinatorics:
if we start looking at ordering so 1/2 = 2/1
by trowing 3 dices the total output is 120 = 6*5*4
by take 1,2,3 as example it can heppen in 6 form -> 3! so every ouput repeated 6 time, if we remove it
the answe will be 120/6 = 20 = P(6, 3) / 3!. 

-The number of ways to chooce k among n opjects (consider order):-
C(n, k) = n! / (k! * (n − k)!).
