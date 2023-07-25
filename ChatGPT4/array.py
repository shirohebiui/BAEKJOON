numbers = [1,2,3,4,5,6,7,8,9,0]
memo = [0] * 10

''' for n in numbers:
    print(n)
for n in numbers:
    memo[n] += 1
print(memo) '''
for n in numbers:
    memo[n] += 1
for i in range(len(memo)):
    print(f'i:{i} n:{memo[i]}')