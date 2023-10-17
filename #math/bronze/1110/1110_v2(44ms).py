

key = int(input())
origin = key
cycle = 1
while True:
    key = (int)(key%10)*10 + (int)(key/10 + key%10)%10
    #print(key, cycle)
    if origin == key:
        print(cycle)
        break
    cycle += 1
