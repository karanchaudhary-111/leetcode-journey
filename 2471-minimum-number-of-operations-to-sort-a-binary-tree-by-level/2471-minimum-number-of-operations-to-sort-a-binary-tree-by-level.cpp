class Solution {
public:

    int countMinToSort(vector<int>& vec){

        int n = vec.size();
        int swapCount = 0;

        vector<int> sortedVec(vec);

        sort(begin(sortedVec), end(sortedVec));

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[vec[i]] = i;
        }

        for(int i = 0; i < n; i++){
            if(vec[i] != sortedVec[i]){
                int currIdx = mp[sortedVec[i]];
                mp[vec[i]] = currIdx;

                swap(vec[currIdx], vec[i]);
                swapCount++;
            }
        }

        return swapCount;
    }

    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int result = 0;

        while(!q.empty()){
            int n = q.size();
            vector<int> levelNode;

            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                levelNode.push_back(curr -> val);

                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
            result += countMinToSort(levelNode);
        }
        return result;
    }
};