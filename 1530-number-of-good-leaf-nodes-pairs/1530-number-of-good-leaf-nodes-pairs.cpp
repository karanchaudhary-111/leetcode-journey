/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> solve(TreeNode* root, int &count, int &distance){
        if(!root) return {};

        if(root -> left == NULL && root -> right == NULL){
            return {1};
        }

        vector<int> l = solve(root -> left, count, distance);
        vector<int> r = solve(root -> right, count, distance);

        for(auto & leftLeaf : l){
            for(auto& rightLeaf : r){
                if(leftLeaf + rightLeaf <= distance){
                    count++;
                }
            }
        }
        vector<int> currD;
        for(int& ld : l){
            if((ld+1 <= distance)){
                currD.push_back(ld+1);
            }
        }

        for(int& rd : r){
            if(rd != 0 && rd+1 <= distance) currD.push_back(rd+1);
        }
        
        return currD;
    }

    int countPairs(TreeNode* root, int distance) {
        int resultCount = 0;

        solve(root, resultCount, distance);

        return resultCount;
        
    }
};