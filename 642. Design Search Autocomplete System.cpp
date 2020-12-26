class AutocompleteSystem {
private:
    struct Trie {
        vector<Trie*> children;
        map<string, int> matches;
        Trie() {
            this->children.assign(27, NULL);
            this->matches={};
        }
        
        static Trie* insert(Trie* node, string s, int t=0, bool isLeaf=true) {
            int i=0, index;
            while(i<s.length()) {
                index = s[i]==' ' ? 26 : s[i]-'a';
                if(node->children[index] == NULL) {
                    node->children[index] = new Trie();
                }
                node = node->children[index];
                if(isLeaf) node->matches[s]+=t;
                i++;
            }
            return node;
        }
    };
    
    static bool comp(const pair<string, int>& p1, const pair<string, int>& p2) {
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    }
    
    Trie* root, *curr;
    string search="";
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Trie();
        for(int i=0; i<sentences.size(); i++) {
            Trie* node = Trie::insert(root, sentences[i], times[i]);
        }
        curr=root;
    }
    
    vector<string> input(char c) {
        if(c=='#') {
            Trie::insert(root, search, 1);
            curr=root;
            search="";
            return {};
        }
        search += string(1,c);
        curr=Trie::insert(curr, string(1,c), 0, false);
        
        if(curr->matches.size() == 0) return {};
        
        vector<pair<string, int>> result;
        for(auto it : curr->matches) {
            result.push_back({it.first, it.second});
        }
        
        partial_sort(result.begin(), result.begin()+min((int)result.size(), 3), result.end(), comp);

        vector<string> res;
        for(int i=0; i<min((int)result.size(), 3); i++) res.push_back(result[i].first);
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
