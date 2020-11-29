class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        
        vector<int>result;
        
        int i=0;
        for(i=0; i<=n-k; i++) {
            while(!dq.empty() && nums[i] < nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        
        
        for(int j=0; j<k; j++) {
            result.push_back(nums[dq.front()]);
            dq.pop_front();
            if(i<n) {
                while(!dq.empty() && nums[i] < nums[dq.back()])
                    dq.pop_back();
                dq.push_back(i++);
            }
        }
        return result;
    }
};
