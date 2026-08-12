class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # i forgot variable and was just sorting haha
        result1= sorted(s)
        result2 = sorted(t)
        if (result1 == result2):
            return True
        else:
            return False
