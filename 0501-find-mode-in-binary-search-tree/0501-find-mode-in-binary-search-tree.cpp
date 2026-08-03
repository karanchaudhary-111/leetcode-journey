class Solution {
public:
    int currNo   = 0;
    int currFreq = 0;
    int maxFreq  = 0;
    vector<int> ans;

    void inOrder(TreeNode* root){
        if(!root) return ;

        inOrder(root -> left);

        if(currNo != root -> val){
            currNo =  root -> val;
            currFreq = 1;
        }else{
            currFreq++;
        }

        if(currFreq > maxFreq){
            maxFreq = currFreq;
            ans = {};
            ans.push_back(root -> val);

        }else if(currFreq == maxFreq){
            ans.push_back(root -> val);
        }

        inOrder(root -> right);
    }

    vector<int> findMode(TreeNode* root) {
        inOrder(root);

        return ans;
    }
};