class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s = std::accumulate(sentence.begin(), sentence.end(), std::string(), 
    [](const std::string& a, const std::string& b) -> std::string { 
        return a + (a.length() > 0 ? " " : "") + b; 
    } ) + ' ';
        int n=s.length();
        int start=0;
        for(int i=0; i<rows; i++) {
            start += cols;
            if(s[(start%n)] == ' ') start++;
            else {
                while(start>=0 && s[(start-1)%n] != ' ') start--;
            }
        }
        return start/n;
    }
};
