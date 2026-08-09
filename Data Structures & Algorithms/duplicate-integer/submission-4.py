class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dup = False
        hash = {}
        for index, num in enumerate(nums):
            if num in hash:
                return True
            else:
                hash[num] = (index)
                continue
        return dup
            