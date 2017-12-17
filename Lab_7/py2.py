import sum2

res = 0
for i in range(100000000):
    res += sum2.digit_sum(i)

print(res)
