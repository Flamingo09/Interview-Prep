//Very nice use of XOR
class Solution {
public:
    int ind(char c) {
        if ('A' <= c && c <= 'Z') return c - 'A';
        return c - 'a' + 26;
    }
    
    string longestNiceSubstring(string s) {
        int n = s.length();
        string ans;
        for (int i = 0; i < n; i++) {
            vector<int> cnt(52);
            for (int j = i; j < n; j++) {
                cnt[ind(s[j])]++;
                int ok = 1;
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] != 0 ^ cnt[k+26] != 0) {
                        ok = 0;
                    }
                }
                if (ok && j-i+1 > (int)ans.length()) {
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        return ans;
    }
};
