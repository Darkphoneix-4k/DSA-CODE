class Solution:
    def maxDepth(self, s: str) -> int:
      x = 0 
      ans = 0 


      for ch in s:
        if ch == '(':
            x += 1
            ans = max(ans , x)
        elif ch == ')':
            x-=1

      return ans  