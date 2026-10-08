class Solution(object):
    def removeOuterParentheses(self, s):
        n = len(s)
        p = ""
        count1 = 0
        count2 = 0
        for ch in s :
            if (ch == '('):
                count1 +=1
                if (count1 > 1):
                    p += ch

            elif (ch == ')'):
                count2 +=1
                if (count1 > count2):
                    p +=ch

                elif (count1 == count2):
                    count1 =0
                    count2 =0

        return p

        