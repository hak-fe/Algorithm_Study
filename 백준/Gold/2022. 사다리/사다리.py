import sys
import math

x, y, c = map(float, sys.stdin.readline().split())
low, high = 0, min(x, y)
ans = 0


for _ in range(10000):
    mid = (low + high) / 2
    h1 = math.sqrt(x**2 - mid**2)
    h2 = math.sqrt(y**2 - mid**2)
    

    guess_c = (h1 * h2) / (h1 + h2)

    if guess_c >= c:
        ans = mid
        low = mid
    else:
        high = mid

print(f"{ans:.3f}")