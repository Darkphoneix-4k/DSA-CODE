class Solution(object):
    def longestValidParentheses(self, s):
        stack = []
        stack.append(-1)
        ans = 0

        for i in range (0, len(s)):
            if (s[i] == '('):
                stack.append(i)

            else :
                stack.pop()

                if not stack:
                    stack.append(i)

                else :
                    ans = max (ans , i- stack[-1])

        return ans


            