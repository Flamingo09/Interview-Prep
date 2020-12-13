//Not efficient, but diff
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> heap;
        vector<int> result;
        
        int n = nums.size();
        
        if(n==0) return result;
        
        for(int i=0; i<k && i<n; i++)
            heap[nums[i]]++;
        
        result.push_back(heap.rbegin()->first);
        
        for(int i=k; i<n; i++) {
            heap[nums[i-k]]--;
            if(heap[nums[i-k]] == 0) heap.erase(nums[i-k]);
            heap[nums[i]]++;
            result.push_back(heap.rbegin()->first);
        }
        
        return result;
    }
};
