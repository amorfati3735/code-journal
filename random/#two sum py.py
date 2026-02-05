#two sum py
def twos(arr,tar):
    dic={}
    for k,v in enumerate(tar):
        if (tar-v) in seen:
        seen[v]= k
        
seen is a dic that has the og list as keys and the values as the indices
def twoSum(nums, target):
    seen = {}
    for i, x in enumerate(nums):
        if target - x in seen:
            return [seen[target - x], i]
        seen[x] = i
