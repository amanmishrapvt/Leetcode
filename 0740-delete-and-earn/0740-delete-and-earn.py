class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        ht = Counter(nums)
        keys = sorted(ht.keys())
        n = len(keys)
        
        # next1 -> dp[i + 1], next2 -> dp[i + 2]
        next1, next2 = 0, 0
        
        for i in range(n - 1, -1, -1):
            skip = next1
            points = keys[i] * ht[keys[i]]
            
            if i + 1 < n and keys[i + 1] == keys[i] + 1:
                take = points + next2
            else:
                take = points + next1
                
            curr = max(skip, take)
            
            # Shift state backward
            next2 = next1
            next1 = curr
            
        return next1