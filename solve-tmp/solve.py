def nCrNoOverFlow(n, k):
    if n < k or k < 0:
        return 0
    k = max(k, n - k)
    ans = 1

    i = n
    while i > k:
        ans = (ans * i) / (n - i + 1)
        i = i - 1
    return ans


i = 0
while i <= 65:
    print(nCrNoOverFlow(65, i))
    i = i + 1