class Solution {
public:
    string s;
    int i = 0;

    set<string> parse() {
        set<string> res;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {

            // Union
            if (s[i] == ',') {
                res.insert(cur.begin(), cur.end());
                cur = {""};
                i++;
            }

            // Nested expression
            else if (s[i] == '{') {
                i++; // skip '{'

                set<string> next = parse();

                i++; // skip '}'

                // Concatenation
                set<string> temp;

                for (const string& a : cur) {
                    for (const string& b : next) {
                        temp.insert(a + b);
                    }
                }

                cur = temp;
            }

            // Normal letters
            else {
                string word;

                while (i < s.size() && isalpha(s[i])) {
                    word += s[i];
                    i++;
                }

                set<string> temp;

                for (const string& x : cur) {
                    temp.insert(x + word);
                }

                cur = temp;
            }
        }

        res.insert(cur.begin(), cur.end());

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parse();

        return vector<string>(ans.begin(), ans.end());
    }
};
