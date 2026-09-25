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

        if (curr->child[index] == nullptr)
            return;

        curr = curr->child[index];

        path.push_back(ch);

        if (curr->isEnd) {
            ans.push_back(path);
            curr->isEnd = false;
        }

        board[r][c] = '#';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < board.size() && nc >= 0 &&
                nc < board[0].size() && board[nr][nc] != '#') {

                dfs(nr, nc, curr, board, path, ans);
            }
        }

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

        int rows = board.size();
        int cols = board[0].size();

        // Start DFS from every cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(r, c, root, board, path, ans);
            }
        }

        return ans;
    }
};