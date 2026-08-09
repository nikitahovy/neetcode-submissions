class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.replace(" ", "")
        s = s.replace("?", "")
        s = s.replace("!", "")
        s = s.replace("'", "")
        s = s.replace(",", "")
        s = s.replace(".", "")
        s = s.replace(":", "")
        s = s.replace(";", "")



        s = s.lower()
        print(s)
        curr = s
        for i in range(len(s) // 2):
            print("comparison = " + curr[i] + curr[len(curr) - 1])
            if curr[i] == curr[len(curr) - 1]:
                curr = curr[0:len(curr) - 1]
                continue
            else:return False

        return True