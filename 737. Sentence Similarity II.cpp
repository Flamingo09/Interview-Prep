class Solution {
private:
    struct Subset{
        string parent;
        int rank;
    };
    unordered_map<string ,Subset> parents;
    
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        int n=words1.size();
        if(n!=words2.size()) return false;
        
        createUnions(pairs);
        
        for(int i=0; i<n;i++) {
            if(words1[i] != words2[i]) {
                if(find(words1[i]) != find(words2[i])) return false;
            }
        }
                   
        return true;
    }
    
    void createUnions(vector<vector<string>>& pairs) {
        for(vector<string> pair : pairs) {
            string parentFirst = find(pair[0]);
            string parentSecond = find(pair[1]);
            if(parentFirst != parentSecond) {
                if(parents[parentFirst].rank < parents[parentSecond].rank) {
                    parents[parentFirst].parent=parentSecond;
                } else if(parents[parentFirst].rank > parents[parentSecond].rank) {
                    parents[parentSecond].parent=parentFirst;
                } else {
                    parents[parentFirst].parent=parentSecond;
                    parents[parentSecond].rank++;
                }
            }
        }
    }
    
    string find(string s) {
        if(!parents.count(s)) {
            parents[s].parent = s;
            parents[s].rank=1;
            return s;
        }
        if(parents[s].parent != s) 
            parents[s].parent = find(parents[s].parent);
        return parents[s].parent;
    }
};
