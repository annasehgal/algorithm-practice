class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set() # creates empty set
        for num in nums: # due to set we don't need range(len(nums))
            if num in seen: 
                return True
            seen.add(num) 
            
        return False
