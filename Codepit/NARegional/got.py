l = list(0 for i in range(112))
while True:
    try:
        n, k = [int(x) for x in input().split(' ')]
    except (ValueError, EOFError):
        break
    ans, ind = 0, 0;
    s = input().split(' ')
    undo = False
    for i in s:
        try:
            if undo:
                x = int(i)
                ind = ind - x
                ans = l[ind - 1]
                undo = False
            else:
                x = int(i)
                ans = (ans + x) % n
                l[ind] = ans
                ind = ind + 1
        except ValueError:
            undo = True
    print(ans)

