class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int right = 0;

        int required = need.size();
        int formed = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

           
            char c = s[right];
            window[c]++;

           
            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

           
            while (formed == required) {

              
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

            
                char leftChar = s[left];
                window[leftChar]--;

                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};