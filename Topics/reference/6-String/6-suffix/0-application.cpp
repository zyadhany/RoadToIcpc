/*
    suffix array: is index of suffixes in sorted order.

    1. we can count number of occurences of a string using binary search and compare string in time O(|s|*log(n)).

    2. number of distinct substrings = n*(n+1)/2 - sum(lcp[i]) for i = 0 to n-2. ie- the number of substrings - number of common prefixes.

    3. find longest common substring of two strings using lcp array. we create new string s = s1 + '$' + s2 + '#' and find the longest common prefix of suffixes in the range [0, n-1] and [n+1, n+m]. The lcp array will give us the length of the longest common substring.
    (make sure that char '$' is greater than '#' in the string)

    4. after building lcp array we can find longest common prefix of any two suffixes in O(1) time using sparse table. that equal to min(lcp[l..r-1]) where l and r are indices of i and j in suff array.
*/