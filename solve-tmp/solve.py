l = 1
r = 1e9
while True:
    mid = (l + r) // 2
    print(int(mid), flush=True)
    c = input()
    if c == '=':
        print("! " + str(int(mid)), flush=True)
        break
    elif c == '<':
        r = mid - 1
    else:
        l = mid + 1
