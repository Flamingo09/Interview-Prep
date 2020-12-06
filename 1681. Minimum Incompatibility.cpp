class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        n = nums.size(), m = n / k;
        this->k = k;
        if(m == 1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets(k);
        backtrack(nums, 0, subsets, 0);
        return ans == INT_MAX ? -1 : ans;
    }
private:
    int ans = INT_MAX, n, m, k;
    void backtrack(const vector<int>& nums, int idx, vector<vector<int>>& subsets, int res){
        if(idx == n){
            ans = min(ans, res);
            return;
        }
        if(res >= ans){
            return;
        }
        for(int i = 0; i < subsets.size(); i++){
            if(subsets[i].size() == m || (!subsets[i].empty() && subsets[i].back() == nums[idx])){
                continue;
            }
            subsets[i].push_back(nums[idx]);
            int cur = 0;
            if(subsets[i].size() > 1){
                int t = subsets[i].size();
                cur = subsets[i][t-1] - subsets[i][t-2];
            }
            backtrack(nums, idx + 1, subsets, res + cur);
            subsets[i].pop_back();
        }
    }
};
