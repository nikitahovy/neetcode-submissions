class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hash = {}
        for index, value in enumerate(nums):
            if value in hash:
                return True
            hash[value] = index
        
        return False