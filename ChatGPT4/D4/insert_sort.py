nums = [11,22,44,33,77,3,55,66,88,99,0]

for i in range(1, len(nums)):
    for j in range(i, 0, -1):
        #print(i, j, j - 1)
        if(nums[j-1] > nums[i]):
            tmp = nums[j-1]
            nums[j-1] = nums[i]
            nums[i] = tmp
    print(i, nums)