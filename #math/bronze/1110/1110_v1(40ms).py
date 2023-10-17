def find_cycle(key, cycle):
    key = (int)(key%10)*10 + (int)(key/10 + key%10)%10
    #print(key, cycle)
    if origin == key:
        return cycle
    else :
        return find_cycle(key, cycle+1)

origin = int(input())
print(find_cycle(origin, 1))
