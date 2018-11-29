n = int(input())
ss = []
for i in range(n):
    s = input()
    ss.append((s.lower(), s))

ss.sort()
print(type(ss[0]))

for s in ss:
    print(s[1])
