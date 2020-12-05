class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> numerators;
        vector<double> result;
        unordered_set<string> seen;
        
        for(int i=0; i<equations.size(); i++) {
            numerators[equations[i][0]][equations[i][1]]=values[i];
            numerators[equations[i][1]][equations[i][0]]=1/values[i];
        }
        
        for(int i=0; i<queries.size(); i++) {
            
            double val=-1;
            bool done = false;
            if(numerators.find(queries[i][0]) == numerators.end()) {
                done=true;
            } 
            if(!done) {
                queue<pair<string, double>> nums;
                nums.push(make_pair(queries[i][0], (double)1));

                while(!nums.empty()) {
                    pair<string, double> p = nums.front();
                    seen.insert(p.first);
                    nums.pop();
                    unordered_map<string, double> second = numerators[p.first];
                    
                    for(pair<string, double> p2 : second) {
                        double curr = p.second*p2.second;
                        if(p2.first == queries[i][1]) {
                            if(val == -1) {
                                val = curr;
                            } else if(val != curr) {
                                val=-1;
                                done=true;
                                break;
                            }
                        } else {
                            if(seen.count(p2.first) <= 0)
                                nums.push(make_pair(p2.first, curr));
                        }    
                    }
                    if(done) 
                        break;
                }
                seen.clear();
            }
            result.push_back(val);
        }
        
        return result;
    }
};
