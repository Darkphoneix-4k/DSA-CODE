class Solution {
public:
void solve (string &s , int i ){
    if (s.find(')') == string :: npos){
        return ;
    }
  
    stack <int> st ;
   while (s[i]!= ')'){
    st.push(i);
    i++;
   }
   int close = i;
   while (s[st.top()]!='('){
    st.pop();
   }
   int open = st.top();
   
   reverse (s.begin()+open+1 ,s.begin()+close);
   
   s.erase (close, 1);
   s.erase(open ,1);
  
   solve (s , 0);

}
    string reverseParentheses(string s) {
       solve (s , 0);
        return s ;
       
    }
};