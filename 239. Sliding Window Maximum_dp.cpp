//Dp approach of sliding window
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1) return nums;
        vector<int> left(n,INT_MIN), right(n,INT_MIN);
        
        
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        
        for(int i=1; i<n; i++) {
            if(i%k==0) left[i]=nums[i];
            else left[i]=max(left[i-1], nums[i]);
        }
        
        for(int i=n-2; i>=0; i--) {
            if(i%k==0) right[i]=nums[i];
            else right[i]=max(right[i+1], nums[i]);
        }
        
        vector<int> result(n-k+1,0);
        
        for(int i=0; i<n-k+1; i++) {
            result[i]=max(left[i+k-1], right[i]);
        }
        
        return result;
    }
};
