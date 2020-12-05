//Awesome explanation here : https://www.youtube.com/watch?v=FhEbfSRuNNA

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double, int>> workers;

        for(int i=0; i<n; i++) {
            workers.push_back({(double)wage[i]/quality[i], quality[i]});
        }
        
        sort(workers.begin(), workers.end());
        
        double ans=DBL_MAX;
        int sum=0, maxQuality;
        
        priority_queue<int> Q;
        
        for(int i=0; i<k; i++) {
            sum+=workers[i].second;
            Q.push(workers[i].second);
        }
        
        ans=sum*workers[k-1].first;
        
        for(int i=k; i<n; i++) {
            maxQuality = Q.top();
            if(workers[i].second < maxQuality) {
                Q.pop();
                Q.push(workers[i].second);
                sum += workers[i].second - maxQuality;
                ans = min(ans, sum*workers[i].first);
            }
        }
        
        return ans;
    }
};
