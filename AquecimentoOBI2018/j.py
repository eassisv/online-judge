b = input()
e = int(input())
ans = 0
for i in b:
    ans += int(i)
    ans = 1 + ((ans - 1) % 9)

ebin = bin(e)[2:]
def expbin(a, e):
    r = 1
    for i in e[::-1]:
        if int(i) == 1:
            r = 1 + (((r * a) - 1) % 9)
        a = 1 + (((a * a) - 1) % 9)
    return r

print(expbin(ans, ebin))
