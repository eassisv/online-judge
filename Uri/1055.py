t = int(input())
for i in range(t):
    vs = list(int(x) for x in input().split(' '))
    vs.pop(0)
    vs.sort()
    ans = 0
    for j in [True, False]:
        vs1 = vs.copy()
        aux = [vs1.pop() if j else vs1.pop(0)]
        g = not j
        while len(vs1):
            global vs1
            if g:
                aux.insert(0, vs1.pop())
                if len(vs1): aux.append(vs1.pop())
            else:
                aux.insert(0, vs1.pop(0))
                if len(vs1): aux.append(vs1.pop(0))
            g = not g
        temp = 0
        for x in range(len(aux) - 1):
            temp += abs(aux[x] - aux[x + 1])
        ans = max(ans, temp)
    print('Case {}: {}'.format(i + 1, ans))


