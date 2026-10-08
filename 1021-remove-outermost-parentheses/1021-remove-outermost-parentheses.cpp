class Solution {
public:
    string removeOuterParentheses(string s) {
        int n =s.size();
        string p = "";
        int count1 =0;
        int count2 = 0;

        for (int i = 0; i < n; i++){
           if (s[i]=='('){
             count1++;
            if (count1 > 1){
                p.push_back(s[i]);
            }
           }
           if (s[i]== ')'){
            count2++;
            if (count2 < count1){
                 p.push_back(s[i]);
            }
            else if (count2 == count1){
                count1 = 0;
                count2 = 0;
                continue;
            }
           }
        }
        return p;
    }
};