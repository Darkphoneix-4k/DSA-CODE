class Solution(object):
    def isValid(self, s):
        stack = []
        for i in range (0 ,len(s)):
            ch = s[i]
            if (ch == '(' or ch =='{' or ch=='['):
                stack.append(ch)

            else :
                if stack:
                    top = stack[-1]
                    if ((ch ==')' and top == '(') or
                       (ch =='}' and top == '{') or
                       (ch ==']' and top == '[')):
                       stack.pop()
                    else:
                        return False 
                         
                else:
                    return False 
                    
        if not stack:
            return True
        else:
            return False 

              
        