class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hash = {}
        if (len(s) != len(t)):
            return False
        count = 0

        for index, value in enumerate(s):
            if value not in hash:
                hash[value] = []
            hash[value].append(index)
        print("going into second")
        for i in range(len(t)):
            if t[i] in hash:
                hash[t[i]].pop()
                if not hash[t[i]]:
                    del hash[t[i]]
                continue
            if t[i] not in hash:
                return False
        return True