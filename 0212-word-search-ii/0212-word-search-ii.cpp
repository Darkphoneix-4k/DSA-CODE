class Solution {
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    int m, n;
    Node* root;
    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr)
                curr->child[index] = new Node();

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }

public:
    void dfs(int r, int c, Node* curr, vector<vector<char>>& board,
             string& path, vector<string>& ans) {

        char ch = board[r][c];
        int index = ch - 'a';

        if (curr->child[index] == nullptr) {
            return;
        }

        curr = curr->child[index];

        path.push_back(ch);

        if (curr->isEnd) {
            ans.push_back(path);
            curr->isEnd = false;
        }

        board[r][c] = '#';

        if (r > 0 && board[r-1][c] != '#')
            dfs(r - 1, c, curr, board, path, ans);

        if (r + 1 < m && board[r+1][c] != '#')
            dfs(r + 1, c, curr, board, path, ans);

        if (c > 0 && board[r][c-1] != '#')
            dfs(r, c - 1, curr, board, path, ans);

        if (c + 1 < n&& board[r][c+1] != '#')
            dfs(r, c + 1, curr, board, path, ans);

        board[r][c] = ch;
        path.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        root = new Node();

        // Build Trie
        for (string word : words)
            insert(word);

        vector<string> ans;
        string path;

        m = board.size();
        n = board[0].size();

        // Start DFS from every cell
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dfs(r, c, root, board, path, ans);
            }
        }

        return ans;
    }
};