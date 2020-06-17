//Problem path : https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alphas(127,-1);
        int maxSize = 0;
        int start = 0;
        
        for(int i=0; i<s.length(); i++){
           if(alphas[s[i]] == -1 || alphas[s[i]] < start) {
               alphas[s[i]] = i;
               maxSize = max(maxSize, i-start + 1);
           } else {
               start = alphas[s[i]] + 1;
               alphas[s[i]] = i;
           }  
        }
        
        return maxSize;
    }
};
