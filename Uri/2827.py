s = input().lower()
m = {}
for i in range(len(s[:-1])):
    key = s[i: i + 2]
    if key in m.keys():
        m[key] = m[key] + 1
    else:
        m.update({key: 1})

ans = 0
key = ''
for i in m:
    v = m[i]
    if v > ans:
        key = i
        ans = v
    elif v == ans:
        key = i if i < key else key

print('{}:{}'.format(key, ans))




