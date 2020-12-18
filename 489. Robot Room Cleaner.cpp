// Very easy explanation : https://leetcode.com/problems/robot-room-cleaner/discuss/153530/DFS-Logical-Thinking

class Solution {
private:
    int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    unordered_set<string> visited;
public:
    void cleanRoom(Robot& robot) {
        visited.insert("0 0");
        clean(robot, 0, 0, 0);
    }
    
    void clean(Robot& r, int i, int j, int direction) {
        r.clean();
        
        for(int k=0; k<4; k++) {
            int ni=dir[(direction+k)%4][0] + i;
            int nj=dir[(direction+k)%4][1] + j;
            string s=to_string(ni) + " " + to_string(nj);
            if(visited.find(s) == visited.end() && r.move()) {
                visited.insert(s);
                clean(r, ni, nj, (direction+k)%4);
            }
            r.turnRight();
        }
        
        r.turnRight();
        r.turnRight();
        r.move();
        r.turnRight();
        r.turnRight();
    }
};
