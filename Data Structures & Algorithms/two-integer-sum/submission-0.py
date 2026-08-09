class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = {}
        for index, n in enumerate(nums):
            diff = target - n
            if diff in hashMap:
                return [hashMap[diff], index]
            hashMap[n] = index