class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map <string ,string> mp;
        int n = s.size();

        for (auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }
        string ans = "";
        int i = 0;
        while (i < n) {


            if (s[i] == '(') {
                i++;
                string temp ="";
                while (s[i] != ')') {
                    temp.push_back (s[i]);
                    i++;
                }
                if (mp.count(temp)){
                    ans+=mp[temp];
                }
                else {
                     ans+="?";
                }
            } else {
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans ;
    }
};