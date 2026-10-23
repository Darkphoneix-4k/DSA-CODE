class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        
        n=len(nums)
        k=-1
        for i in range(n):
            if(nums[i]!=i):
                k=k & nums[i]
        if(k==-1):
            return 0
        else:
            return k
