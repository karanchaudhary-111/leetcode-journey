class Solution {
public:

    int storeLVL[100001];
    int height[100001];
    int levelMaxHt[100001];
    int levelSecMaxHt[100001];

    int findHeight(TreeNode* root, int level){
        if(!root) return 0;

        storeLVL[root -> val] = level;
        height[root -> val] = max(findHeight(root -> left, level+1), findHeight(root -> right, level+1)) + 1;

        if(levelMaxHt[level] <  height[root -> val]){

            levelSecMaxHt[level] = levelMaxHt[level];
            levelMaxHt[level] =  height[root -> val];

        }else if(levelSecMaxHt[level] <  height[root -> val]){

            levelSecMaxHt[level] =  height[root -> val];

        }

        return height[root-> val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        vector<int> ans;
        findHeight(root, 0);

        for(int &node: queries){
            int L = storeLVL[node];
            //int H = height[node] == levelMaxHt[L] ? levelSecMaxHt[L] : levelMaxHt[L];

            int temp = L + (height[node] == levelMaxHt[L] ? levelSecMaxHt[L] : levelMaxHt[L]) - 1;
            ans.push_back(temp);
        }

        return ans;
    }
};