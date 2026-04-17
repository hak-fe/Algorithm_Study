import sys
from itertools import permutations
import math

stats = list(map(int, sys.stdin.readline().split()))
ans = 0


for p in permutations(stats):
    convex = True
    for i in range(8):
        a = p[i]
        b = p[(i + 1) % 8]
        c = p[(i + 2) % 8]
        
        if b * (a + c) < a * c * math.sqrt(2):
            convex = False
            break
            
    if convex:
        ans += 1

print(ans)