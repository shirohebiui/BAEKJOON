arr = [4, 0, 4, 4, 1, 8, 8, 2, 2, 5, 0, 6, 5, 6, 0]
memo = [0] * 10

for n in range(len(arr)):
    memo[arr[n]] += 1

print(memo)

''' d1 = {}

for num in arr:
    if d1.get(num) == None:
        d1[num] = 1
    else:
        d1[num] = d1[num] + 1
print(d1) '''