class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n=height.size();
        int water=0;
        
        st.push(0);
        int i=1;
        while(i<n) {
            while(i<n && height[i] <= height[st.top()]) st.push(i++);
            
            if(i==n) break;
            
            while(!st.empty() && height[st.top()] < height[i]) {
                int top=st.top();
                st.pop();
                if(st.empty()) break;
                water += (min(height[st.top()], height[i]) - height[top]) *  (i-st.top()-1);
            }            
            st.push(i);
        }
        
        return water;
    }
};
