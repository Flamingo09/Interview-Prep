// use this -> converging the walls : https://leetcode.com/problems/trapping-rain-water-ii/discuss/89496/Concise-C%2B%2B-method-with-explanation
// and this -> https://leetcode.com/problems/trapping-rain-water-ii/discuss/89461/Java-solution-using-PriorityQueue
class Solution {
private:
    struct pillar {
        int x;
        int y;
        int height;

        pillar(int x, int y, int height) : x(x), y(y), height(height) {}
    };
    struct comp {
        bool operator()(const pillar& p1, const pillar& p2) {
            return p1.height > p2.height;
        }
    };
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        if(n==0) return 0;
        int m=heightMap[0].size();
        
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        
        priority_queue<pillar, vector<pillar>, comp> pq;
        
        for(int i=0; i<n; i++) {
            pq.push(pillar(i, 0, heightMap[i][0]));
            pq.push(pillar(i, m-1, heightMap[i][m-1]));
            visited[i][0]=true;
            visited[i][m-1]=true;
        }
        
        for(int i=1; i<m-1; i++) {
            pq.push(pillar(0, i, heightMap[0][i]));
            pq.push(pillar(n-1, i, heightMap[n-1][i]));
            visited[0][i]=true;
            visited[n-1][i]=true;
        }
        
        int water=0;
        while(!pq.empty()) {
            pillar p = pq.top(); pq.pop();
            for(int i=0; i<4; i++) {
                int r=p.x+dir[i][0];
                int c=p.y+dir[i][1];
                
                if(r>=0 && r<n && c>=0 && c<m && visited[r][c]==false) {
                    water+=max(0, p.height-heightMap[r][c]);
                    pq.push(pillar(r,c, max(p.height, heightMap[r][c])));
                    visited[r][c]=true;
                }
            }
        }
        
        return water;
    }
};
