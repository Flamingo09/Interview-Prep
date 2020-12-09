class Solution {
private:
    unordered_map<char, int> visited;
    unordered_map<char, vector<char>> graph;
    stack<char> order;
    bool isInvalid=false;
    int n;
public:
    string alienOrder(vector<string>& words) {
        n=words.size();
        if(n==0) return "";
        if(n==1) return words[0];
        
        fillGraph(words);
        
        if(isInvalid) return "";
        
        for(auto it: visited) {
            if(it.second==0){
                bool res = topo(it.first);
                if(!res) return "";
            }
        }
        
        return buildLang();
    }
    
    bool topo(char s) {
        if(visited[s] == 1) return false;
        if(visited[s] == 2) return true;
            
        visited[s]=1;
        for(auto it=graph[s].begin(); it!=graph[s].end(); it++) {
            bool res = topo(*it);
            if(!res) return false;
        }
        
        visited[s]=2;
        order.push(s);
        return true;
    }
    
    void fillGraph(vector<string>& words) {
        for(int i=0; i<n-1; i++) {
            int j=0;
            if (words[i].length() > words[i+1].length() && words[i].rfind(words[i+1], 0) == 0) {
                isInvalid=true;
                return;
            }
            for(;j<min(words[i].length(), words[i+1].length()); j++) {
                if(words[i][j] != words[i+1][j]) {
                    graph[words[i][j]].push_back(words[i+1][j]);
                    break;
                }
                visited[words[i][j]] = false;
                visited[words[i+1][j]] = false;
            }
            while(j<max(words[i].length(), words[i+1].length())) {
                if(j<words[i].length())
                    visited[words[i][j]] = false;
                if(j<words[i+1].length())
                    visited[words[i+1][j]] = false;
                j++;
            }
        }
        return;
    }
            
    string buildLang() {
        string result="";
        while(!order.empty()) {
            result += order.top();
            order.pop();
        }
        return result;
    }                  
                            
};
