# Test Cases

- The first line contains a single integer $t$ ($1 \le t \le 10^4$)~--- number of testcases.

- The first line of each testcase contains integers $n$ and $m$ ($1 \le m \le n \le 2 \cdot 10^5$)~--- the number of Ira students and the number of dancers in the \textit{magnificent} dance.

- The second line of each testcase contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$)~--- \textit{levels} of students.

- The only line of each testcase contains a string s, consisting of lowercase Latin letters. Its length is from 1 to 2⋅105.

- It is guaranteed that the sum of $n$ over all testcases \textbf{does not exceed} $2 \cdot 10^5$.

- For each test case, print a single integer, the count of unique numbers of size $n$ that are divisible by $k$ and have no more than $m$ different digits.
# Notes

- In the first test case, the playlist is already exciting.

- In the second test case, if you have the songs in the order 4,3,1,2 , it is exciting, so you don't need to remove any songs.

- In the third test case, you can remove songs 4,5,6,7. Then the playlist with songs in the order 1,2,3 is exciting.

# Others

- Since this number can be very large, count it \textbf{modulo} $10^9 + 7$.

- subarray
    - A subarray of an array is a contiguous sequence of elements within that array. For example, if we have an array $[1, -2, 3, 4, -1, 2, 1, -5, 4]$, then some of its subarrays include $[1, -2, 3]$, $[4, -1, 2, 1]$, and $[-5, 4]$.