class Solution(object):
    def solve (self , count , n, curr , ans ):
        if len(curr) == 2* n :
            if count == 0:
                ans.append(curr)
                return

        openUsed = (len(curr)+ count) // 2

        if openUsed < n :
            self.solve( count+1 , n , curr + "(" , ans)

        if count > 0:
            self.solve ( count-1 , n , curr + ")" , ans)

    def generateParenthesis(self, n):
        ans = []
        self.solve (0,n , "" , ans)
        return ans 