class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_array = defaultdict(int)
        for num in nums:
            freq_array[num] += 1
        # for key, value in freq_array.items():
        #    result.append(key)
        # result.sort(reverse=True)
        sorted_arr = dict(sorted(freq_array.items(), key=lambda item: item[1], reverse=True))
        array = list(sorted_arr.keys())
        return array[:k]

