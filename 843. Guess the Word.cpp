/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for(int i=0; i<10; i++) {
            int guessIndex = rand() % wordlist.size();
            int value = master.guess(wordlist[guessIndex]);
            if(value==6) break;
            if(value==-1) wordlist.erase(wordlist.begin()+guessIndex);
            else wordlist=generateMatch(wordlist[guessIndex], value, wordlist);
        }
    }
    
    vector<string> generateMatch(string s, int n, vector<string> wordlist) {
        vector<string> result;
        for(int i=0; i<wordlist.size(); i++) {
            int match=0;
            for(int j=0; j<6; j++) {
                if(s[j]==wordlist[i][j]) match++;
            }
            if(match==n) result.push_back(wordlist[i]);
        }
        return result;
    }
};
