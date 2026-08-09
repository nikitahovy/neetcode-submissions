class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
       hash = {}
       for index, value in enumerate(nums):
        comp = target - value
        if comp in hash:
            return [hash[comp], index]
        hash[value] = index
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
        # hashMap = {}
        # for index, n in enumerate(nums):
        #     diff = target - n
        #     if diff in hashMap:
        #         return [hashMap[diff], index]
        #     hashMap[n] = index