class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int ans = s.size() + 1;
        int l = 0;
        int r = 0;
        int start = 0;
        int length = 0;
        for (char i : t) {
            need[i]++;
        }
        int have = 0;
        int required = need.size();
        for (r = 0; r < s.size(); r++) {
            window[s[r]]++;
            if (window[s[r]] == need[s[r]]) {
                have++;

                while (have == required) {
                    if (r - l + 1 < ans) {
                        ans = r - l + 1;
                        start = l;
                    }

                    window[s[l]]--;
                    if (window[s[l]] < need[s[l]]) {
                        have--;
                    }

                    l++;
                }
            }
        }
        if (ans == s.size() + 1) {
            return "";
        }

        return s.substr(start, ans);
    }
};