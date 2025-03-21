/*
Birthday Paradox: refers to the probability that in a set of n randomly chosen people, some pair of them will have the same birthday.

Example: Find a string with the standard polynomial hash equal to the target value X modulo 109+7
. The hash is computed by converting characters a-z into 0-25 and multiplying every character by the next power of 26.

Solution: We can use the birthday paradox to solve this problem. We can generate a random strings of size k and check there is prev string such that H_1 + P^k * H_2 = X. then the sol is s_1+s_2. 
*/