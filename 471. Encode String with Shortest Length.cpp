// Time complexity is O(n^3). if use find method of string, it'll become O(n^4) as it's own time complexity is O(n^2) 
// http://www.cplusplus.com/reference/string/basic_string/find/
class Solution {
public:
    string encode(string s) {
        int n=s.length();
        if(n<=4) return s;
        
        vector<vector<string>>dp(n, vector<string>(n, ""));
        
        for(int l=0; l<n; l++) {
            for(int i=0; i+l<n; i++) {
                int j=i+l;
                string currS=s.substr(i, l+1);
                dp[i][j]=currS;
                
                if(l<4) continue;
                for(int k=i; k<j; k++) {
                    if((dp[i][k]+dp[k+1][j]).length() < dp[i][j].length()) {
                        dp[i][j]=dp[i][k]+dp[k+1][j];
                    }
                }
                string patt=kmp(currS);
                if(patt.length() == dp[i][j].length()) continue;
                
                string newS = to_string(currS.length()/patt.length()) + "[" + dp[i][i+patt.length()-1] +"]"; //get encoded form of repeated pattern;
                if(newS.length() < dp[i][j].length()) 
                    dp[i][j]=newS;
                
            }
        }
        
        return dp[0][n-1];
    }
    
    string kmp(string s) {
        int n=s.length();
        vector<int>kmp(n,0);
        
        int j=0;
        for(int i=1; i<n; i++) {
            j=kmp[i-1];
            while(j>0 && s[j]!=s[i]) j=kmp[j-1];
            if(s[i]==s[j]) j++;
            kmp[i]=j;
        }
        
        if(kmp[n-1] != 0 && kmp[n-1] % (n-kmp[n-1]) == 0)
            return s.substr(0, n-kmp[n-1]);
        return s;
    }
};
