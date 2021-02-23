/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> nodeMapping;
    vector<int> result;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root==NULL || target==NULL) return {};
        int x = generateMapping(root, target->val);
        if(x==INT_MAX) return {};
        findNodes(root, nodeMapping[root->val], K);
        return result;
    }
    
    void findNodes(TreeNode* root, int depth, int& k) {
        if(root==NULL) return;
        if(nodeMapping.find(root->val) != nodeMapping.end()) depth = nodeMapping[root->val];
        
        if(depth==k) result.push_back(root->val);
        findNodes(root->left, depth+1, k);
        findNodes(root->right, depth+1, k);
    }
    
    int generateMapping(TreeNode* root, int& target) {
        if(root==NULL) return INT_MAX;
        if(root->val == target) {
            nodeMapping[root->val]=0;
            return 1;
        }
        int left = generateMapping(root->left, target);
        if(left!=INT_MAX) {
            nodeMapping[root->val]=left;
            return left+1;
        }
        int right = generateMapping(root->right, target);
        if(right!=INT_MAX) {
            nodeMapping[root->val]=right;
            return right+1;
        }
        return INT_MAX;
    }
};
