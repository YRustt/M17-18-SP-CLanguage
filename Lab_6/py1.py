from ctypes import CDLL


libc = CDLL("sum1.so")
digit_sum = libc.digit_sum


res = 0
for i in range(100000000):
    res += digit_sum(i)

print(res)
