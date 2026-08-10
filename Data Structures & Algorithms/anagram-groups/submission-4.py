from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash = defaultdict(list)
        for word in strs:
            temp = "".join(sorted(word))
            hash[temp].append(word)
        matrix = [value for value in hash.values()]
        return matrix
