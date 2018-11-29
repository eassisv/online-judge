import string
n = int(input())
abc = string.ascii_lowercase
ans = 'a'
for i in abc[1:]:
    ans = ans + i + ans

print(ans[n - 1])
