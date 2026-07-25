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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        
        int n = desc.size();

        unordered_map<int, TreeNode*> mp;
        unordered_set<int> temp;

        for(int i = 0; i < n; i++){
            if(mp.find(desc[i][0]) == mp.end()){
                TreeNode* root = new TreeNode(desc[i][0]);
                mp[desc[i][0]] = root;
            }

            if(mp.find(desc[i][1]) == mp.end()){
                TreeNode*child = new TreeNode(desc[i][1]);
                mp[desc[i][1]] = child;
            }

            if(desc[i][2] == 1){
                mp[desc[i][0]] -> left = mp[desc[i][1]];
            }else{
                mp[desc[i][0]] -> right = mp[desc[i][1]];
            }
            temp.insert(desc[i][1]);
        }

        for(int i = 0; i < n; i++){
            if(temp.find(desc[i][0]) == temp.end()){
                TreeNode* result = mp[desc[i][0]];
                return result;
            }
        }
        return NULL;
    }
};