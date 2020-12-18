//awesome solution with optimization from zestypanda(in comments) :https://leetcode.com/problems/word-squares/discuss/91337/70ms-Concise-C%2B%2B-Solution-Using-Trie-and-Backtracking

class Solution {
struct TrieNode {
    // prefix is to keep indexes of all words that have the prefix from root to current node 
    vector<int> prefix;
    TrieNode* childs[26];
    TrieNode () {
        memset(childs, 0, sizeof(childs));
    }
};
    
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words[0].size();
        TrieNode* root = build(words);
        vector<vector<string>> ans;
        vector<string> board(n);
        for (int i = 0; i < words.size(); i++) {
            board[0] = words[i];
            helper(ans, board, words, root, 1);
        }
        return ans;
    }
private:
    TrieNode* build(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode* p = root;
            for (int j = 0; j < words[i].size()-1; j++) {
                if (p->childs[words[i][j]-'a'] == NULL) {
                    p->childs[words[i][j]-'a'] = new TrieNode();
                }
                p = p->childs[words[i][j]-'a'];
                p->prefix.push_back(i);
            }
        }
        return root;
    }
    void helper(vector<vector<string>>& ans, vector<string>& board, vector<string>& words, TrieNode* root, int row) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
        TrieNode* p = root;
        for (int i = 0; i < row; i++) {
            if (p->childs[board[i][row]-'a'] == NULL) return;
            p = p->childs[board[i][row]-'a'];
        }
        // try every valid word, backtracking
        for (int i:p->prefix) {
            board[row] = words[i];
            helper(ans, board, words, root, row+1);
        }
    }
};
